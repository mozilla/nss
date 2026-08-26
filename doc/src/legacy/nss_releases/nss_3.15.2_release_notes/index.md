(mozilla-projects-nss-nss-3-15-2-release-notes)=

# NSS 3.15.2 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.15.2 is a patch release for NSS 3.15. The bug fixes in NSS
3.15.2 are described in the "Bugs Fixed" section below.
:::

## Distribution Information

:::{container}
NSS 3.15.2 source distributions are also available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_15_2_RTM/src/>
:::

## Security Advisories

:::{container}
The following security-relevant bugs have been resolved in NSS 3.15.2. Users are encouraged to
upgrade immediately.

- [Bug 894370](https://bugzilla.mozilla.org/show_bug.cgi?id=894370) - (CVE-2013-1739) Avoid
  uninitialized data read in the event of a decryption failure.
:::

(new-in-nss-3-15-2)=

## New in NSS 3.15.2

### New Functionality

:::{container}

- AES-GCM Ciphersuites: AES-GCM cipher suite (RFC 5288 and RFC 5289) support has been added when
  TLS 1.2 is negotiated. Specifically, the following cipher suites are now supported:

  - TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
  - TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
  - TLS_DHE_RSA_WITH_AES_128_GCM_SHA256
  - TLS_RSA_WITH_AES_128_GCM_SHA256

```{rubric} New Functions
```

PK11_CipherFinal has been introduced, which is a simple alias for PK11_DigestFinal.

```{rubric} New Types
```

No new types have been introduced.

```{rubric} New PKCS #11 Mechanisms
```

No new PKCS#11 mechanisms have been introduced
:::

(notable-changes-in-nss-3-15-2)=

### Notable Changes in NSS 3.15.2

:::{container}

- [Bug 880543](https://bugzilla.mozilla.org/show_bug.cgi?id=880543) - Support for AES-GCM
  ciphersuites that use the SHA-256 PRF
- [Bug 663313](https://bugzilla.mozilla.org/show_bug.cgi?id=663313) - MD2, MD4, and MD5
  signatures are no longer accepted for OCSP or CRLs, consistent with their handling for general
  certificate signatures.
- [Bug 884178](https://bugzilla.mozilla.org/show_bug.cgi?id=884178) - Add PK11_CipherFinal
  macro
:::

(bugs-fixed-in-nss-3-15-2)=

### Bugs fixed in NSS 3.15.2

:::{container}

- [Bug 734007](https://bugzilla.mozilla.org/show_bug.cgi?id=734007) - sizeof() used
  incorrectly
- [Bug 900971](https://bugzilla.mozilla.org/show_bug.cgi?id=900971) - nssutil_ReadSecmodDB()
  leaks memory
- [Bug 681839](https://bugzilla.mozilla.org/show_bug.cgi?id=681839) - Allow
  SSL_HandshakeNegotiatedExtension to be called before the handshake is finished.
- [Bug 848384](https://bugzilla.mozilla.org/show_bug.cgi?id=848384) - Deprecate the SSL
  cipher policy code, as it's no longer relevant. It is no longer necessary to call
  NSS_SetDomesticPolicy because all cipher suites are now allowed by default.

A complete list of all bugs resolved in this release can be obtained at
<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&target_milestone=3.15.2&product=NSS&list_id=7982238>
:::

## Compatibility

:::{container}
NSS 3.15.2 shared libraries are backward compatible with all older NSS 3.x shared libraries. A
program linked with older NSS 3.x shared libraries will work with NSS 3.15.2 shared libraries
without recompiling or relinking. Furthermore, applications that restrict their use of NSS APIs
to the functions listed in NSS Public Functions will remain compatible with future versions of
the NSS shared libraries.
:::

## Feedback

:::{container}
Bugs discovered should be reported by filing a bug report with
[bugzilla.mozilla.org](https://bugzilla.mozilla.org/enter_bug.cgi?product=NSS) (product NSS).
:::
