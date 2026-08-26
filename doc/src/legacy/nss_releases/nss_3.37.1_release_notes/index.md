(mozilla-projects-nss-nss-3-37-1-release-notes)=

# NSS 3.37.1 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.37.1 is a patch release for NSS 3.37.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_37_1_RTM. NSS 3.37.1 requires NSPR 4.19 or newer.

NSS 3.37.1 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/security/nss/releases/NSS_3_37_1_RTM/src/>
:::

(new-in-nss-3-37-1)=

## New in NSS 3.37.1

### New Functionality

:::{container}
No new functionality is introduced in this release. This is a patch release to fix regression
bugs.
:::

(bugs-fixed-in-nss-3-37-1)=

## Bugs fixed in NSS 3.37.1

:::{container}

- Bug 1462303 - Connecting to a server that was recently upgraded to TLS 1.3 would result in a
  SSL_RX_MALFORMED_SERVER_HELLO error.
- Bug 1460673 - Fix a rare bug with PKCS#12 files.

This Bugzilla query returns all the bugs fixed in NSS 3.37.1:

<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&product=NSS&target_milestone=3.37.1>
:::

## Compatibility

:::{container}
NSS 3.37.1 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.37.1 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
