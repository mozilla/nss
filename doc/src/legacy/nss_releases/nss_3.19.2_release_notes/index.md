(mozilla-projects-nss-nss-3-19-2-release-notes)=

# NSS 3.19.2 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.19.2 is a patch release for NSS 3.19 that addresses
compatibility issues in NSS 3.19.1.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_19_2_RTM. NSS 3.19.2 requires NSPR 4.10.8 or newer.

NSS 3.19.2 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_19_2_RTM/src/>
:::

(new-in-nss-3-19-2)=

## New in NSS 3.19.2

### New Functionality

:::{container}
No new functionality is introduced in this release.
:::

(notable-changes-in-nss-3-19-2)=

## Notable Changes in NSS 3.19.2

:::{container}

- [Bug 1172128](https://bugzilla.mozilla.org/show_bug.cgi?id=1172128) - In NSS 3.19.1, the
  minimum key sizes that the freebl cryptographic implementation (part of the softoken
  cryptographic module used by default by NSS) was willing to generate or use was increased -
  for RSA keys, to 512 bits, and for DH keys, 1023 bits. This was done as part of a security fix
  for [Bug 1138554](https://bugzilla.mozilla.org/show_bug.cgi?id=1138554) /
  [CVE-2015-4000](http://www.cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2015-4000).
  Applications that requested or attempted to use keys smaller then the minimum size would fail.
  However, this change in behaviour unintentionally broke existing NSS applications that need to
  generate or use such keys, via APIs such as SECKEY_CreateRSAPrivateKey or
  SECKEY_CreateDHPrivateKey.
  In NSS 3.19.2, this change in freebl behaviour has been reverted. The fix for [Bug
  1138554](https://bugzilla.mozilla.org/show_bug.cgi?id=1138554) has been moved to libssl,
  and will now only affect the minimum keystrengths used in SSL/TLS.
  **Note:** Future versions of NSS *may* increase the minimum keysizes required by the freebl
  module. Consumers of NSS are **strongly** encouraged to migrate to stronger cryptographic
  strengths as soon as possible.
:::

(bugs-fixed-in-nss-3-19-2)=

## Bugs fixed in NSS 3.19.2

:::{container}
This Bugzilla query returns all the bugs fixed in NSS 3.19.2:

<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&product=NSS&target_milestone=3.19.2>
:::

## Compatibility

:::{container}
NSS 3.19.2 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.19.2 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
