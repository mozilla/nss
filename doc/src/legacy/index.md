---
orphan: true
---

(mozilla-projects-nss-legacy-index)=

# Legacy documentation

```{eval-rst}
.. toctree::
   :maxdepth: 2
   :glob:
   :hidden:

   introduction_to_network_security_services/index.md
   More documentation <more_docs>
```

:::{warning}
This NSS documentation was just imported from our legacy MDN repository. It currently is very deprecated and likely incorrect or broken in many places.
:::

## Legacy Documentation

:::{container}
**Network Security Services** (**NSS**) is a set of libraries designed to support cross-platform
development of security-enabled client and server applications. Applications built with NSS can
support SSL v3, TLS, PKCS #5, PKCS #7, PKCS #11, PKCS #12, S/MIME, X.509 v3 certificates, and
other security standards.

For detailed information on standards supported, see {ref}`mozilla-projects-nss-overview`. For a
list of frequently asked questions, see the {ref}`mozilla-projects-nss-faq`.

NSS is available under the Mozilla Public License. For information on downloading NSS releases as
tar files, see {ref}`mozilla-projects-nss-nss-sources-building-testing`.

If you're a developer and would like to contribute to NSS, you might want to read the document
{ref}`mozilla-projects-nss-an-overview-of-nss-internals`.

```{rubric} Background Information
:name: Background_Information
```

{ref}`mozilla-projects-nss-overview`

: Provides a brief summary of NSS and its capabilities.

{ref}`mozilla-projects-nss-faq`

: Answers basic questions about NSS.

