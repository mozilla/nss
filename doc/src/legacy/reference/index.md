(mozilla-projects-nss-reference)=

# NSS reference

(initial-notes)=

## Initial Notes

::::{container}

:::{container} notecard note

- We are migrating the {ref}`mozilla-projects-nss-ssl-functions-old-ssl-reference` into the
  format described in the [MDN Style
  Guide](https://developer.mozilla.org/en-US/docs/MDN/Guidelines). If you are inclined to
  help with this migration, your help would be very much appreciated.
- The proposed chapters below are based on the chapters of the
  {ref}`mozilla-projects-nss-ssl-functions-old-ssl-reference` and the categories of functions
  in {ref}`mozilla-projects-nss-reference-nss-functions`.
- Should a particular page require the use of an underscore, please see the documentation for
  the [Title Override Extension](/Project:En/MDC_style_guide#Title_Override_Extension).
:::
::::

(building-and-installing-nss)=

## Building and installing NSS

:::{container}
{ref}`mozilla-projects-nss-reference-building-and-installing-nss`
:::

(overview-of-an-nss-application)=

## Overview of an NSS application

:::{container}
Based on {ref}`mozilla-projects-nss-ssl-functions-sslintro` in the SSL Reference.
:::

(getting-started-with-nss)=

## Getting started with NSS

:::{container}
Based on {ref}`mozilla-projects-nss-ssl-functions-gtstd` in the SSL Reference.
:::

## Data types

:::{container}
Based on {ref}`mozilla-projects-nss-ssl-functions-ssltyp` in the SSL Reference.
:::

(nss-initialization-and-shutdown)=

## NSS initialization and shutdown

:::{container}

- NSS_Init
- NSS_InitReadWrite
- NSS_NoDB_Init
- {ref}`mozilla-projects-nss-reference-nss-initialize`
- NSS_Shutdown
:::

## Utility functions

:::{container}
Based on {ref}`mozilla_projects_nss_reference_nss_functions#utility_functions` in NSS Public
Functions.
:::

## Certificate functions

:::{container}
Based on {ref}`mozilla-projects-nss-ssl-functions-sslcrt` in the SSL Reference and
{ref}`mozilla_projects_nss_reference_nss_functions#certificate_functions` in NSS Public
Functions.

- {ref}`mozilla_projects_nss_reference_nss_certificate_functions#validating_certificates`

  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_verifycertnow`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_verifycert`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_verifycertname`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_checkcertvalidtimes`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#nss_cmpcertchainwcanames`

- {ref}`mozilla_projects_nss_reference_nss_certificate_functions#manipulating_certificates`

  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_dupcertificate`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_destroycertificate`
  - SEC_DeletePermCertificate
  - \_\_CERT_ClosePermCertDB

- {ref}`mozilla_projects_nss_reference_nss_certificate_functions#getting_certificate_information`

  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_findcertbyname`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_getcertnicknames`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_freenicknames`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#cert_getdefaultcertdb`
  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#nss_findcertkeatype`

- {ref}`mozilla_projects_nss_reference_nss_certificate_functions#comparing_secitem_objects`

  - {ref}`mozilla_projects_nss_reference_nss_certificate_functions#secitem_compareitem`
:::

## Key functions

:::{container}
{ref}`mozilla-projects-nss-reference-nss-key-functions`

- {ref}`mozilla_projects_nss_ssl_functions_sslkey#seckey_getdefaultkeydb`
- {ref}`mozilla_projects_nss_ssl_functions_sslkey#seckey_destroyprivatekey`
:::

(digital-signatures)=

## Digital signatures

:::{container}
This API consists of the routines used to perform signature generation and the routines used to
perform signature verification.
:::

(encryption-2fdecryption)=

## Encryption/decryption

## Hashing

(key-generation)=

## Key generation

:::{container}
Generate keys, key pairs, and domain parameters.
:::

(random-number-generation)=

## Random number generation

:::{container}
This API consists of the two routines used for pseudorandom number generation --
PK11_GenerateRandomOnSlot and PK11_GenerateRandom -- and the two routines used for seeding
pseudorandom number generation -- PK11_SeedRandom and PK11_RandomUpdate.
:::

## PKCS #11 functions

:::{container}
Based on {ref}`mozilla-projects-nss-ssl-functions-pkfnc` in the SSL Reference and
{ref}`mozilla_projects_nss_reference_nss_functions#cryptography_functions` in NSS Public
Functions.

- {ref}`mozilla_projects_nss_pkcs11_functions#secmod_loadusermodule`
- {ref}`mozilla_projects_nss_pkcs11_functions#secmod_unloadusermodule`
- {ref}`mozilla_projects_nss_pkcs11_functions#secmod_closeuserdb`
- {ref}`mozilla_projects_nss_pkcs11_functions#secmod_openuserdb`
- {ref}`mozilla_projects_nss_pkcs11_functions#pk11_findcertfromnickname`
- {ref}`mozilla_projects_nss_pkcs11_functions#pk11_findkeybyanycert`
- {ref}`mozilla_projects_nss_pkcs11_functions#pk11_getslotname`
- {ref}`mozilla_projects_nss_pkcs11_functions#pk11_gettokenname`
- {ref}`mozilla_projects_nss_pkcs11_functions#pk11_ishw`
- {ref}`mozilla_projects_nss_pkcs11_functions#pk11_ispresent`
- {ref}`mozilla_projects_nss_pkcs11_functions#pk11_isreadonly`
- {ref}`mozilla_projects_nss_pkcs11_functions#pk11_setpasswordfunc`
:::

## SSL Functions

:::{container}
Based on {ref}`mozilla-projects-nss-ssl-functions-sslfnc` in the SSL Reference and
{ref}`mozilla_projects_nss_reference_nss_functions#ssl_functions` and
{ref}`mozilla_projects_nss_reference_nss_functions#deprecated_ssl_functions` in NSS Public
Functions.

- SSL_ConfigServerSessionIDCache
- SSL_ClearSessionCache
:::

(s-2fmime)=

## S/MIME

:::{container}
Based on the [S/MIME
Reference](https://www-archive.mozilla.org/projects/security/pki/nss/ref/smime/) (which only
has one written chapter) and
{ref}`mozilla_projects_nss_reference_nss_functions#s_2fmime_functions` in NSS Public Functions.
:::

## PKCS #7 functions

:::{container}
Based on ["Archived PKCS #7 Functions
documentation."](https://www-archive.mozilla.org/projects/security/pki/nss/ref/nssfunctions.html#pkcs7)
:::

(pkcs-235-functions)=

## PKCS #5 functions

:::{container}
Password-based encryption

- SEC_PKCS5GetIV
- SEC_PKCS5CreateAlgorithmID
- SEC_PKCS5GetCryptoAlgorithm
- SEC_PKCS5GetKeyLength
- SEC_PKCS5GetPBEAlgorithm
- SEC_PKCS5IsAlgorithmPBEAlg
:::

## PKCS #12 functions

:::{container}
Based on ["Archived PKCS #12 Functions
documentation."](https://www-archive.mozilla.org/projects/security/pki/nss/ref/nssfunctions.html#pkcs12)
Used to exchange data such as private keys and certificates between two parties.

- SEC_PKCS12CreateExportContext
- SEC_PKCS12CreatePasswordPrivSafe
- SEC_PKCS12CreateUnencryptedSafe
- SEC_PKCS12AddCertAndKey
- SEC_PKCS12AddPasswordIntegrity
- SEC_PKCS12EnableCipher
- SEC_PKCS12Encode
- SEC_PKCS12DestroyExportContext
- SEC_PKCS12DecoderStart
- SEC_PKCS12DecoderImportBags
- SEC_PKCS12DecoderUpdate
- SEC_PKCS12DecoderFinish
- SEC_PKCS12DecoderValidateBags
- SEC_PKCS12DecoderVerify
- SEC_PKCS12DecoderGetCerts
- SEC_PKCS12DecoderSetTargetTokenCAs
- SEC_PKCS12DecoderIterateInit
- SEC_PKCS12DecoderIterateNext
- SEC_PKCS12IsEncryptionAllowed
- SEC_PKCS12SetPreferredCipher
:::

(nspr-functions)=

## NSPR functions

:::{container}
A small number of {ref}`mozilla-projects-nss-reference-nspr-functions` are required for using the
certificate verification and SSL functions in NSS. These functions are listed in this section.
:::

## Error codes

:::{container}
Based on {ref}`mozilla-projects-nss-ssl-functions-sslerr` in the SSL Reference.
:::

(nss-environment-variables)=

## NSS Environment variables

:::{container}
{ref}`mozilla-projects-nss-reference-nss-environment-variables`
:::

(nss-cryptographic-module)=

## NSS cryptographic module

:::{container}
{ref}`mozilla-projects-nss-reference-nss-cryptographic-module`
:::

(nss-tech-notes)=

## NSS Tech Notes

:::{container}
{ref}`mozilla-projects-nss-nss-tech-notes` {ref}`mozilla-projects-nss-memory-allocation`
:::

## Tools

:::{container}
Based on {ref}`mozilla-projects-nss-tools` documentation.

Based on {ref}`mozilla-projects-nss-tools`
:::
