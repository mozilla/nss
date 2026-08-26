(mozilla-projects-nss-nss-3-19-2-4-release-notes)=

# NSS 3.19.2.4 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.19.2.4 is a security patch release for NSS 3.19.2. The bug
fixed in NSS 3.19.2.4 have been described in the "Security Fixes" section below.

(Current users of NSS 3.19.3, NSS 3.19.4 or NSS 3.20.x are advised to update to
{ref}`mozilla-projects-nss-nss-3-21-1-release-notes`,
{ref}`mozilla-projects-nss-nss-3-22-2-release-notes` or a later release.)
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_19_2_4_RTM. NSS 3.19.2.4 requires NSPR 4.10.10 or newer.

NSS 3.19.2.4 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_19_2_4_RTM/src/>
:::

(new-in-nss-3-19-2-4)=

## New in NSS 3.19.2.4

### New Functionality

:::{container}
No new functionality has been introduced in this release.
:::

(security-fixes-in-nss-3-19-2-4)=

## Security Fixes in NSS 3.19.2.4

:::{container}
The following security fixes from NSS 3.21 have been backported to NSS 3.19.2.4:

- [Bug 1185033](https://bugzilla.mozilla.org/show_bug.cgi?id=1185033) /
  [CVE-2016-1979](http://www.cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2016-1979) -
  Use-after-free during processing of DER encoded keys in NSS
- [Bug 1209546](https://bugzilla.mozilla.org/show_bug.cgi?id=1209546) /
  [CVE-2016-1978](http://www.cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2016-1978) -
  Use-after-free in NSS during SSL connections in low memory
- [Bug 1190248](https://bugzilla.mozilla.org/show_bug.cgi?id=1190248) /
  [CVE-2016-1938](http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2016-1938) - Errors in
  mp_div and mp_exptmod cryptographic functions in NSS
:::

## Compatibility

:::{container}
NSS 3.19.2.4 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.19.2.4 shared libraries
without recompiling or relinking. Furthermore, applications that restrict the use of NSS APIs to
the functions listed in NSS Public Functions will remain compatible with future versions of the
NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
