(mozilla-projects-nss-nss-3-22-3-release-notes)=

# NSS 3.22.3 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.22.3 is a patch release for NSS 3.22. The bug fixes in NSS
3.22.3 are described in the "Bugs fixed" section below.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_22_3_RTM. NSS 3.22.3 requires NSPR 4.12 or newer.

NSS 3.22.3 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_22_3_RTM/src/>
:::

(new-in-nss-3-22-3)=

## New in NSS 3.22.3

### New Functionality

:::{container}
No new functionality is introduced in this release.
:::

(bugs-fixed-in-nss-3-22-3)=

## Bugs fixed in NSS 3.22.3

:::{container}

- [Bug 1243641](https://bugzilla.mozilla.org/show_bug.cgi?id=1243641) - Increase
  compatibility of TLS extended master secret, don't send an empty TLS extension last in the
  handshake
:::

## Compatibility

:::{container}
NSS 3.22.3 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.22.3 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
