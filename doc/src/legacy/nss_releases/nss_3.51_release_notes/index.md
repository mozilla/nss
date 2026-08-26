(mozilla-projects-nss-nss-3-51-release-notes)=

# NSS 3.51 release notes

## Introduction

:::{container}
The NSS team has released Network Security Services (NSS) 3.51 on **6 March 2020**, which is a
minor release.

The NSS team would like to recognize first-time contributors:

- Dmitry Baryshkov
- Victor Tapia
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_51_RTM. NSS 3.51 requires NSPR 4.25 or newer.

NSS 3.51 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_51_RTM/src/>

Other releases are available {ref}`mozilla-projects-nss-nss-releases`.
:::

(notable-changes-in-nss-3-51)=

## Notable Changes in NSS 3.51

:::{container}

- Updated DTLS 1.3 implementation to Draft-34. See [Bug
  1608892](https://bugzilla.mozilla.org/show_bug.cgi?id=1608892) for details.
:::

(bugs-fixed-in-nss-3-51)=

## Bugs fixed in NSS 3.51

:::{container}

- [Bug 1608892](https://bugzilla.mozilla.org/show_bug.cgi?id=1608892) - Update DTLS 1.3
  implementation to draft-34.
- [Bug 1611209](https://bugzilla.mozilla.org/show_bug.cgi?id=1611209) - Correct swapped
  PKCS11 values of CKM_AES_CMAC and CKM_AES_CMAC_GENERAL
- [Bug 1612259](https://bugzilla.mozilla.org/show_bug.cgi?id=1612259) - Complete integration
  of Wycheproof ECDH test cases
- [Bug 1614183](https://bugzilla.mozilla.org/show_bug.cgi?id=1614183) - Check if PPC
  \_\_has_include(\<sys/auxv.h>)
- [Bug 1614786](https://bugzilla.mozilla.org/show_bug.cgi?id=1614786) - Fix a compilation
  error for ‘getFIPSEnv’ "defined but not used"
- [Bug 1615208](https://bugzilla.mozilla.org/show_bug.cgi?id=1615208) - Send DTLS version
  numbers in DTLS 1.3 supported_versions extension to avoid an incompatibility.
- [Bug 1538980](https://bugzilla.mozilla.org/show_bug.cgi?id=1538980) - SECU_ReadDERFromFile
  calls strstr on a string that isn't guaranteed to be null-terminated
- [Bug 1561337](https://bugzilla.mozilla.org/show_bug.cgi?id=1561337) - Correct a warning for
  comparison of integers of different signs: 'int' and 'unsigned long' in
  security/nss/lib/freebl/ecl/ecp_25519.c:88
- [Bug 1609751](https://bugzilla.mozilla.org/show_bug.cgi?id=1609751) - Add test for mp_int
  clamping
- [Bug 1582169](https://bugzilla.mozilla.org/show_bug.cgi?id=1582169) - Don't attempt to read
  the fips_enabled flag on the machine unless NSS was built with FIPS enabled
- [Bug 1431940](https://bugzilla.mozilla.org/show_bug.cgi?id=1431940) - Fix a null pointer
  dereference in BLAKE2B_Update
- [Bug 1617387](https://bugzilla.mozilla.org/show_bug.cgi?id=1617387) - Fix compiler warning
  in secsign.c
- [Bug 1618400](https://bugzilla.mozilla.org/show_bug.cgi?id=1618400) - Fix a OpenBSD/arm64
  compilation error: unused variable 'getauxval'
- [Bug 1610687](https://bugzilla.mozilla.org/show_bug.cgi?id=1610687) - Fix a crash on
  unaligned CMACContext.aes.keySchedule when using AES-NI intrinsics

This Bugzilla query returns all the bugs fixed in NSS 3.51:

<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&product=NSS&target_milestone=3.51>
:::

## Compatibility

:::{container}
NSS 3.51 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.51 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
