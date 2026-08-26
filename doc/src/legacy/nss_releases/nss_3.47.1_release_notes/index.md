(mozilla-projects-nss-nss-3-47-1-release-notes)=

# NSS 3.47.1 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.47.1 is a patch release for NSS 3.47. The bug fixes in NSS
3.47.1 are described in the "Bugs Fixed" section below. It was released on 19 November 2019.

The NSS team would like to recognize first-time contributors:

- Craig Disselkoen
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_47_1_RTM. NSS 3.47.1 requires NSPR 4.23 or newer.

NSS 3.47.1 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_47_1_RTM/src/>

Other releases are available in NSS Releases.
:::

(new-in-nss-3-47-1)=

## New in NSS 3.47.1

:::{container}
No new functionality is introduced in this release.
:::

(bugs-fixed-in-nss-3-47-1)=

## Bugs fixed in NSS 3.47.1

:::{container}

- [CVE-2019-11745](https://bugzilla.mozilla.org/show_bug.cgi?id=CVE-2019-11745) -
  EncryptUpdate should use maxout, not block size
- [Bug 1590495](https://bugzilla.mozilla.org/show_bug.cgi?id=1590495) - Fix a crash that
  could be caused by client certificates during startup
- [Bug 1589810](https://bugzilla.mozilla.org/show_bug.cgi?id=1589810) - Fix compile-time
  warnings from uninitialized variables in a perl script

This Bugzilla query returns all the bugs fixed in NSS 3.47:

<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&product=NSS&target_milestone=3.47>
:::

## Compatibility

:::{container}
NSS 3.47.1 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.47.1 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
