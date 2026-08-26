/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "secutil.h"
#include "secmod.h"
#include "cert.h"
#include "secoid.h"
#include "nss.h"
#include "pk11pub.h"
#include "pk11pqg.h"

/* NSPR 2.0 header files */
#include "prinit.h"
#include "prprf.h"
#include "prsystem.h"
#include "prmem.h"
/* Portable layer header files */
#include "plstr.h"

SECOidData *
getCurveFromString(char *curve_name)
{
    SECOidTag tag = SEC_OID_SECG_EC_SECP256R1;

    if (PORT_Strcasecmp(curve_name, "NISTP256") == 0) {
    } else if (PORT_Strcasecmp(curve_name, "NISTP384") == 0) {
        tag = SEC_OID_SECG_EC_SECP384R1;
    } else if (PORT_Strcasecmp(curve_name, "NISTP521") == 0) {
        tag = SEC_OID_SECG_EC_SECP521R1;
    } else if (PORT_Strcasecmp(curve_name, "Curve25519") == 0) {
        tag = SEC_OID_CURVE25519;
    }
    return SECOID_FindOIDByTag(tag);
}

void
dumpItem(const char *label, const SECItem *item)
{
    int i;
    printf("%s = [%d bytes] {", label, item->len);
    for (i = 0; i < item->len; i++) {
        if ((i & 0xf) == 0)
            printf("\n    ");
        else
            printf(", ");
        printf("%02x", item->data[i]);
    }
    printf("};\n");
}

/*
 * An imported private key should have a CKA_ID, and, because we import it as
 * a token key, the token should have a matching permanent public key.
 */
PRBool
verifyImportedKey(char *progName, PK11SlotInfo *slot,
                  SECKEYPrivateKey *privKey)
{
    SECStatus rv;
    SECItem privID = { 0 };
    SECItem pubID = { 0 };
    SECItem token = { 0 };
    PK11GenericObject *objs = NULL;
    PK11GenericObject *obj = NULL;
    PRBool keyFound = 0;

    rv = PK11_ReadRawAttribute(PK11_TypePrivKey, privKey, CKA_ID, &privID);
    if (rv != SECSuccess) {
        SECU_PrintError(progName, "Couldn't read CKA_ID from priv key");
        goto cleanup;
    }
    dumpItem("privKey CKA_ID", &privID);
    objs = PK11_FindGenericObjects(slot, CKO_PUBLIC_KEY);
    for (obj = objs; obj; obj = PK11_GetNextGenericObject(obj)) {
        rv = PK11_ReadRawAttribute(PK11_TypeGeneric, obj, CKA_ID, &pubID);
        if (rv != SECSuccess) {
            SECU_PrintError(progName,
                            "Couldn't read CKA_ID from object, checking next key");
            continue;
        }
        dumpItem("pubKey CKA_ID", &pubID);
        if (!SECITEM_ItemsAreEqual(&privID, &pubID)) {
            fprintf(stderr,
                    "CKA_ID does not match priv key, checking next key\n");
            SECITEM_FreeItem(&pubID, PR_FALSE);
            continue;
        }
        SECITEM_FreeItem(&pubID, PR_FALSE);
        rv = PK11_ReadRawAttribute(PK11_TypeGeneric, obj, CKA_TOKEN, &token);
        if (rv == SECSuccess) {
            if (token.len == 1) {
                keyFound = token.data[0];
            }
            SECITEM_FreeItem(&token, PR_FALSE);
        }
        if (keyFound) {
            printf("matching public key found\n");
            break;
        }
        printf("Matching key was not a token key, checking next key\n");
    }

cleanup:
    if (objs) {
        PK11_DestroyGenericObjects(objs);
    }
    SECITEM_FreeItem(&privID, PR_FALSE);
    SECITEM_FreeItem(&pubID, PR_FALSE);
    SECITEM_FreeItem(&token, PR_FALSE);
    return keyFound;
}

