(mozilla-projects-nss-reference-nss-cryptographic-module-fips-mode-of-operation)=

# FIPS mode of operation

## [General-purpose functions](#general-purpose_functions)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-getfunctionlist`
- {ref}`mozilla-projects-nss-reference-fc-initialize`
- {ref}`mozilla-projects-nss-reference-fc-finalize`
- {ref}`mozilla-projects-nss-reference-fc-getinfo`
:::

(slot-and-token-management-functions)=

## [Slot and token management functions](#slot_and_token_management_functions)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-getslotlist`
- {ref}`mozilla-projects-nss-reference-fc-getslotinfo`
- {ref}`mozilla-projects-nss-reference-fc-gettokeninfo`
- {ref}`mozilla-projects-nss-reference-fc-waitforslotevent`
- {ref}`mozilla-projects-nss-reference-fc-getmechanismlist`
- {ref}`mozilla-projects-nss-reference-fc-getmechanisminfo`
- {ref}`mozilla-projects-nss-reference-fc-inittoken`
- {ref}`mozilla-projects-nss-reference-fc-initpin`
- {ref}`mozilla-projects-nss-reference-fc-setpin`
:::

(session-management-functions)=

## [Session management functions](#session_management_functions)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-opensession`
- {ref}`mozilla-projects-nss-reference-fc-closesession`
- {ref}`mozilla-projects-nss-reference-fc-closeallsessions`
- {ref}`mozilla-projects-nss-reference-fc-getsessioninfo`
- {ref}`mozilla-projects-nss-reference-fc-getoperationstate`
- {ref}`mozilla-projects-nss-reference-fc-setoperationstate`
- {ref}`mozilla-projects-nss-reference-fc-login`
- {ref}`mozilla-projects-nss-reference-fc-logout`
:::

(object-management-functions)=

## [Object management functions](#object_management_functions)

:::{container}
These functions manage certificates and keys.

- {ref}`mozilla-projects-nss-reference-fc-createobject`
- {ref}`mozilla-projects-nss-reference-fc-copyobject`
- {ref}`mozilla-projects-nss-reference-fc-destroyobject`
- {ref}`mozilla-projects-nss-reference-fc-getobjectsize`
- {ref}`mozilla-projects-nss-reference-fc-getattributevalue`
- {ref}`mozilla-projects-nss-reference-fc-setattributevalue`
- {ref}`mozilla-projects-nss-reference-fc-findobjectsinit`
- {ref}`mozilla-projects-nss-reference-fc-findobjects`
- {ref}`mozilla-projects-nss-reference-fc-findobjectsfinal`
:::

(encryption-functions)=

## [Encryption functions](#encryption_functions)

:::{container}
These functions support Triple DES and AES in ECB and CBC modes.

- {ref}`mozilla-projects-nss-reference-fc-encryptinit`
- {ref}`mozilla-projects-nss-reference-fc-encrypt`
- {ref}`mozilla-projects-nss-reference-fc-encryptupdate`
- {ref}`mozilla-projects-nss-reference-fc-encryptfinal`
:::

(decryption-functions)=

## [Decryption functions](#decryption_functions)

:::{container}
These functions support Triple DES and AES in ECB and CBC modes.

- {ref}`mozilla-projects-nss-reference-fc-decryptinit`
- {ref}`mozilla-projects-nss-reference-fc-decrypt`
- {ref}`mozilla-projects-nss-reference-fc-decryptupdate`
- {ref}`mozilla-projects-nss-reference-fc-decryptfinal`
:::

(message-digesting-functions)=

## [Message digesting functions](#message_digesting_functions)

:::{container}
These functions support SHA-1, SHA-256, SHA-384, and SHA-512.

- {ref}`mozilla-projects-nss-reference-fc-digestinit`
- {ref}`mozilla-projects-nss-reference-fc-digest`
- {ref}`mozilla-projects-nss-reference-fc-digestupdate`
- {ref}`mozilla-projects-nss-reference-fc-digestkey`
- {ref}`mozilla-projects-nss-reference-fc-digestfinal`
:::

(signature-and-mac-generation-functions)=

## [Signature and MAC generation functions](#signature_and_mac_generation_functions)

:::{container}
These functions support DSA, RSA, ECDSA, and HMAC.

- {ref}`mozilla-projects-nss-reference-fc-signinit`
- {ref}`mozilla-projects-nss-reference-fc-sign`
- {ref}`mozilla-projects-nss-reference-fc-signupdate`
- {ref}`mozilla-projects-nss-reference-fc-signfinal`
- {ref}`mozilla-projects-nss-reference-fc-signrecoverinit`
- {ref}`mozilla-projects-nss-reference-fc-signrecover`
:::

(signature-and-mac-verification-functions)=

## [Signature and MAC verification functions](#signature_and_mac_verification_functions)

:::{container}
These functions support DSA, RSA, ECDSA, and HMAC.

- {ref}`mozilla-projects-nss-reference-fc-verifyinit`
- {ref}`mozilla-projects-nss-reference-fc-verify`
- {ref}`mozilla-projects-nss-reference-fc-verifyupdate`
- {ref}`mozilla-projects-nss-reference-fc-verifyfinal`
- {ref}`mozilla-projects-nss-reference-fc-verifyrecoverinit`
- {ref}`mozilla-projects-nss-reference-fc-verifyrecover`
:::

(dual-function-cryptographic-functions)=

## [Dual-function cryptographic functions](#dual-function_cryptographic_functions)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-digestencryptupdate`
- {ref}`mozilla-projects-nss-reference-fc-decryptdigestupdate`
- {ref}`mozilla-projects-nss-reference-fc-signencryptupdate`
- {ref}`mozilla-projects-nss-reference-fc-decryptverifyupdate`
:::

(key-management-functions)=

## [Key management functions](#key_management_functions)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-generatekey`: DSA domain parameters (PQG)
- {ref}`mozilla-projects-nss-reference-fc-generatekeypair`: DSA, RSA, and ECDSA. Performs
  pair-wise consistency test.
- {ref}`mozilla-projects-nss-reference-fc-wrapkey`: RSA Key Wrapping
- {ref}`mozilla-projects-nss-reference-fc-unwrapkey`: RSA Key Wrapping
- {ref}`mozilla-projects-nss-reference-fc-derivekey`: Diffie-Hellman, EC Diffie-Hellman
:::

(random-number-generation-functions)=

## [Random number generation functions](#random_number_generation_functions)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-seedrandom`
- {ref}`mozilla-projects-nss-reference-fc-generaterandom`: Performs continuous random number
  generator test.
:::

(parallel-function-management-functions)=

## [Parallel function management functions](#parallel_function_management_functions)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-getfunctionstatus`
- {ref}`mozilla-projects-nss-reference-fc-cancelfunction`
:::
