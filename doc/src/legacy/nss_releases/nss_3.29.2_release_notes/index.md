(mozilla-projects-nss-nss-3-29-2-release-notes)=

# NSS 3.29.2 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.29.2 is a patch release for NSS 3.29. The bug fixes in NSS
3.29.2 are described in the "Bugs Fixed" section below.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_29_2_RTM. NSS 3.29.2 requires Netscape Portable Runtime(NSPR) 4.13.1 or
newer.

NSS 3.29.2 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/security/nss/releases/NSS_3_29_2_RTM/src/>
:::

(new-in-nss-3-29-2)=

## New in NSS 3.29.2

### New Functionality

:::{container}
No new functionality is introduced in this release.
:::

(bugs-fixed-in-nss-3-29-2)=

## Bugs fixed in NSS 3.29.2

:::{container}
NSS 3.29 and 3.29.1 included a change that reduced the time that NSS considered a TLS session
ticket to be valid. This release restores the session ticket lifetime to the intended value. See
[Bug 1340841](https://bugzilla.mozilla.org/show_bug.cgi?id=1340841) for details.
:::

## Compatibility

:::{container}
NSS 3.29.2 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.29.2 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
