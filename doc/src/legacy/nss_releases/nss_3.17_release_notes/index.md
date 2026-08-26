(mozilla-projects-nss-nss-3-17-release-notes)=

# NSS 3.17 release notes

## Introduction

:::{container}
The NSS team has released Network Security Services (NSS) 3.17, which is a minor release.
:::

## Distribution Information

:::{container}
The HG tag is NSS_3_17_RTM. NSS 3.17 requires NSPR 4.10.7 or newer.

NSS 3.17 source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_3_17_RTM/src/>
:::

(new-in-nss-3-17)=

## New in NSS 3.17

### New Functionality

:::{container}

- When using ECDHE, the TLS server code may be configured to generate a fresh ephemeral ECDH key
  for each handshake, by setting the SSL_REUSE_SERVER_ECDHE_KEY socket option to PR_FALSE. The
  SSL_REUSE_SERVER_ECDHE_KEY option defaults to PR_TRUE, which means the server's ephemeral ECDH
  key is reused for multiple handshakes. This option does not affect the TLS client code, which
  always generates a fresh ephemeral ECDH key for each handshake.

New Macros

- *in ssl.h*

  - **SSL_REUSE_SERVER_ECDHE_KEY**
:::

(notable-changes-in-nss-3-17)=

## Notable Changes in NSS 3.17

:::{container}

- The manual pages for the certutil and pp tools have been updated to document the new
  parameters that had been added in NSS 3.16.2.
- On Windows, the new build variable USE_STATIC_RTL can be used to specify the static C runtime
  library should be used. By default the dynamic C runtime library is used.
:::

(bugs-fixed-in-nss-3-17)=

## Bugs fixed in NSS 3.17

:::{container}
This Bugzilla query returns all the bugs fixed in NSS 3.17:

<https://bugzilla.mozilla.org/buglist.cgi?resolution=FIXED&classification=Components&query_format=advanced&product=NSS&target_milestone=3.17>
:::
