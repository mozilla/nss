(mozilla-projects-nss-nss-3-16-1-release-notes)=

# NSS 3.16.1 release notes

## Introduction

:::{container}
Network Security Services (NSS) 3.16.1 is a patch release for NSS 3.16. The bug fixes in NSS
3.16.1 are described in the "Bugs Fixed" section below.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_16_1_RTM. NSS 3.16.1 requires NSPR 4.10.5 or newer.

NSS 3.16.1 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_16_1_RTM/src/>
:::

(new-in-nss-3-16-1)=

## New in NSS 3.16.1

### New Functionality

:::{container}

- Added the "ECC" flag for modutil to select the module used for elliptic curve cryptography
  (ECC) operations.

```{rubric} New Functions
```

- *in pk11pub.h*

  - **PK11_ExportDERPrivateKeyInfo and PK11_ExportPrivKeyInfo** - exports a private key in a
    DER-encoded ASN.1 PrivateKeyInfo type or a SECKEYPrivateKeyInfo structure. Only RSA private
    keys are supported now.

- *in secmod.h*

  - **SECMOD_InternalToPubMechFlags** - converts from NSS-internal to public representation of
    mechanism flags.

```{rubric} New Types
```

- *in sslt.h*

  - **ssl_padding_xtn** - the value of this enum constant changed from the experimental value
    35655 to the IANA-assigned value 21. .

```{rubric} New Macros
```

- *in secmod.h*

  - **PUBLIC_MECH_ECC_FLAG** - a public mechanism flag for elliptic curve cryptography (ECC)
    operations.

- *in utilmodt.h*

  - **SECMOD_ECC_FLAG** - an NSS-internal mechanism flag for elliptic curve cryptography (ECC)
    operations. This macro has the same numeric value as **PUBLIC_MECH_ECC_FLAG.**
:::

(notable-changes-in-nss-3-16-1)=

## Notable Changes in NSS 3.16.1

:::{container}

- Imposed [name constraints](https://hg.mozilla.org/projects/nss/rev/742307da0792) on the
  French government root CA ANSSI (DCISS).
:::

(bugs-fixed-in-nss-3-16-1)=

## Bugs fixed in NSS 3.16.1

:::{container}
This Bugzilla query returns all the bugs fixed in NSS 3.16.1:

<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&product=NSS&target_milestone=3.16.1>
:::
