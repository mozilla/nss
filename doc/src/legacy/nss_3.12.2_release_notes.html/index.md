(mozilla-projects-nss-nss-3-12-2-release-notes-html)=

# NSS_3.12.2_release_notes.html

(nss-3-12-2-release-notes)=

## NSS 3.12.2 Release Notes

(nss-3-12-2-release-date)=

### 2008-10-20

:::{container}
Newsgroup: [mozilla.dev.tech.crypto](news://news.mozilla.org/mozilla.dev.tech.crypto)
:::

### Contents

:::{container}

- [Introduction](#introduction)
- [Distribution Information](#distribution-information)
- [New in NSS 3.12.2](#new-in-nss-3122)
- [Bugs Fixed](#bugs-fixed)
- [Documentation](#documentation)
- [Compatibility](#compatibility)
- [Feedback](#feedback)
:::

### Introduction

:::{container}
Network Security Services (NSS) 3.12.2 is a patch release for NSS 3.12. The bug fixes in NSS
3.12.2 are described in the "[Bugs Fixed](#bugs-fixed)" section below.
NSS 3.12.2 is tri-licensed under the MPL 1.1/GPL 2.0/LGPL 2.1.
:::

### Distribution Information

:::{container}
The CVS tag for the NSS 3.12.2 release is NSS_3_12_2_RTM. NSS 3.12.2 requires [NSPR
4.7.1](https://www.mozilla.org/projects/nspr/release-notes/nspr471.html).
See the [Documentation](#documentation) section for the build instructions.
NSS 3.12.2 source and binary distributions are also available on ftp.mozilla.org for secure HTTPS
download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_12_2_RTM/src/>.

- Binary distributions:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_12_2_RTM/>. Both debug and
  optimized builds are provided. Go to the subdirectory for your platform, DBG (debug) or OPT
  (optimized), to get the tar.gz or zip file. The tar.gz or zip file expands to an nss-3.12.2
  directory containing three subdirectories:

  - include - NSS header files
  - lib - NSS shared libraries
  - bin< - [NSS Tools](https://www.mozilla.org/projects/security/pki/nss/tools/) and test
    programs

You also need to download the NSPR 4.7.1 binary distributions to get the NSPR 4.7.1 header files
and shared libraries, which NSS 3.12.2 requires. NSPR 4.7.1 binary distributions are in
<https://ftp.mozilla.org/pub/mozilla.org/nspr/releases/v4.7.1/>.
:::

(new-in-nss-3-12-2)=

### New in NSS 3.12.2

:::{container}

- New functions in the nss shared library:

  - SEC_PKCS12AddCertOrChainAndKey (see p12.h)

- New PKCS11 errors (see secerr.h)

  - SEC_ERROR_PKCS11_GENERAL_ERROR
  - SEC_ERROR_PKCS11_FUNCTION_FAILED
  - SEC_ERROR_PKCS11_DEVICE_ERROR
:::

### Bugs Fixed

:::{container}
The following bugs have been fixed in NSS 3.12.2.

- [Bug 200704](https://bugzilla.mozilla.org/show_bug.cgi?id=200704): PKCS11: invalid session
  handle 0
- [Bug 205434](https://bugzilla.mozilla.org/show_bug.cgi?id=205434): Fully implement new
  libPKIX cert verification API from bug 294531
- [Bug 302670](https://bugzilla.mozilla.org/show_bug.cgi?id=302670): Use the installed
  libz.so where available
- [Bug 305693](https://bugzilla.mozilla.org/show_bug.cgi?id=305693): shlibsign generates PQG
  for every run
- [Bug 311483](https://bugzilla.mozilla.org/show_bug.cgi?id=311483): exposing
  includeCertChain as a parameter to SEC_PKCS12AddCertAndKey
- [Bug 390527](https://bugzilla.mozilla.org/show_bug.cgi?id=390527): get rid of pkixErrorMsg
  variable in PKIX_Error
- [Bug 391560](https://bugzilla.mozilla.org/show_bug.cgi?id=391560): libpkix does not
  consistently return PKIX_ValidateNode tree that truly represent failure reasons
- [Bug 408260](https://bugzilla.mozilla.org/show_bug.cgi?id=408260): certutil usage doesn't
  give enough information about trust arguments
- [Bug 412311](https://bugzilla.mozilla.org/show_bug.cgi?id=412311): Replace
  PR_INTERVAL_NO_WAIT with PR_INTERVAL_NO_TIMEOUT in client initialization calls
- [Bug 423839](https://bugzilla.mozilla.org/show_bug.cgi?id=423839): Add multiple PKCS#11
  token password command line option to NSS tools.
- [Bug 432260](https://bugzilla.mozilla.org/show_bug.cgi?id=432260): \[[@
  pkix_pl_HttpDefaultClient_HdrCheckComplete - PKIX_PL_Memcpy] crashes when there is no
  content-length header in the http response
- [Bug 436599](https://bugzilla.mozilla.org/show_bug.cgi?id=436599): PKIX: AIA extension is
  not used in some Bridge CA / known certs configuration
- [Bug 437804](https://bugzilla.mozilla.org/show_bug.cgi?id=437804): certutil -R for cert
  renewal should derive the subject from the cert if none is specified.
- [Bug 444974](https://bugzilla.mozilla.org/show_bug.cgi?id=444974): Crash upon reinsertion
  of E-Identity smartcard
- [Bug 447563](https://bugzilla.mozilla.org/show_bug.cgi?id=447563): modutil -add prints no
  error explanation on failure
- [Bug 448431](https://bugzilla.mozilla.org/show_bug.cgi?id=448431): PK11_CreateMergeLog()
  declaration causes gcc warning when compiling with -Wstrict-prototypes
- [Bug 449334](https://bugzilla.mozilla.org/show_bug.cgi?id=449334): pk12util has duplicate
  options letters
- [Bug 449725](https://bugzilla.mozilla.org/show_bug.cgi?id=449725): signver is still using
  static libraries.
- [Bug 450427](https://bugzilla.mozilla.org/show_bug.cgi?id=450427): Add COMODO ECC
  Certification Authority certificate to NSS
- [Bug 450536](https://bugzilla.mozilla.org/show_bug.cgi?id=450536): Remove obsolete XP_MAC
  code
- [Bug 451024](https://bugzilla.mozilla.org/show_bug.cgi?id=451024): certutil.exe crashes
  with Segmentation fault inside PR_Cleanup
- [Bug 451927](https://bugzilla.mozilla.org/show_bug.cgi?id=451927):
  security/coreconf/WINNT6.0.mk has invalid defines
- [Bug 452751](https://bugzilla.mozilla.org/show_bug.cgi?id=452751): Slot leak in
  PK11_FindSlotsByNames
- [Bug 452865](https://bugzilla.mozilla.org/show_bug.cgi?id=452865): Remove obsolete linker
  flags needed when libnss3 was linked with libsoftokn3
- [Bug 454961](https://bugzilla.mozilla.org/show_bug.cgi?id=454961): Fix the implementation
  and use of pr_fgets in signtool
- [Bug 455348](https://bugzilla.mozilla.org/show_bug.cgi?id=455348): Change hyphens to
  underscores in DEBUG\_\$(shell whoami).
- [Bug 455424](https://bugzilla.mozilla.org/show_bug.cgi?id=455424): nssilckt.h defines the
  enumeration constant 'Lock'
- [Bug 456036](https://bugzilla.mozilla.org/show_bug.cgi?id=456036): Stubs for deprecated
  functions in lib/certdb/stanpcertdb.c should set the PR_NOT_IMPLEMENTED_ERROR error.
- [Bug 456854](https://bugzilla.mozilla.org/show_bug.cgi?id=456854): CERT_DecodeCertPackage
  does not set NSPR error code upon error
- [Bug 457980](https://bugzilla.mozilla.org/show_bug.cgi?id=457980): hundreds of kilobytes of
  useless strings in libPKIX
- [Bug 457984](https://bugzilla.mozilla.org/show_bug.cgi?id=457984): Enable PKCS11 module
  logging in optimized builds
- [Bug 458905](https://bugzilla.mozilla.org/show_bug.cgi?id=458905): Memory leaks in PKIX
  bridge certificates.
- [Bug 459231](https://bugzilla.mozilla.org/show_bug.cgi?id=459231): Memory leak in cert
  fetching - AIA extension.
- [Bug 459248](https://bugzilla.mozilla.org/show_bug.cgi?id=459248): Support Intel AES
  extensions.
- [Bug 459359](https://bugzilla.mozilla.org/show_bug.cgi?id=459359): ForwardBuilderState
  object is leaked when AIA path incorrect
- [Bug 459481](https://bugzilla.mozilla.org/show_bug.cgi?id=459481): NSS build problem with
  GCC 3.4.6 on OS/2
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
NSS 3.12.2 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.12.2 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in [NSS Public Functions](../ref/nssfunctions.html) will remain
compatible with future versions of the NSS shared libraries.
:::

### Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with [mozilla.org
Bugzilla](https://bugzilla.mozilla.org/) (product NSS).
:::
