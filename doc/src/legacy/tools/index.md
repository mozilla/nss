(mozilla-projects-nss-tools)=

# NSS Tools

(nss-security-tools)=

## NSS Security Tools

:::{container}
Newsgroup: [mozilla.dev.tech.crypto](news://news.mozilla.org/mozilla.dev.tech.crypto)
:::

### Overview

:::{container}
The NSS Security Tools allow developers to test, debug, and manage applications that use NSS. The
[Tools Information](#tools) table below describes both the tools that are currently working
and those that are still under development. The links for each tool take you to the source code,
documentation, plans, and related links for each tool. The links will become active when
information is available.

Currently, you must download the NSS 3.1 source and build it to create binary files for the NSS
tools. For information about downloading the NSS source, see
{ref}`mozilla-projects-nss-building`.

If you have feedback or questions, please feel free to post to
[mozilla.dev.tech.crypto](news://news.mozilla.org/mozilla.dev.tech.crypto). This newsgroup is
the preferred forum for all questions about NSS and NSS tools.
:::

(overall-objectives)=

### Overall Objectives

:::{container}

1. Provide a tool for analyzing and repairing certificate databases ([dbck](#dbck)).
2. Migrate tools from secutil.h interface to PKCS #11 interface.
3. Eliminate redundant functionality in tools. Many tools implement private versions of
   PKCS11Init(), OpenCertDB(), etc.
4. Eliminate use of getopt() and replace with NSPR calls to get command options (to eliminate
   platform dependencies with getopt()).
:::

(tools-information)=

### Tools information

:::{container}

```{eval-rst}
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| **Tool**     | **Description**                         | **Links**                                                                                                                                                                                                                        |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| certutil 2.0 | Manage certificate and key databases    | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/certutil/>`__, :ref:`mozilla-projects-nss-tools-certutil`, :ref:`mozilla-projects-nss-tools-nss-tools-certutil-tasks`                                           |
|              | (cert7.db and key3.db).                 |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| cmsutil 1.0  | Performs basic CMS operations such as   | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/smimetools/>`__, :ref:`mozilla-projects-nss-tools-cmsutil`                                                                                                      |
|              | encrypting, decrypting, and signing     |                                                                                                                                                                                                                                  |
|              | messages.                               |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| crlutil      | Manage certificate revocation lists     | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/crlutil/>`__, :ref:`mozilla-projects-nss-tools-crlutil`,                                                                                                        |
|              | (CRLs).                                 |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| dbck 1.0     | Analyze and repair certificate          | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/dbck/>`__, :ref:`mozilla-projects-nss-tools-nss-tools-dbck-tasks`                                                                                               |
|              | databases (not working in NSS 3.2)      |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| modutil 1.1  | Manage the database of PKCS11 modules   | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/modutil/>`__, :ref:`mozilla-projects-nss-tools-modutil`, :ref:`mozilla-projects-nss-tools-nss-tools-modutil-tasks`                                              |
|              | (secmod.db). Add modules and modify the |                                                                                                                                                                                                                                  |
|              | properties of existing modules (such as |                                                                                                                                                                                                                                  |
|              | whether a module is the default         |                                                                                                                                                                                                                                  |
|              | provider of some crypto service).       |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| pk12util 1.0 | Import and export keys and certificates | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/pk12util/>`__, :ref:`mozilla-projects-nss-tools-pk12util`, :ref:`mozilla-projects-nss-tools-nss-tools-pk12util-tasks`                                           |
|              | between the cert/key databases and      |                                                                                                                                                                                                                                  |
|              | files in PKCS12 format.                 |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| signtool 1.3 | Create digitally-signed jar archives    | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/signtool/>`__, `Documentation <https://docs.oracle.com/javase/8/docs/technotes/guides/security/SecurityToolsSummary.html#jarsigner>`__,                         |
|              | containing files and/or code.           |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| signver 1.1  | Verify signatures on digitally-signed   | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/signver/>`__, `Documentation <https://docs.oracle.com/javase/tutorial/deployment/jar/verify.html>`__, :ref:`mozilla-projects-nss-tools-nss-tools-signver-tasks` |
|              | objects.                                |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| sslstrength  | SSL Strength                            | :ref:`mozilla-projects-nss-nss-tools-sslstrength`                                                                                                                                                                                |
|              |                                         |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| ssltap 3.2   | Proxy requests for an SSL server and    | `Source <https://dxr.mozilla.org/mozilla/source/security/nss/cmd/ssltap/>`__, :ref:`mozilla-projects-nss-tools-ssltap`                                                                                                           |
|              | display the contents of the messages    |                                                                                                                                                                                                                                  |
|              | exchanged between the client and        |                                                                                                                                                                                                                                  |
|              | server. The ssltap tool does not        |                                                                                                                                                                                                                                  |
|              | decrypt data, but it shows things like  |                                                                                                                                                                                                                                  |
|              | the type of SSL message (clientHello,   |                                                                                                                                                                                                                                  |
|              | serverHello, etc) and connection data   |                                                                                                                                                                                                                                  |
|              | (protocol version, cipher suite, etc).  |                                                                                                                                                                                                                                  |
|              | This tool is very useful for debugging. |                                                                                                                                                                                                                                  |
+--------------+-----------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
```

:::
