(mozilla-projects-nss-nss-3-19-2-2-release-notes)=

# NSS 3.19.2.2 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.19.2.2 is a security patch release for NSS 3.19.2. The bug
fixes in NSS 3.19.2.2 are described in the "Security Fixes" section below.

(Current users of NSS 3.19.3 or NSS 3.19.4 are advised to update to
{ref}`mozilla-projects-nss-nss-3-20-2-release-notes`,
{ref}`mozilla-projects-nss-nss-3-21-release-notes`, or a later release.)
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_19_2_2_RTM. NSS 3.19.2.2 requires NSPR 4.10.10 or newer.

NSS 3.19.2.2 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_19_2_2_RTM/src/>
:::

(security-fixes-in-nss-3-19-2-2)=

## Security Fixes in NSS 3.19.2.2

:::{container}

- [Bug 1158489](https://bugzilla.mozilla.org/show_bug.cgi?id=1158489)
  \` \<<https://bugzilla.mozilla.org/show_bug.cgi?id=1138554>>\`\_\_ /
  [CVE-2015-7575](http://www.cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2015-7575) - Prevent
  MD5 Downgrade in TLS 1.2 Signatures.
:::

(new-in-nss-3-19-2-2)=

## New in NSS 3.19.2.2

### New Functionality

:::{container}
No new functionality is introduced in this release.
:::

## Acknowledgements

:::{container}
The NSS development team would like to thank Karthikeyan Bhargavan from
[INRIA](http://inria.fr/) for responsibly disclosing the issue in [Bug
1158489](https://bugzilla.mozilla.org/show_bug.cgi?id=1158489).
:::

## Compatibility

:::{container}
NSS 3.19.2.2 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.19.2.2 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
