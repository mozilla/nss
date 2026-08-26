(mozilla-projects-nss-nss-3-15-3-release-notes)=

# NSS 3.15.3 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.15.3 is a patch release for NSS 3.15. The bug fixes in NSS
3.15.3 are described in the "Bugs Fixed" section below.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_15_3_RTM. NSS 3.15.3 requires NSPR 4.10.2 or newer.

NSS 3.15.3 source distributions are also available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_15_3_RTM/src/>
:::

## Security Advisories

:::{container}
The following security-relevant bugs have been resolved in NSS 3.15.3. Users are encouraged to
upgrade immediately.

- [Bug 925100](https://bugzilla.mozilla.org/show_bug.cgi?id=925100) - (CVE-2013-1741) Ensure
  a size is \<= half of the maximum PRUint32 value
- [Bug 934016](https://bugzilla.mozilla.org/show_bug.cgi?id=934016) - (CVE-2013-5605) Handle
  invalid handshake packets
- [Bug 910438](https://bugzilla.mozilla.org/show_bug.cgi?id=910438) - (CVE-2013-5606) Return
  the correct result in CERT_VerifyCert on failure, if a verifyLog isn't used
:::

(new-in-nss-3-15-3)=

## New in NSS 3.15.3

### New Functionality

:::{container}
No new major functionality is introduced in this release. This release is a patch release to
address [CVE-2013-1741](http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2013-1741),
[CVE-](http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2013-5605)[2013-5605](http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2013-5605)
and [CVE-2013-5606](http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2013-5606).
:::

(bugs-fixed-in-nss-3-15-3)=

### Bugs fixed in NSS 3.15.3

:::{container}

- [Bug 850478](https://bugzilla.mozilla.org/show_bug.cgi?id=850478) - List RC4_128 cipher
  suites after AES_128 cipher suites
- [Bug 919677](https://bugzilla.mozilla.org/show_bug.cgi?id=919677) - Don't advertise TLS
  1.2-only ciphersuites in a TLS 1.1 ClientHello

A complete list of all bugs resolved in this release can be obtained at
<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&target_milestone=3.15.3&product=NSS>
:::

## Compatibility

:::{container}
NSS 3.15.3 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.15.3 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
