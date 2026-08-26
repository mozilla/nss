(mozilla-projects-nss-nss-3-31-1-release-notes)=

# NSS 3.31.1 release notes

::::{container}

:::{note}
**This is a DRAFT document.** This notice will be removed when completed.
:::
::::

## Introduction

:::{container}
The Network Security Services (NSS) team has released NSS 3.31.1, which is a patch release for
NSS 3.31.
:::

## Distribution information

:::{container}
The hg tag is NSS_3_31_1_RTM. NSS 3.31.1 requires Netscape Portable Runtime (NSPR) 4.15, or
newer.

NSS 3.31.1 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_31_1_RTM/src/>
:::

(new-in-nss-3-31-1)=

## New in NSS 3.31.1

:::{container}
No new functionality is introduced in this release.
:::

(bugs-fixed-in-nss-3-31-1)=

## Bugs fixed in NSS 3.31.1

:::{container}

- [Bug 1381784](https://bugzilla.mozilla.org/show_bug.cgi?id=1381784) - Potential deadlock
  when using an external PKCS#11 token.
:::

## Compatibility

:::{container}
NSS 3.31.1 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.31.1 shared libraries,
without recompiling, or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
