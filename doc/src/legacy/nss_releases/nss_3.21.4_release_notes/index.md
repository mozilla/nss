(mozilla-projects-nss-nss-3-21-4-release-notes)=

# NSS 3.21.4 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.21.4 is a security patch release for NSS 3.21. The bug fixes in
NSS 3.21.4 are described in the "Bugs Fixed" section below.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_21_4_RTM. NSS 3.21.4 requires NSPR 4.12 or newer.

NSS 3.21.4 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_21_4_RTM/src/>
:::

(new-in-nss-3-21-4)=

## New in NSS 3.21.4

:::{container}
No new functionality is introduced in this release.
:::

(bugs-fixed-in-nss-3-21-4)=

## Bugs fixed in NSS 3.21.4

:::{container}

- [Bug 1344380](https://bugzilla.mozilla.org/show_bug.cgi?id=1344380) / Out-of-bounds write
  in Base64 encoding in NSS
  ([CVE-2017-5461](https://www.mozilla.org/en-US/security/advisories/mfsa2017-10/#CVE-2017-5461))
- [Bug 1345089](https://bugzilla.mozilla.org/show_bug.cgi?id=1345089) / DRBG flaw in NSS
  ([CVE-2017-5462](https://www.mozilla.org/en-US/security/advisories/mfsa2017-10/#CVE-2017-5462))
:::

## Acknowledgements

:::{container}
The NSS development team would like to thank Ronald Crane and Vladimir Klebanov for responsibly
disclosing the issues by providing advance copies of their research.
:::

## Compatibility

:::{container}
NSS 3.21.4 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.21.4 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
