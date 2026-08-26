(mozilla-projects-nss-nss-third-party-code)=

# NSS Third-Party Code

:::{container}
This is a list of third-party code included in the NSS repository, broken into two lists: Code
that can be compiled into the NSS libraries, and code that is only used for testing.

Note that not all code that can be compiled into the NSS libraries necessarily *is*. Often this
is configurable at build time, with various trade-offs.
:::

(compiled-in)=

## Compiled In

:::{container}

- sqlite [/lib/sqlite]
- BerkleyDB [/lib/dbm]
- zlib [/lib/zlib]
- libjar [/lib/jar]
- Fiat-Crypto, Ring [lib/freebl/ecl]
:::

(used-for-tests)=

## Used for Tests

:::{container}

- GTest [/gtests]
:::

(downloaded-by-certain-test-tooling)=

### Downloaded by certain test tooling

:::{container}

- TLSFuzzer [/tests/tlsfuzzer]
- BoGo tests [/tests/bogo]
- BoringSSL, OpenSSL [/tests/interop]
:::
