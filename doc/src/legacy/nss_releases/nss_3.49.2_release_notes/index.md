(mozilla-projects-nss-nss-3-49-2-release-notes)=

# NSS 3.49.2 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.49.2 is a patch release for NSS 3.49. The bug fixes in NSS
3.49.2 are described in the "Bugs Fixed" section below. It was released on **23 January 2020**.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_49_2_RTM. NSS 3.49.2 requires NSPR 4.24 or newer.

NSS 3.49.2 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_49_2_RTM/src/>

Other releases are available in {ref}`mozilla-projects-nss-nss-releases`.
:::

(new-in-nss-3-49-2)=

## New in NSS 3.49.2

:::{container}
No new functionality is introduced in this release.
:::

(bugs-fixed-in-nss-3-49-2)=

## Bugs fixed in NSS 3.49.2

:::{container}

- [Bug 1606992](https://bugzilla.mozilla.org/show_bug.cgi?id=1606992) - Cache the most
  recent PBKDF1 password hash, to speed up repeated SDR operations, important with the increased
  KDF iteration counts. NSS 3.49.1 sped up PBKDF2 operations, though PBKDF1 operations are also
  relevant for older NSS databases.
- [Bug 1608327](https://bugzilla.mozilla.org/show_bug.cgi?id=1608327) - Fix compilation
  problems with NEON-specific code in freebl
- [Bug 1608895](https://bugzilla.mozilla.org/show_bug.cgi?id=1608895) - Fix a taskcluster
  issue with Python 2 / Python 3

This Bugzilla query returns all the bugs fixed in NSS 3.49:

<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&product=NSS&target_milestone=3.49>
:::

## Compatibility

:::{container}
NSS 3.49.2 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.49.2 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
