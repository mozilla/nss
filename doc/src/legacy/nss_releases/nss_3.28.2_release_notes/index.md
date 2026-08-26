(mozilla-projects-nss-nss-3-28-2-release-notes)=

# NSS 3.28.2 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.28.2 is a patch release for NSS 3.28.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_28_2_RTM. NSS 3.28.2 requires NSPR 4.13.1 or newer.

NSS 3.28.2 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_28_2_RTM/src/>
:::

(incorrect-version-number)=

## Incorrect version number

:::{container}

- Note the version numbers embedded in the NSS 3.28.2 are wrong (it reports itself as version
  3.28.1).
:::

(new-in-nss-3-28-2)=

## New in NSS 3.28.2

:::{container}
No new functionality is introduced in this release. This is a patch release includes bug fixes
and addresses some compatibility issues with TLS.
:::

(bugs-fixed-in-nss-3-28-2)=

## Bugs fixed in NSS 3.28.2

:::{container}

- [Bug 1334114 - NSS 3.28 regression in signature scheme flexibility, causes connectivity issue
  between iOS 8 clients and NSS servers with ECDSA
  certificates](https://bugzilla.mozilla.org/show_bug.cgi?id=1334114)
- [Bug 1330612 - X25519 is the default curve for ECDHE in
  NSS](https://bugzilla.mozilla.org/show_bug.cgi?id=1330612)
- [Bug 1323150 - Crash [@ ReadDBEntry
  ]](https://bugzilla.mozilla.org/show_bug.cgi?id=1323150)
:::

## Compatibility

:::{container}
NSS 3.28.2 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.28.2 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
