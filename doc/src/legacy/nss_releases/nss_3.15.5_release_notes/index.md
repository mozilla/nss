(mozilla-projects-nss-nss-3-15-5-release-notes)=

# NSS 3.15.5 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.15.5 is a patch release for NSS 3.15. The bug fixes in NSS
3.15.5 are described in the "Bugs Fixed" section below.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_15_5_RTM. NSS 3.15.5 requires NSPR 4.10.2 or newer.

NSS 3.15.5 source distributions are also available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_15_5_RTM/src/>
:::

(new-in-nss-3-15-5)=

## New in NSS 3.15.5

### New Functionality

:::{container}

- Added support for the TLS [application layer protocol negotiation (ALPN)
  extension](http://www.iana.org/go/draft-friedl-tls-applayerprotoneg). Two SSL socket
  options, `SSL_ENABLE_NPN` and `SSL_ENABLE_ALPN`, can be used to control whether NPN or
  ALPN (or both) should be used for application layer protocol negotiation.
- Added the TLS [padding
  extension](https://datatracker.ietf.org/doc/html/draft-agl-tls-padding). The extension type
  value is 35655, which may change when an official extension type value is assigned by IANA.
  NSS automatically adds the padding extension to ClientHello when necessary.
- Added a new macro `CERT_LIST_TAIL`, defined in `certt.h`, for getting the tail of a
  `CERTCertList`.
:::

(notable-changes-in-nss-3-15-5)=

### Notable Changes in NSS 3.15.5

:::{container}

- [Bug 950129](https://bugzilla.mozilla.org/show_bug.cgi?id=950129): Improve the OCSP
  fetching policy when verifying OCSP responses
- [Bug 949060](https://bugzilla.mozilla.org/show_bug.cgi?id=949060): Validate the `iov`
  input argument (an array of `PRIOVec` structures) of `ssl_WriteV` (called via
  `PR_Writev`). Applications should still take care when converting `struct iov` to
  `PRIOVec` because the `iov_len` members of the two structures have different types
  (`size_t` vs. `int`). `size_t` is unsigned and may be larger than `int`.
:::

(bugs-fixed-in-nss-3-15-5)=

### Bugs fixed in NSS 3.15.5

:::{container}
A complete list of all bugs resolved in this release can be obtained at
<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&target_milestone=3.15.5&product=NSS>
:::

## Compatibility

:::{container}
NSS 3.15.5 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.15.5 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