SECStatus
handleEncryptedPrivateImportTest(char *progName, PK11SlotInfo *slot,
                                 char *testname, CK_MECHANISM_TYPE genMech,
                                 PRBool noPub, void *params, void *pwArgs)
{
    SECStatus rv = SECSuccess;
    SECItem pubValue = { 0 };
    SECItem pbePwItem = { 0 };
    SECItem nickname = { 0 };
    SECKEYPublicKey *pubKey = NULL;
    SECKEYPrivateKey *privKey = NULL;
    SECKEYEncryptedPrivateKeyInfo *epki = NULL;
    PRBool keyFound = 0;
    KeyType keyType;

    fprintf(stderr, "Testing %s PrivateKeyImport ***********************\n",
            testname);

    /* generate a temp key */
    privKey = PK11_GenerateKeyPair(slot, genMech, params, &pubKey,
                                   PR_FALSE, PR_TRUE, pwArgs);
    if (privKey == NULL) {
        SECU_PrintError(progName, "PK11_GenerateKeyPair Failed");
        goto cleanup;
    }

    /* wrap the temp key */
    pbePwItem.data = (unsigned char *)"pw";
    pbePwItem.len = 2;
    epki = PK11_ExportEncryptedPrivKeyInfo(slot, SEC_OID_AES_256_CBC,
                                           &pbePwItem, privKey, 1, NULL);
    if (epki == NULL) {
        SECU_PrintError(progName, "PK11_ExportEncryptedPrivKeyInfo Failed");
        goto cleanup;
    }

    /* Save the public value, which we will need on import */
    keyType = pubKey->keyType;
    if (!noPub) {
        const SECItem *idValue = PK11_GetPublicValueFromPublicKey(pubKey);
        if (!idValue) {
            SECU_PrintError(progName, "Unable to get public value from key");
            goto cleanup;
        }
        /* copy the value so it doesn't disappear when we free the key */
        SECITEM_CopyItem(NULL, &pubValue, idValue);
        if (pubValue.data == NULL) {
            SECU_PrintError(progName, "Unable to allocate memory");
            goto cleanup;
        }
        dumpItem("pubValue", &pubValue);
    }

    /* when Asymetric keys represent session keys, those session keys are
     * destroyed when we destroy the Asymetric key representations */
    SECKEY_DestroyPublicKey(pubKey);
    pubKey = NULL;
    SECKEY_DestroyPrivateKey(privKey);
    privKey = NULL;

    /* unwrap the temp key as a perm */
    nickname.data = (unsigned char *)"testKey";
    nickname.len = sizeof("testKey");
    rv = PK11_ImportEncryptedPrivateKeyInfoAndReturnKey(
        slot, epki, &pbePwItem, &nickname, noPub ? NULL : &pubValue,
        PR_TRUE, PR_TRUE, keyType, 0, &privKey, NULL);
    if (rv != SECSuccess) {
        SECU_PrintError(progName, "PK11_ImportEncryptedPrivateKeyInfo Failed");
        goto cleanup;
    }

    keyFound = verifyImportedKey(progName, slot, privKey);

cleanup:
    SECITEM_FreeItem(&pubValue, PR_FALSE);
    if (epki && epki->arena) {
        PORT_FreeArena(epki->arena, PR_TRUE);
    }
    SECKEY_DestroyPublicKey(pubKey);
    SECKEY_DestroyPrivateKey(privKey);
    fprintf(stderr, "%s PrivateKeyImport %s ***********************\n",
            testname, keyFound ? "PASSED" : "FAILED");
    return keyFound ? SECSuccess : SECFailure;
}

/*
 * Same as above, but going through the unencrypted PrivateKeyInfo interface.
 * That interface is really only meant for testing, but it should give the
 * same semantics as the encrypted one.
 *
 * PK11_ExportPrivKeyInfo doesn't handle every key type PK11_ExportEncrypted-
 * PrivKeyInfo does. Report the ones it can't export as skipped rather than
 * failed, so that this test picks them up automatically if that changes.
 */
