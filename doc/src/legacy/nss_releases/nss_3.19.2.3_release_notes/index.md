(mozilla-projects-nss-nss-3-19-2-3-release-notes)=

# NSS 3.19.2.3 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.19.2.3 is a security patch release for NSS 3.19.2. The bug
fixes in NSS 3.19.2.3 are described in the "Security Fixes" section below.

(Current users of NSS 3.19.3, NSS 3.19.4 or NSS 3.20.x are advised to update to
{ref}`mozilla-projects-nss-nss-3-21-1-release-notes`,
{ref}`mozilla-projects-nss-nss-3-22-2-release-notes`, or a later release.)
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_19_2_3_RTM. NSS 3.19.2.3 requires NSPR 4.10.10 or newer.

NSS 3.19.2.3 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_19_2_3_RTM/src/>
:::

(new-in-nss-3-19-2-3)=

## New in NSS 3.19.2.3

### New Functionality

:::{container}
No new functionality is introduced in this release.
:::

(security-fixes-in-nss-3-19-2-3)=

## Security Fixes in NSS 3.19.2.3

:::{container}

- [Bug 1245528](https://bugzilla.mozilla.org/show_bug.cgi?id=1245528) /
  [CVE-2016-1950](http://www.cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2016-1950) - Fixed a
  heap-based buffer overflow related to the parsing of certain ASN.1 structures. An attacker
  could create a specially-crafted certificate which, when parsed by NSS, would cause a crash or
  execution of arbitrary code with the permissions of the user.
:::

## Acknowledgements

:::{container}
The NSS development team would like to thank security researcher Francis Gabriel for responsibly
disclosing the issue in [Bug 1245528](https://bugzilla.mozilla.org/show_bug.cgi?id=1245528).
:::

## Compatibility

:::{container}
NSS 3.19.2.3 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.19.2.3 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