[Introduction to Public-Key Cryptography](https://developer.mozilla.org/en-US/docs/Archive/Security/Introduction_to_Public-Key_Cryptography)

: Explains the basic concepts of public-key cryptography that underlie NSS.

[Introduction to SSL](https://developer.mozilla.org/en-US/docs/Archive/Security/Introduction_to_SSL)

: Introduces the SSL protocol, including information about cryptographic ciphers supported by
  SSL and the steps involved in the SSL handshake.

```{rubric} Getting Started
```

{ref}`mozilla-projects-nss-nss-releases`

: This page contains information about the current and past releases of NSS.

{ref}`mozilla-projects-nss-nss-sources-building-testing`

: Instructions on how to build NSS on the different supported platforms.

[Get Mozilla Source Code Using Mercurial](https://developer.mozilla.org/en-US/docs/Mozilla/Developer_guide/Source_Code/Mercurial)

: Information about with working with Mercurial.

[Get Mozilla Source Code Using CVS (deprecated)](https://developer.mozilla.org/en-US/docs/Mozilla/Developer_guide/Source_Code/CVS)

: Old deprecated CVS documentation.

```{rubric} NSS APIs
:name: NSS_APIs
```

{ref}`mozilla-projects-nss-introduction-to-network-security-services`

: Provides an overview of the NSS libraries and what you need to know to use them.

{ref}`mozilla-projects-nss-ssl-functions`

: Summarizes the SSL APIs exported by the NSS shared libraries.

{ref}`mozilla-projects-nss-reference`

: API used to invoke SSL operations.

{ref}`mozilla-projects-nss-nss-api-guidelines`

: Explains how the libraries and code are organized, and guidelines for developing code (naming
  conventions, error handling, thread safety, etc.)

{ref}`mozilla-projects-nss-nss-tech-notes`

: Links to NSS technical notes, which provide latest information about new NSS features and
  supplementary documentation for advanced topics in programming with NSS.

```{rubric} Tools, testing, and other technical details
:name: Tools_testing_and_other_technical_details
```

{ref}`mozilla-projects-nss-building`

: Describe how to check out and build NSS releases.

{ref}`mozilla-projects-nss-nss-developer-tutorial`

: How to make changes in NSS. Coding style, maintaining ABI compatibility.

{ref}`mozilla-projects-nss-tools`

: Tools for developing, debugging, and managing applications that use NSS.

{ref}`mozilla-projects-nss-nss-sample-code`

: Demonstrates how NSS can be used for cryptographic operations, certificate handling, SSL, etc.

{ref}`mozilla-projects-nss-nss-third-party-code`

: A list of third-party code included in the NSS library.

[NSS 3.2 Test Suite](https://www-archive.mozilla.org/projects/security/pki/nss/testnss_32.html)

: **Archived version.** Describes how to run the standard NSS tests.

[NSS Performance Reports](https://www-archive.mozilla.org/projects/security/pki/nss/performance_reports.html)

: **Archived version.** Links to performance reports for NSS 3.2 and later releases.

[Encryption Technologies Available in NSS 3.11](https://www-archive.mozilla.org/projects/security/pki/nss/nss-3.11/nss-3.11-algorithms.html)

: **Archived version.** Lists the cryptographic algorithms used by NSS 3.11.

[NSS 3.1 Loadable Root Certificates](https://www-archive.mozilla.org/projects/security/pki/nss/loadable_certs.html)

: **Archived version.** Describes the scheme for loading root CA certificates.

[cert7.db](https://www-archive.mozilla.org/projects/security/pki/nss/db_formats.html)

: **Archived version.** General format of the cert7.db database.

```{rubric} PKCS #11 information
:name: PKCS_11_information
```

- {ref}`mozilla-projects-nss-pkcs11`
- {ref}`mozilla-projects-nss-pkcs11-implement`
- {ref}`mozilla-projects-nss-pkcs11-module-specs`
- {ref}`mozilla-projects-nss-pkcs11-faq`
- [Using the JAR Installation Manager to Install a PKCS #11 Cryptographic
  Module](https://developer.mozilla.org/en-US/docs/PKCS11_Jar_Install)
- [PKCS #11 Conformance Testing - Archived
  version](https://www-archive.mozilla.org/projects/security/pki/pkcs11/)

```{rubric} CA certificates pre-loaded into NSS
:name: CA_certificates_pre-loaded_into_NSS
```

- [Mozilla CA certificate policy](https://www.mozilla.org/projects/security/certs/policy/)

- [List of pre-loaded CA certificates](https://wiki.mozilla.org/CA/Included_Certificates)

  - Consumers of this list must consider the trust bit setting for each included root
    certificate. [More
    Information](https://www.imperialviolet.org/2012/01/30/mozillaroots.html), [Extracting
    roots and their trust bits](https://github.com/agl/extract-nss-root-certs)

```{rubric} NSS is built on top of Netscape Portable Runtime (NSPR)
:name: NSS_is_built_on_top_of_Netscape_Portable_Runtime_NSPR
```

[Netscape Portable Runtime](NSPR)

: NSPR project page.

[NSPR Reference](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSPR/Reference)

: NSPR API documentation.

```{rubric} Additional Information
:name: Additional_Information
```

- [Using the window.crypto object from
  JavaScript](https://developer.mozilla.org/en-US/docs/JavaScript_crypto)
- {ref}`mozilla-projects-nss-http-delegation`
- {ref}`mozilla-projects-nss-tls-cipher-suite-discovery`
- {ref}`mozilla-projects-nss-certificate-download-specification`
- {ref}`mozilla_projects_nss_fips_mode_-_an_explanation`
- {ref}`mozilla-projects-nss-key-log-format`

```{rubric} Planning
:name: Planning
```

Information on NSS planning can be found at [wiki.mozilla.org](https://wiki.mozilla.org/NSS),
including:

- [FIPS Validation](https://wiki.mozilla.org/FIPS_Validation)
- [NSS Roadmap page](https://wiki.mozilla.org/NSS:Roadmap)
- [NSS Improvement
  Project](https://fedoraproject.org/wiki/User:Mitr/NSS:DeveloperFriendliness)
:::

### Community

- View Mozilla Security forums...
- [Mailing list](https://lists.mozilla.org/listinfo/dev-security)
- [Newsgroup](http://groups.google.com/group/mozilla.dev.security)
- [RSS feed](http://groups.google.com/group/mozilla.dev.security/feeds)
- View Mozilla Cryptography forums...
- [Mailing list](https://lists.mozilla.org/listinfo/dev-tech-crypto)
- [Newsgroup](http://groups.google.com/group/mozilla.dev.tech.crypto)
- [RSS feed](http://groups.google.com/group/mozilla.dev.tech.crypto/feeds)

### Related Topics

- [Security](https://developer.mozilla.org/en-US/docs/Security)