SECStatus
handlePrivateImportTest(char *progName, PK11SlotInfo *slot,
                        char *testname, CK_MECHANISM_TYPE genMech,
                        PRBool noPub, void *params, void *pwArgs)
{
    SECStatus rv = SECSuccess;
    SECItem pubValue = { 0 };
    SECItem nickname = { 0 };
    SECKEYPublicKey *pubKey = NULL;
    SECKEYPrivateKey *privKey = NULL;
    SECKEYPrivateKeyInfo *pki = NULL;
    PRBool keyFound = 0;
    PRBool skipped = 0;

    fprintf(stderr,
            "Testing %s unencrypted PrivateKeyImport *******************\n",
            testname);

    /* generate a temp key. Unlike the encrypted export, which wraps the key
     * on the token, an unencrypted export has to read the private attributes
     * out, so the key can't be sensitive. */
    privKey = PK11_GenerateKeyPair(slot, genMech, params, &pubKey,
                                   PR_FALSE, PR_FALSE, pwArgs);
    if (privKey == NULL) {
        SECU_PrintError(progName, "PK11_GenerateKeyPair Failed");
        goto cleanup;
    }

    pki = PK11_ExportPrivKeyInfo(privKey, pwArgs);
    if (pki == NULL) {
        if (PORT_GetError() == PR_NOT_IMPLEMENTED_ERROR) {
            skipped = 1;
        } else {
            SECU_PrintError(progName, "PK11_ExportPrivKeyInfo Failed");
        }
        goto cleanup;
    }

    /* Save the public value, which we will need on import */
    if (!noPub) {
        const SECItem *idValue = PK11_GetPublicValueFromPublicKey(pubKey);
        if (!idValue) {
            SECU_PrintError(progName, "Unable to get public value from key");
            goto cleanup;
        }
        /* copy the value so it doesn't disappear when we free the key */
        SECITEM_CopyItem(NULL, &pubValue, idValue);
        if (pubValue.data == NULL) {
            SECU_PrintError(progName, "Unable to allocate memory");
            goto cleanup;
        }
        dumpItem("pubValue", &pubValue);
    }

    /* when Asymetric keys represent session keys, those session keys are
     * destroyed when we destroy the Asymetric key representations */
    SECKEY_DestroyPublicKey(pubKey);
    pubKey = NULL;
    SECKEY_DestroyPrivateKey(privKey);
    privKey = NULL;

    /* import the temp key as a perm */
    nickname.data = (unsigned char *)"testKey";
    nickname.len = sizeof("testKey");
    rv = PK11_ImportPrivateKeyInfoAndReturnKey(
        slot, pki, &nickname, noPub ? NULL : &pubValue,
        PR_TRUE, PR_TRUE, KU_ALL, &privKey, NULL);
    if (rv != SECSuccess) {
        SECU_PrintError(progName, "PK11_ImportPrivateKeyInfo Failed");
        goto cleanup;
    }

    keyFound = verifyImportedKey(progName, slot, privKey);

cleanup:
    SECITEM_FreeItem(&pubValue, PR_FALSE);
    if (pki) {
        SECKEY_DestroyPrivateKeyInfo(pki, PR_TRUE);
    }
    SECKEY_DestroyPublicKey(pubKey);
    SECKEY_DestroyPrivateKey(privKey);
    fprintf(stderr,
            "%s unencrypted PrivateKeyImport %s *******************\n",
            testname, skipped ? "SKIPPED" : (keyFound ? "PASSED" : "FAILED"));
    return (skipped || keyFound) ? SECSuccess : SECFailure;
}

SECStatus
handleImportTests(char *progName, PK11SlotInfo *slot, char *testname,
                  CK_MECHANISM_TYPE genMech, PRBool noPub, void *params,
                  void *pwArgs)
{
    SECStatus encrypted = handleEncryptedPrivateImportTest(
        progName, slot, testname, genMech, noPub, params, pwArgs);
    SECStatus plain = handlePrivateImportTest(
        progName, slot, testname, genMech, noPub, params, pwArgs);

    return ((encrypted == SECSuccess) && (plain == SECSuccess)) ? SECSuccess
                                                                : SECFailure;
}

static const char *const usageInfo[] = {
    "pk11import - test PK11_PrivateKeyImport()",
    "Options:",
    " -d certdir            directory containing cert database",
    " -k keysize            size of the rsa, dh, and dsa key to test (default 1024)",
    " -C ecc_curve          ecc curve (default )",
    " -f pwFile             file to fetch the password from",
    " -p pwString           password",
    " -n                    force pub key to be rebuilt",
    " -r                    skip rsa test",
    " -D                    skip dsa test",
    " -h                    skip dh test",
    " -e                    skip ec test",
    " -K                    skip ml-kem test",
    " -m                    skip ml-dsa test",
};
static int nUsageInfo = sizeof(usageInfo) / sizeof(char *);

static void
Usage(char *progName, FILE *outFile)
{
    int i;
    fprintf(outFile, "Usage:  %s [ commands ] options\n", progName);
    for (i = 0; i < nUsageInfo; i++)
        fprintf(outFile, "%s\n", usageInfo[i]);
    exit(-1);
}

enum {
    opt_CertDir,
    opt_KeySize,
    opt_ECCurve,
    opt_PWFile,
    opt_PWString,
    opt_NoPub,
    opt_NoRSA,
    opt_NoDSA,
    opt_NoDH,
    opt_NoEC,
    opt_NoMLKEM,
    opt_NoMLDSA,
};

