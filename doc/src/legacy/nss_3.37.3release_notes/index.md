(mozilla-projects-nss-nss-3-37-3release-notes)=

# NSS 3.37.3 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.37.3 is a patch release for NSS 3.37.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_37_3_RTM. NSS 3.37.3 requires NSPR 4.19 or newer.

NSS 3.37.3 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/security/nss/releases/NSS_3_37_3_RTM/src/>
:::

(new-in-nss-3-37-3)=

## New in NSS 3.37.3

### New Functionality

:::{container}
No new functionality is introduced in this release. This is a patch release to fix regression
bugs.
:::

(bugs-fixed-in-nss-3-37-3)=

## Bugs fixed in NSS 3.37.3

:::{container}

- Bug 1459739 - Fix build on armv6/armv7 and other platforms.
- Bug 1461731 - Fix crash on macOS related to authentication tokens, e.g. PK11or WebAuthn.
:::

## Compatibility

:::{container}
NSS 3.37.3 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.37.3 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
