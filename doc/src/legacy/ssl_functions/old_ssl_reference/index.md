(mozilla-projects-nss-ssl-functions-old-ssl-reference)=

# OLD SSL Reference

::::{container}

```{rubric} OLD SSL Reference
:name: OLD_SSL_Reference
```

:::{note}

- We are migrating this SSL Reference into the format described in the [MDN Style
  Guide](https://developer.mozilla.org/en-US/docs/Project:MDC_style_guide). If you are
  inclined to help with this migration, your help would be very much appreciated.
- Upgraded documentation may be found in the {ref}`mozilla-projects-nss-reference`
:::
::::

(ssl-reference)=

## SSL Reference

:::{container}
*Newsgroup:*[mozilla.dev.tech.crypto](news://news.mozilla.org/mozilla.dev.tech.crypto)\*
Writer: Sean Cotter
Manager: Wan-Teh Chang\*

```{rubric} Chapter 1 Overview of an SSL Application
```

SSL and related APIs allow compliant applications to configure sockets for authenticated,
tamper-proof, and encrypted communications. This chapter introduces some of the basic SSL
functions. Chapter 2, "Getting Started With SSL" illustrates their use in sample client and
server applications.

- [Initialization](sslintro.html#1027662)

  - [Initializing Caches](sslintro.html#1039943)

- [Configuration](sslintro.html#1027742) \` \<sslintro.html#1027816>\`\_\_

- [Communication](sslintro.html#1027816) \` \<sslintro.html#1027820>\`\_\_

- [Functions Used by Callbacks](sslintro.html#1027820) \` \<sslintro.html#1030535>\`\_\_

- [Cleanup](sslintro.html#1030535)

```{rubric} Chapter 2 Getting Started With SSL
```

This chapter describes how to set up your environment, including certificate and key
databases, to run the NSS sample code. The sample code and makefiles are available via LXR in
the SSLSamples directory.

- [SSL, PKCS #11, and the Default Security Databases](gtstd.html#1011970)
  \` \<gtstd.html#1011987>\`\_\_

- [Setting Up the Certificate and Key Databases](gtstd.html#1011987)

  - [Setting Up the CA DB and Certificate](gtstd.html#1012301) \` \<gtstd.html#1012351>\`\_\_
  - [Setting Up the Server DB and Certificate](gtstd.html#1012351) \` \<gtstd.html#1012067>\`\_\_
  - [Setting Up the Client DB and Certificate](gtstd.html#1012067) \` \<gtstd.html#1012108>\`\_\_
  - [Verifying the Server and Client Certificates](gtstd.html#1012108)

- [Building NSS Programs](gtstd.html#1013274)

```{rubric} Chapter 3 Selected SSL Types and Structures
```

This chapter describes some of the most important types and structures used with the functions
described in the rest of this document, and how to manage the memory used for them. Additional
types are described with the functions that use them or in the header files.

- [Types and Structures](ssltyp.html#1030559)

  - [CERTCertDBHandle](ssltyp.html#1028465) \` \<ssltyp.html#1027387>\`\_\_
  - [CERTCertificate](ssltyp.html#1027387) \` \<ssltyp.html#1028593>\`\_\_
  - [PK11SlotInfo](ssltyp.html#1028593) \` \<ssltyp.html#1026076>\`\_\_
  - [SECItem](ssltyp.html#1026076) \` \<ssltyp.html#1026727>\`\_\_
  - [SECKEYPrivateKey](ssltyp.html#1026727) \` \<ssltyp.html#1026722>\`\_\_
  - [SECStatus](ssltyp.html#1026722)

- [Managing SECItem Memory](ssltyp.html#1029645)

  - [SECItem_FreeItem](ssltyp.html#1030620) \` \<ssltyp.html#1030773>\`\_\_
  - [SECItem_ZfreeItem](ssltyp.html#1030773)

```{rubric} Chapter 4 SSL Functions
```

This chapter describes the core SSL functions.

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1022864`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1067601`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1237143`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1237143`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1234224`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1234224`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1068466`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1068466`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1204897`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1204897`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1084747`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1084747`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1208119`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1208119`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1138601`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1138601`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1143851`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1143851`

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1154189`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1142625`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1162055`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1162055`

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1098841`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1228530`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1100285`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1100285`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1105952`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1105952`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1104647`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1104647`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1210463`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1210463`

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1163855`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1090577`

    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1085950`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1086543`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1086543`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1194921`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1194921`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1214758`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1214758`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1214800`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1214800`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1217647`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1217647`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1087792`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1087792`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1088040`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1088040`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1089578`

    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1088805`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1088888`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1088888`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1088928`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1088928`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1126622`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1126622`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1106762`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1106762`
      {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1112702`
    - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1112702`

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1127321`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1089420`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1092785`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1092785`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1092805`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1092805`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1092869`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1092869`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1124562`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1124562`

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1127893`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1096168`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1081175`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1081175`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1123385`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1123385`

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1061582`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1133431`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1232052`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1232052`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1058001`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1058001`

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1095840`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1061858`

- {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1198429`

  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1206365`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1220189`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1220189`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1207298`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1207298`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1207350`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1207350`
    {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1231825`
  - {ref}`mozilla_projects_nss_ssl_functions_sslfnc#1231825`

```{rubric} Chapter 5 Certificate Functions
```

This chapter describes the functions and related types used to work with a certificate
database such as the cert7.db database provided with Communicator.

- [Validating Certificates](sslcrt.html#1060423)

  - [CERT_VerifyCertNow](sslcrt.html#1058011) \` \<sslcrt.html#1050342>\`\_\_
  - [CERT_VerifyCertName](sslcrt.html#1050342) \` \<sslcrt.html#1056662>\`\_\_
  - [CERT_CheckCertValidTimes](sslcrt.html#1056662) \` \<sslcrt.html#1056760>\`\_\_
  - [NSS_CmpCertChainWCANames](sslcrt.html#1056760)

- [Manipulating Certificates](sslcrt.html#1056436)

  - [CERT_DupCertificate](sslcrt.html#1058344) \` \<sslcrt.html#1050532>\`\_\_
  - [CERT_DestroyCertificate](sslcrt.html#1050532)

- [Getting Certificate Information](sslcrt.html#1056475)

  - [CERT_FindCertByName](sslcrt.html#1050345) \` \<sslcrt.html#1050346>\`\_\_
  - [CERT_GetCertNicknames](sslcrt.html#1050346) \` \<sslcrt.html#1050349>\`\_\_
  - [CERT_FreeNicknames](sslcrt.html#1050349) \` \<sslcrt.html#1052308>\`\_\_
  - [CERT_GetDefaultCertDB](sslcrt.html#1052308) \` \<sslcrt.html#1056950>\`\_\_
  - [NSS_FindCertKEAType](sslcrt.html#1056950)

- [Comparing SecItem Objects](sslcrt.html#1055384)

  - [SECITEM_CompareItem](sslcrt.html#1057028)

```{rubric} Chapter 6 Key Functions
```

This chapter describes two functions used to manipulate private keys and key databases such as
the key3.db database provided with Communicator.

- [SECKEY_GetDefaultKeyDB](sslkey.html#1051479) \` \<sslkey.html#1051017>\`\_\_
- [SECKEY_DestroyPrivateKey](sslkey.html#1051017)

```{rubric} Chapter 7 PKCS #11 Functions
```

This chapter describes the core PKCS #11 functions that an application needs for communicating
with cryptographic modules. In particular, these functions are used for obtaining
certificates, keys, and passwords.

- [PK11_FindCertFromNickname](pkfnc.html#1035673) \` \<pkfnc.html#1026891>\`\_\_
- [PK11_FindKeyByAnyCert](pkfnc.html#1026891) \` \<pkfnc.html#1030779>\`\_\_
- [PK11_GetSlotName](pkfnc.html#1030779) \` \<pkfnc.html#1026964>\`\_\_
- [PK11_GetTokenName](pkfnc.html#1026964) \` \<pkfnc.html#1026762>\`\_\_
- [PK11_IsHW](pkfnc.html#1026762) \` \<pkfnc.html#1022948>\`\_\_
- [PK11_IsPresent](pkfnc.html#1022948) \` \<pkfnc.html#1022991>\`\_\_
- [PK11_IsReadOnly](pkfnc.html#1022991) \` \<pkfnc.html#1023128>\`\_\_
- [PK11_SetPasswordFunc](pkfnc.html#1023128)

```{rubric} Chapter 8 NSS and SSL Error Codes
```

NSS error codes are retrieved using the NSPR function PR_GetError. In addition to the error
codes defined by NSPR, PR_GetError retrieves the error codes described in this chapter.

- [SSL Error Codes](sslerr.html#1040263) \` \<sslerr.html#1039257>\`\_\_
- [SEC Error Codes](sslerr.html#1039257)
:::