static secuCommandFlag options[] = {
    { /* opt_CertDir          */ 'd', PR_TRUE, 0, PR_FALSE },
    { /* opt_KeySize          */ 'k', PR_TRUE, 0, PR_FALSE },
    { /* opt_ECCurve          */ 'C', PR_TRUE, 0, PR_FALSE },
    { /* opt_PWFile           */ 'f', PR_TRUE, 0, PR_FALSE },
    { /* opt_PWString         */ 'p', PR_TRUE, 0, PR_FALSE },
    { /* opt_NoPub            */ 'n', PR_FALSE, 0, PR_FALSE },
    { /* opt_NoRSA            */ 'r', PR_FALSE, 0, PR_FALSE },
    { /* opt_NoDSA            */ 'D', PR_FALSE, 0, PR_FALSE },
    { /* opt_NoDH             */ 'h', PR_FALSE, 0, PR_FALSE },
    { /* opt_NoEC             */ 'e', PR_FALSE, 0, PR_FALSE },
    { /* opt_NoMLKEM          */ 'K', PR_FALSE, 0, PR_FALSE },
    { /* opt_NoMLDSA          */ 'm', PR_FALSE, 0, PR_FALSE },
};

int
main(int argc, char **argv)
{
    char *progName;
    SECStatus rv;
    secuCommand args;
    PK11SlotInfo *slot = NULL;
    PRBool failed = PR_FALSE;
    secuPWData pwArgs = { PW_NONE, 0 };
    PRBool doRSA = PR_TRUE;
    PRBool doDSA = PR_TRUE;
    PRBool doDH = PR_FALSE; /* NSS currently can't export wrapped DH keys */
    PRBool doEC = PR_TRUE;
    PRBool doMLKEM = PR_TRUE;
    PRBool doMLDSA = PR_TRUE;
    PRBool noPub = PR_FALSE;
    PQGParams *pqgParams = NULL;
    int keySize;

    args.numCommands = 0;
    args.numOptions = sizeof(options) / sizeof(secuCommandFlag);
    args.commands = NULL;
    args.options = options;

#ifdef XP_PC
    progName = strrchr(argv[0], '\\');
#else
    progName = strrchr(argv[0], '/');
#endif
    progName = progName ? progName + 1 : argv[0];

    rv = SECU_ParseCommandLine(argc, argv, progName, &args);
    if (SECSuccess != rv) {
        Usage(progName, stderr);
    }

    /*  Set the certdb directory (default is ~/.netscape) */
    rv = NSS_InitReadWrite(SECU_ConfigDirectory(args.options[opt_CertDir].arg));
    if (rv != SECSuccess) {
        SECU_PrintPRandOSError(progName);
        return 255;
    }
    PK11_SetPasswordFunc(SECU_GetModulePassword);

    /* below here, goto cleanup */
    SECU_RegisterDynamicOids();

    /* handle the arguments */
    if (args.options[opt_PWFile].arg) {
        pwArgs.source = PW_FROMFILE;
        pwArgs.data = args.options[opt_PWFile].arg;
    }
    if (args.options[opt_PWString].arg) {
        pwArgs.source = PW_PLAINTEXT;
        pwArgs.data = args.options[opt_PWString].arg;
    }
    if (args.options[opt_NoPub].activated) {
        noPub = PR_TRUE;
        doDSA = PR_FALSE; /* dsa can't handle no pub */
    }
    if (args.options[opt_NoRSA].activated) {
        doRSA = PR_FALSE;
    }
    if (args.options[opt_NoDSA].activated) {
        doDSA = PR_FALSE;
    }
    if (args.options[opt_NoDH].activated) {
        doDH = PR_FALSE;
    }
    if (args.options[opt_NoEC].activated) {
        doEC = PR_FALSE;
    }
    if (args.options[opt_NoMLKEM].activated) {
        doMLKEM = PR_FALSE;
    }
    if (args.options[opt_NoMLDSA].activated) {
        doMLDSA = PR_FALSE;
    }

    slot = PK11_GetInternalKeySlot();
    if (slot == NULL) {
        SECU_PrintError(progName, "Couldn't find the internal key slot\n");
        return 255;
    }
    rv = PK11_Authenticate(slot, PR_TRUE, &pwArgs);
    if (rv != SECSuccess) {
        SECU_PrintError(progName, "Failed to log into slot");
        PK11_FreeSlot(slot);
        return 255;
    }

    keySize = 1024;
    if (args.options[opt_KeySize].activated &&
        args.options[opt_KeySize].arg) {
        keySize = atoi(args.options[opt_KeySize].arg);
    }

    if (doDSA || doDH) {
        PQGVerify *pqgVfy;
        rv = PK11_PQG_ParamGenV2(keySize, 0, keySize / 16, &pqgParams, &pqgVfy);
        if (rv == SECSuccess) {
            PK11_PQG_DestroyVerify(pqgVfy);
        } else {
            SECU_PrintError(progName,
                            "PK11_PQG_ParamGenV2 failed, can't test DH or DSA");
            doDSA = doDH = PR_FALSE;
            failed = PR_TRUE;
        }
    }

    if (doRSA) {
        PK11RSAGenParams rsaParams;
        rsaParams.keySizeInBits = keySize;
        rsaParams.pe = 0x010001;
        rv = handleImportTests(progName, slot, "RSA",
                               CKM_RSA_PKCS_KEY_PAIR_GEN,
                               noPub, &rsaParams, &pwArgs);
        if (rv != SECSuccess) {
            fprintf(stderr, "RSA Import Failed!\n");
            failed = PR_TRUE;
        }
    }
    if (doDSA) {
        rv = handleImportTests(progName, slot, "DSA",
                               CKM_DSA_KEY_PAIR_GEN,
                               noPub, pqgParams, &pwArgs);
        if (rv != SECSuccess) {
            fprintf(stderr, "DSA Import Failed!\n");
            failed = PR_TRUE;
        }
    }
    if (doDH) {
        SECKEYDHParams dhParams;
        dhParams.prime = pqgParams->prime;
        dhParams.base = pqgParams->base;
        rv = handleImportTests(progName, slot, "DH",
                               CKM_DH_PKCS_KEY_PAIR_GEN,
                               noPub, &dhParams, &pwArgs);
        if (rv != SECSuccess) {
            fprintf(stderr, "DH Import Failed!\n");
            failed = PR_TRUE;
        }
    }
    if (doEC) {
        SECKEYECParams ecParams;
        SECOidData *curve = SECOID_FindOIDByTag(SEC_OID_SECG_EC_SECP256R1);
        if (args.options[opt_ECCurve].activated &&
            args.options[opt_ECCurve].arg) {
            curve = getCurveFromString(args.options[opt_ECCurve].arg);
        }
        ecParams.data = PORT_Alloc(curve->oid.len + 2);
        if (ecParams.data == NULL) {
            rv = SECFailure;
            goto ec_failed;
        }
        ecParams.data[0] = SEC_ASN1_OBJECT_ID;
        ecParams.data[1] = (unsigned char)curve->oid.len;
        PORT_Memcpy(&ecParams.data[2], curve->oid.data, curve->oid.len);
        ecParams.len = curve->oid.len + 2;
        rv = handleImportTests(progName, slot, "ECC",
                               CKM_EC_KEY_PAIR_GEN,
                               noPub, &ecParams, &pwArgs);
        PORT_Free(ecParams.data);
    ec_failed:
        if (rv != SECSuccess) {
            fprintf(stderr, "ECC Import Failed!\n");
            failed = PR_TRUE;
        }
    }

    if (doMLKEM) {
        CK_ML_KEM_PARAMETER_SET_TYPE paramSet = CKP_ML_KEM_768;

        rv = handleImportTests(progName, slot, "MLKEM",
                               CKM_ML_KEM_KEY_PAIR_GEN,
                               noPub, &paramSet, &pwArgs);
        if (rv != SECSuccess) {
            fprintf(stderr, "MLKEM Import Failed!\n");
            failed = PR_TRUE;
        }
    }

    if (doMLDSA) {
        CK_ML_DSA_PARAMETER_SET_TYPE paramSet = CKP_ML_DSA_44;
        rv = handleImportTests(progName, slot, "ML-DSA",
                               CKM_ML_DSA_KEY_PAIR_GEN,
                               noPub, &paramSet, &pwArgs);
        if (rv != SECSuccess) {
            fprintf(stderr, "ML-DSA Import Failed!\n");
            failed = PR_TRUE;
        }
    }

    if (pqgParams) {
        PK11_PQG_DestroyParams(pqgParams);
    }

    if (slot) {
        PK11_FreeSlot(slot);
    }

    rv = NSS_Shutdown();
    if (rv != SECSuccess) {
        fprintf(stderr, "Shutdown failed\n");
        SECU_PrintPRandOSError(progName);
        return 255;
    }

    return failed ? 1 : 0;
}
