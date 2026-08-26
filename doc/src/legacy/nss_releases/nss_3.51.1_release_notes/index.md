(mozilla-projects-nss-nss-3-51-1-release-notes)=

# NSS 3.51.1 release notes

## Introduction

:::{container}
The NSS team has released Network Security Services (NSS) 3.51.1 on **3 April 2020**. This is a
minor release focusing on functional bug fixes and low-risk patches only.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_51_1_RTM. NSS 3.51.1 requires NSPR 4.25 or newer.

NSS 3.51.1 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_51_1_RTM/src/>

Other releases are available {ref}`mozilla-projects-nss-nss-releases`.
:::

(notable-changes-in-nss-3-51-1)=

## Notable Changes in NSS 3.51.1

:::{container}

- [Bug 1617968](https://bugzilla.mozilla.org/show_bug.cgi?id=1617968) - Update Delegated
  Credentials implementation to draft-07.
:::

(bugs-fixed-in-nss-3-51-1)=

## Bugs fixed in NSS 3.51.1

:::{container}

- [Bug 1619102](https://bugzilla.mozilla.org/show_bug.cgi?id=1619102) - Add workaround option
  to include both DTLS and TLS versions in DTLS supported_versions.
- [Bug 1619056](https://bugzilla.mozilla.org/show_bug.cgi?id=1619056) - Update README: TLS
  1.3 is not experimental anymore.
- [Bug 1618739](https://bugzilla.mozilla.org/show_bug.cgi?id=1618739) - Don't assert fuzzer
  behavior in SSL_ParseSessionTicket.
- [Bug 1618915](https://bugzilla.mozilla.org/show_bug.cgi?id=1618915) - Fix UBSAN issue in
  ssl_ParseSessionTicket.
- [Bug 1608245](https://bugzilla.mozilla.org/show_bug.cgi?id=1608245) - Consistently handle
  NULL slot/session.
- [Bug 1608250](https://bugzilla.mozilla.org/show_bug.cgi?id=1608250) - broken fipstest
  handling of KI_len.
- [Bug 1617968](https://bugzilla.mozilla.org/show_bug.cgi?id=1617968) - Update Delegated
  Credentials implementation to draft-07.
:::

## Compatibility

:::{container}
NSS 3.51.1 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.51.1 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
