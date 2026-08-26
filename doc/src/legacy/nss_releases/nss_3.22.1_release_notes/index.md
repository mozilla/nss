(mozilla-projects-nss-nss-3-22-1-release-notes)=

# NSS 3.22.1 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.22.1 is a patch release for NSS 3.22. The bug fixes in NSS
3.22.1 are described in the "Notable Changes" section below.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_22_1_RTM. NSS 3.22.1 requires NSPR 4.12 or newer.

NSS 3.22.1 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_22_1_RTM/src/>
:::

(new-in-nss-3-22-1)=

## New in NSS 3.22.1

### New Functionality

:::{container}
No new functionality is introduced in this release.
:::

(notable-changes-in-nss-3-22-1)=

## Notable Changes in NSS 3.22.1

:::{container}

- [bug 1194680](https://bugzilla.mozilla.org/show_bug.cgi?id=1194680): NSS has been changed
  to use the PR_GetEnvSecure function that was made available in NSPR 4.12
:::

## Compatibility

:::{container}
NSS 3.22.1 shared libraries are backward compatible with all older NSS 3.22 shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.22.1 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
