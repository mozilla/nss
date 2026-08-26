(mozilla-projects-nss-faq)=

# NSS FAQ

## General Questions

(what-is-network-security-services-28nss-29)=

### What is Network Security Services (NSS)

:::{container}
NSS is set of libraries, APIs, utilities, and documentation designed to support cross-platform
development of security-enabled client and server applications. It provides a complete
open-source implementation of the crypto libraries used by Mozilla and other companies in the
Firefox browser, AOL Instant Messenger (AIM), server products from Red Hat, and other products.

For an overview of NSS, see {ref}`mozilla-projects-nss-overview`. For detailed information on the
open-source NSS project, see [NSS Project Page](https://wiki.mozilla.org/NSS).
:::

(what-can-i-do-with-nss-3f-is-nss-appropriate-for-my-application-3f)=

### What can I do with NSS? Is NSS appropriate for my application?

:::{container}
If you want add support for SSL, S/MIME, or other Internet security standards to your
application, you can use Network Security Services (NSS) to do so. Because NSS provides complete
support for all versions of SSL and TLS, it is particularly well-suited for applications that
need to communicate with the many clients and servers that already support the SSL protocol.

The PKCS #11 interface included in NSS means that your application can use [hardware
accelerators](#what_hardware_accelerators_are_supported.3f) on the server and
{ref}`mozilla_projects_nss_faq#how_do_i_integrate_smart_cards_into_my_application_using_nss_3f`
for two-factor authentication.
:::

(how-does-nss-compare-to-openssl-3f)=

### How does NSS compare to OpenSSL?

:::{container}
[OpenSSL](https://www.openssl.org/) is an open source project that implements server-side SSL,
TLS, and a general-purpose cryptography library. It does not support PKCS #11. It is based on the
SSLeay library developed by Eric A. Young and Tim J. Hudson. OpenSSL is widely used in Apache
servers and is licensed under an Apache-style licence.

NSS supports both server and client applications as well as
{ref}`mozilla-projects-nss-pkcs11-faq` and S/MIME. To permit its use in as many contexts as
possible, NSS is licensed under the [Mozilla Public License](https://www.mozilla.org/MPL/),
version 2.
:::

(how-does-nss-compare-to-sslref-3f)=

### How does NSS compare to SSLRef?

:::{container}
SSLRef was an early reference implementation of the SSL protocol. It contains bugs that were
never fixed, doesn't support TLS or the new 56-bit export cipher suites, and does not contain the
fix to the Bleichenbacher attack on PKCS#1.

Netscape no longer maintains SSLRef or makes it available. It was built as an example of an SSL
implementation, not for creating production applications.

NSS was designed from the ground up for use by commercial developers. It provides a complete
software development kit that uses the same architecture used to support security features in
many client and server products from Netscape and other companies.
:::

(what-platforms-and-development-environments-are-supported-3f)=

### What platforms and development environments are supported?

::::{container}

:::{warning}
This section is out of date
:::

iPlanet E-Commerce Solutions has certified NSS 3.1 on 18 platforms, including AIX 4.3, HP-UX
11.0, Red Hat Linux 6.0, Solaris (2.6 or later), Windows NT (4.0 or later), and Windows 2000.
Other contributors are in the process of certifying additional platforms. The NSS 3.1 API
requires C or C++ development environments.

For the latest NSS release notes and detailed platform information, see [Project
Information](https://wiki.mozilla.org/NSS).
::::

(what-cryptography-standards-are-supported-3f)=

### What cryptography standards are supported?

:::{container}
NSS supports [SSL v2 and v3](https://developer.mozilla.org/en-US/docs/Glossary/SSL),
[TLS](https://developer.mozilla.org/en-US/docs/Glossary/TLS), [PKCS
\# 5](https://developer.mozilla.org/en-US/docs/Glossary/PKCS_.235), [PKCS
\# 7](https://developer.mozilla.org/en-US/docs/Glossary/PKCS_.237), [PKCS
\# 11](https://developer.mozilla.org/en-US/docs/Glossary/PKCS_.2311), [PKCS
\# 12](https://developer.mozilla.org/en-US/docs/Glossary/PKCS_.2312),
[S/MIME](https://developer.mozilla.org/en-US/Glossary/en-US/docs/Glossary/S.2FMIME), and
[X.509 v3](https://developer.mozilla.org/en-US/docs/Mozilla/Security/x509_Certificates)
certificates. For complete details, see [Encryption Technologies Available in NSS
3.11](http://www-archive.mozilla.org/projects/security/pki/nss/nss-3.11/nss-3.11-algorithms.html)
:::

(what-is-the-relationship-between-nss-and-psm-3f)=

### What is the relationship between NSS and PSM?

:::{container}
Personal Security Manager (PSM) is built on top of NSS. It consists of libraries and a daemon
designed to support cross-platform development of security-enabled client applications. The PSM
binary provides a client module that performs cryptographic operations on behalf of applications.
Netscape Personal Security Manager ships with Netscape 6 and the Gateway Connected Touch Pad with
Instant AOL, and is also available for use with Communicator 4.7x.
:::

(where-can-i-get-the-source-3f)=

### Where can I get the source?

:::{container}
For instructions on how to check out and build the NSS source code, see
{ref}`mozilla-projects-nss-nss-sources-building-testing`.
:::

(how-much-does-it-cost-3f)=

### How much does it cost?

:::{container}
NSS source code and binaries (when they become available) are completely free. No license fees,
no royalty fees, no subscription fees.
:::

(developer-questions)=

## Developer Questions

(what-hardware-accelerators-are-supported-3f)=

### What hardware accelerators are supported?

:::{container}
NSS supports the PKCS #11 interface for hardware acceleration. Since leading accelerator vendors
such as Chrysalis-IT, nCipher, and Rainbow Technologies also support this interface, NSS-enabled
applications can support a wide variety of hardware accelerators.
:::

(how-do-i-integrate-smart-cards-into-my-application-using-nss-3f)=

### How do I integrate smart cards into my application using NSS?

:::{container}
NSS supports the PKCS #11 interface for smart card integration. Applications that use the PKCS
\# 11 interface provided by NSS will therefore support smart cards from leading vendors such as
ActiveCard, Litronic, SafeNet, and SecureID Technologies that also support the PKCS #11
interface.
:::

(does-nss-require-netscape-portable-runtime-28nspr-29-3f)=

### Does NSS require Netscape Portable Runtime (NSPR)?

:::{container}

```{rubric} To provide cross-platform support, NSS utilizes Netscape Portable Runtime (NSPR) libraries as a portability interface and implementation that provides consistent cross-platform semantics for network I/O and threading models. You can use NSPR throughout your application or only in the portion that calls into NSS. Mozilla strongly recommends that multithreaded applications use the NSPR or native OS threading model. (In recent NSPR releases, the NSPR threading model is compatible with the native threading model if the OS has native threads.) Alternatively, you can adapt the open-source NSPR implementation to be compatible with your existing application's threading models. More information about NSPR may be found at [Netscape Portable Runtime](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSPR).
:name: to_provide_cross-platform_support_nss_utilizes_netscape_portable_runtime_nspr_libraries_as_a_portability_interface_and_implementation_that_provides_consistent_cross-platform_semantics_for_network_io_and_threading_models._you_can_use_nspr_throughout_your_application_or_only_in_the_portion_that_calls_into_nss._mozilla_strongly_recommends_that_multithreaded_applications_use_the_nspr_or_native_os_threading_model._in_recent_nspr_releases_the_nspr_threading_model_is_compatible_with_the_native_threading_model_if_the_os_has_native_threads._alternatively_you_can_adapt_the_open-source_nspr_implementation_to_be_compatible_with_your_existing_applications_threading_models._more_information_about_nspr_may_be_found_at_netscape_portable_runtime.
```

:::

(can-i-use-nss-even-if-my-application-protocol-isn-27t-http-3f)=

### Can I use NSS even if my application protocol isn't HTTP?

:::{container}
Yes, TLS is independent of application protocols. It works with common Internet standard
application protocols (HTTP, POP3, FTP, SMTP, etc.) as well as custom application protocols using
TCP/IP.
:::

(how-long-does-it-take-to-integrate-nss-into-my-application-3f)=

### How long does it take to integrate NSS into my application?

:::{container}
The integration effort depends on an number of factors, such as developer skill set, application
complexity, and the level of security required for your application. NSS includes detailed
documentation of the SSL API and sample code that demonstrates basic SSL functionality (setting
up an encrypted session, server authentication, and client authentication) to help jump start the
integration process. However, there is little or no documentation currently available for the
rest of the NSS API. If your application requires sophisticated certificate management, smart
card support, or hardware acceleration, your integration effort will be more extensive.
:::

(where-can-i-download-the-nss-tools-3f)=

### Where can I download the NSS tools?

:::{container}
Binary builds of NSS for several platforms including the command-line tools can be downloaded
from
[http://ftp.mozilla.org/pub/mozilla.o...y/nss/releases/](http://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/).
NSPR, which you will need as well, can be downloaded from
<http://ftp.mozilla.org/pub/mozilla.org/nspr/releases/>.
:::

(how-can-i-learn-more-about-ssl-3f)=

### [How can I learn more about TLS?](#how_can_i_learn_more_about_ssl.3f)

:::{container}
See <https://developer.mozilla.org/en-US/docs/Glossary/TLS>.
:::

(licensing-questions)=

## Licensing Questions

(how-is-nss-licensed-3f)=

### How is NSS licensed?

:::{container}
NSS is available under the [Mozilla Public License](https://www.mozilla.org/MPL/), version 2.
:::

(is-nss-available-outside-the-united-states-3f)=

### Is NSS available outside the United States?

::::{container}

:::{warning}
This section is out of date
:::

Yes; see [Build Instructions for NSS
3.1.](NSS_reference/Building_and_installing_NSS/Build_instructions) and
<ftp://ftp.mozilla.org/pub/mozilla.org/security/>. However, NSS source code is subject to the U.S.
Export Administration Regulations and other U.S. law, and may not be exported or re-exported to
certain countries (Cuba, Iran, Iraq, Libya, North Korea, Serbia, Sudan, Syria, and
Taleban-controlled areas of Afghanistan as of January 2000) or to persons or entities prohibited
from receiving U.S. exports (including those (a) on the Bureau of Industry and Security Denied
Parties List or Entity List, (b) on the Office of Foreign Assets Control list of Specially
Designated Nationals and Blocked Persons, and (c) involved with missile technology or nuclear,
chemical or biological weapons).

For more information about U.S. export controls on encryption software, see the [Mozilla Crypto
FAQ](Mozilla_Crypto_FAQ#1-3).
::::
