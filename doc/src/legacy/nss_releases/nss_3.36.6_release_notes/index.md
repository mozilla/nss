(mozilla-projects-nss-nss-3-36-6-release-notes)=

# NSS 3.36.6 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.36.6 is a patch release for NSS 3.36. The bug fixes in NSS
3.36.6 are described in the "Bugs Fixed" section below.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_36_6_RTM. NSS 3.36.6 requires NSPR 4.19 or newer.

NSS 3.36.6 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_36_6_RTM/src/>
:::

(new-in-nss-3-36-6)=

## New in NSS 3.36.6

### New Functionality

:::{container}
No new functionality is introduced in this release. This is a patch release to fix CVE-2018-12404
:::

(bugs-fixed-in-nss-3-36-6)=

## Bugs fixed in NSS 3.36.6

:::{container}
[Bug 1485864](https://bugzilla.mozilla.org/show_bug.cgi?id=1485864) - Cache side-channel
variant of the Bleichenbacher attack (CVE-2018-12404)

[Bug 1389967](https://bugzilla.mozilla.org/show_bug.cgi?id=1389967) and [Bug
1448748](https://bugzilla.mozilla.org/show_bug.cgi?id=1448748) - Fixes for MinGW on x64
platforms.
:::

## Compatibility

:::{container}
NSS 3.36.6 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.36.6 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
