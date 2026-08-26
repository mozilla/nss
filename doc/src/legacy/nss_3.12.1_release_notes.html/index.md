(mozilla-projects-nss-nss-3-12-1-release-notes-html)=

# NSS_3.12.1_release_notes.html

(nss-3-12-1-release-notes)=

## NSS 3.12.1 Release Notes

(nss-3-12-1-release-date)=

### 2008-09-05

:::{container}
Newsgroup: [mozilla.dev.tech.crypto](news://news.mozilla.org/mozilla.dev.tech.crypto)
:::

### Contents

:::{container}

- [Introduction](#introduction)
- [Distribution Information](#distribution-information)
- [New in NSS 3.12.1](#new-in-nss-3121)
- [Bugs Fixed](#bugs-fixed)
- [Documentation](#documentation)
- [Compatibility](#compatibility)
- [Feedback](#feedback)
:::

### Introduction

:::{container}
Network Security Services (NSS) 3.12.1 is a patch release for NSS 3.12. The bug fixes in NSS
3.12.1 are described in the "[Bugs Fixed](#bugs-fixed)" section below.
NSS 3.12.1 is tri-licensed under the MPL 1.1/GPL 2.0/LGPL 2.1.
:::

### Distribution Information

:::{container}
The CVS tag for the NSS 3.12.1 release is NSS_3_12_1_RTM. NSS 3.12.1 requires [NSPR
4.7.1](https://www.mozilla.org/projects/nspr/release-notes/nspr471.html).
See the [Documentation](#docs) section for the build instructions.
NSS 3.12.1 source and binary distributions are also available on ftp.mozilla.org for secure HTTPS
download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_12_1_RTM/src/>.

- Binary distributions:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_12_1_RTM/>. Both debug and
  optimized builds are provided. Go to the subdirectory for your platform, DBG (debug) or OPT
  (optimized), to get the tar.gz or zip file. The tar.gz or zip file expands to an nss-3.12.1
  directory containing three subdirectories:

  - include - NSS header files
  - lib - NSS shared libraries
  - bin - [NSS Tools](https://www.mozilla.org/projects/security/pki/nss/tools/) and test
    programs

You also need to download the NSPR 4.7.1 binary distributions to get the NSPR 4.7.1 header files
and shared libraries, which NSS 3.12.1 requires. NSPR 4.7.1 binary distributions are in
<https://ftp.mozilla.org/pub/mozilla.org/nspr/releases/v4.7.1/>.
:::

(new-in-nss-3-12-1)=

### New in NSS 3.12.1

:::{container}

- New functions in the nss shared library:

  CERT_NameToAsciiInvertible (see cert.h)

  : Convert an CERTName into its RFC1485 encoded equivalent.
    Returns a string that must be freed with PORT_Free().
    Caller chooses encoding rules.

  CERT_EncodeSubjectKeyID (see cert.h)

  : Encode Certificate SKID (Subject Key ID) extension.

  PK11_GetAllSlotsForCert (see pk11pub.h)

  : PK11_GetAllSlotsForCert returns all the slots that a given certificate
    exists on, since it's possible for a cert to exist on more than one
    PKCS#11 token.

- Levels of standards conformance strictness for CERT_NameToAsciiInvertible (see certt.h)

  CERT_N2A_READABLE

  : (maximum human readability)

  CERT_N2A_STRICT

  : (strict RFC compliance)

  CERT_N2A_INVERTIBLE

  : (maximum invertibility)
:::

### Bugs Fixed

:::{container}
The following bugs have been fixed in NSS 3.12.1.

- [Bug 67890](https://bugzilla.mozilla.org/show_bug.cgi?id=67890): create self-signed cert
  with existing key that signed CSR
- [Bug 129303](https://bugzilla.mozilla.org/show_bug.cgi?id=129303): NSS needs to expose
  interfaces to deal with multiple token sources of certs.
- [Bug 311432](https://bugzilla.mozilla.org/show_bug.cgi?id=311432): ECC's ECL_USE_FP code
  (for Linux x86) fails pairwise consistency test
- [Bug 330622](https://bugzilla.mozilla.org/show_bug.cgi?id=330622): certutil's usage
  messages incorrectly document certain options
- [Bug 330628](https://bugzilla.mozilla.org/show_bug.cgi?id=330628): coreconf/Linux.mk should
  \_not\_ default to x86 but result in an error if host is not recognized
- [Bug 359302](https://bugzilla.mozilla.org/show_bug.cgi?id=359302): Remove the sslsample
  code from NSS source tree
- [Bug 372241](https://bugzilla.mozilla.org/show_bug.cgi?id=372241): Need more versatile form
  of CERT_NameToAscii
- [Bug 390296](https://bugzilla.mozilla.org/show_bug.cgi?id=390296): NSS ignores subject CN
  even when SAN contains no dNSName
- [Bug 401928](https://bugzilla.mozilla.org/show_bug.cgi?id=401928): Support generalized
  PKCS#5 v2 PBEs
- [Bug 403543](https://bugzilla.mozilla.org/show_bug.cgi?id=403543): pkix: need a way to
  enable/disable AIA cert fetching
- [Bug 408847](https://bugzilla.mozilla.org/show_bug.cgi?id=408847): pkix_OcspChecker_Check
  does not support specified responder (and given signercert)
- [Bug 414003](https://bugzilla.mozilla.org/show_bug.cgi?id=414003): Crash \[[@
  CERT_DecodeCertPackage] sometimes with this testcase
- [Bug 415167](https://bugzilla.mozilla.org/show_bug.cgi?id=415167): Memory leak in certutil
- [Bug 417399](https://bugzilla.mozilla.org/show_bug.cgi?id=417399): Arena Allocation results
  are not checked in pkix_pl_InfoAccess_ParseLocation
- [Bug 420644](https://bugzilla.mozilla.org/show_bug.cgi?id=420644): Improve SSL tracing of
  key derivation
- [Bug 426886](https://bugzilla.mozilla.org/show_bug.cgi?id=426886): Use const char\* in
  PK11_ImportCertForKey
- [Bug 428103](https://bugzilla.mozilla.org/show_bug.cgi?id=428103): CERT_EncodeSubjectKeyID
  is not defined in any public header file
- [Bug 429716](https://bugzilla.mozilla.org/show_bug.cgi?id=429716): debug builds of libPKIX
  unconditionally dump socket traffic to stdout
- [Bug 430368](https://bugzilla.mozilla.org/show_bug.cgi?id=430368): vfychain -t option is
  undocumented
- [Bug 430369](https://bugzilla.mozilla.org/show_bug.cgi?id=430369): vfychain -o succeeds
  even if -pp is not specified
- [Bug 430399](https://bugzilla.mozilla.org/show_bug.cgi?id=430399): vfychain -pp crashes
- [Bug 430405](https://bugzilla.mozilla.org/show_bug.cgi?id=430405): Error log is not
  produced by CERT_PKIXVerifyCert
- [Bug 430743](https://bugzilla.mozilla.org/show_bug.cgi?id=430743): Update ssltap to
  understand the TLS session ticket extension
- [Bug 430859](https://bugzilla.mozilla.org/show_bug.cgi?id=430859): PKIX: Policy mapping
  fails verification with error invalid arguments
- [Bug 430875](https://bugzilla.mozilla.org/show_bug.cgi?id=430875): Document the policy for
  the order of cipher suites in SSL_ImplementedCiphers.
- [Bug 430916](https://bugzilla.mozilla.org/show_bug.cgi?id=430916): add sustaining asserts
- [Bug 431805](https://bugzilla.mozilla.org/show_bug.cgi?id=431805): leak in
  NSSArena_Destroy()
- [Bug 431929](https://bugzilla.mozilla.org/show_bug.cgi?id=431929): Memory leaks on error
  paths in devutil.c
- [Bug 432303](https://bugzilla.mozilla.org/show_bug.cgi?id=432303): Replace PKIX_PL_Memcpy
  with memcpy
- [Bug 433177](https://bugzilla.mozilla.org/show_bug.cgi?id=433177): Fix the GCC compiler
  warnings in lib/util and lib/freebl
- [Bug 433437](https://bugzilla.mozilla.org/show_bug.cgi?id=433437): vfychain ignores the -a
  option
- [Bug 433594](https://bugzilla.mozilla.org/show_bug.cgi?id=433594): Crash destroying OCSP
  Cert ID \[[@ CERT_DestroyOCSPCertID ]
- [Bug 434099](https://bugzilla.mozilla.org/show_bug.cgi?id=434099): NSS relies on unchecked
  PKCS#11 object attribute values
- [Bug 434187](https://bugzilla.mozilla.org/show_bug.cgi?id=434187): Fix the GCC compiler
  warnings in nss/lib
- [Bug 434398](https://bugzilla.mozilla.org/show_bug.cgi?id=434398): libPKIX cannot find
  issuer cert immediately after checking it with OCSP
- [Bug 434808](https://bugzilla.mozilla.org/show_bug.cgi?id=434808): certutil -B deadlock
  when importing two or more roots
- [Bug 434860](https://bugzilla.mozilla.org/show_bug.cgi?id=434860): Coverity 1150 - dead
  code in ocsp_CreateCertID
- [Bug 436428](https://bugzilla.mozilla.org/show_bug.cgi?id=436428): remove unneeded assert
  from sec_PKCS7EncryptLength
- [Bug 436430](https://bugzilla.mozilla.org/show_bug.cgi?id=436430): Make NSS public headers
  compilable with NO_NSPR_10_SUPPORT defined
- [Bug 436577](https://bugzilla.mozilla.org/show_bug.cgi?id=436577): uninitialized variable
  in sec_pkcs5CreateAlgorithmID
- [Bug 438685](https://bugzilla.mozilla.org/show_bug.cgi?id=438685): libpkix doesn't try all
  the issuers in a bridge with multiple certs
- [Bug 438876](https://bugzilla.mozilla.org/show_bug.cgi?id=438876): signtool is still using
  static libraries.
- [Bug 439123](https://bugzilla.mozilla.org/show_bug.cgi?id=439123): Assertion failure in
  libpkix at shutdown
- [Bug 440062](https://bugzilla.mozilla.org/show_bug.cgi?id=440062): incorrect list element
  count in PKIX_List_AppendItem function
- [Bug 442618](https://bugzilla.mozilla.org/show_bug.cgi?id=442618): Eliminate dead function
  CERT_CertPackageType
- [Bug 443755](https://bugzilla.mozilla.org/show_bug.cgi?id=443755): Extra semicolon in
  PKM_TLSKeyAndMacDerive makes conditional code unconditional
- [Bug 443760](https://bugzilla.mozilla.org/show_bug.cgi?id=443760): Extra semicolon in
  SeqDatabase makes static analysis tool suspicious
- [Bug 448323](https://bugzilla.mozilla.org/show_bug.cgi?id=448323): certutil -K doesn't
  report the token and slot names for found keys
- [Bug 448324](https://bugzilla.mozilla.org/show_bug.cgi?id=448324): ocsp checker returns
  incorrect error code on request with invalid signing cert
- [Bug 449146](https://bugzilla.mozilla.org/show_bug.cgi?id=449146): Remove dead libsec
  function declarations
- [Bug 453227](https://bugzilla.mozilla.org/show_bug.cgi?id=453227): installation of
  PEM-encoded certificate without trailing newline fails
:::

### Documentation

:::{container}
For a list of the primary NSS documentation pages on mozilla.org, see [NSS
Documentation](../index.html#Documentation). New and revised documents available since the
release of NSS 3.11 include the following:

- [Build Instructions for NSS 3.11.4 and above](../nss-3.11.4/nss-3.11.4-build.html)
- [NSS Shared DB](http://wiki.mozilla.org/NSS_Shared_DB)
:::

### Compatibility

:::{container}
NSS 3.12.1 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.12.1 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in [NSS Public Functions](../ref/nssfunctions.html) will remain
compatible with future versions of the NSS shared libraries.
:::

### Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with [mozilla.org
Bugzilla](https://bugzilla.mozilla.org/) (product NSS).
:::
