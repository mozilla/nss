(mozilla-projects-nss-reference-fc-generatekeypair)=

# FC_GenerateKeyPair

## Name

:::{container}
FC_GenerateKeyPair - generate a new public/private key pair
:::

## Syntax

:::{container}

```{code}
CK_RV FC_GenerateKeyPair(
  CK_SESSION_HANDLE hSession,
  CK_MECHANISM_PTR pMechanism,
  CK_ATTRIBUTE_PTR pPublicKeyTemplate,
  CK_ULONG usPublicKeyAttributeCount,
  CK_ATTRIBUTE_PTR pPrivateKeyTemplate,
  CK_ULONG usPrivateKeyAttributeCount,
  CK_OBJECT_HANDLE_PTR phPublicKey,
  CK_OBJECT_HANDLE_PTR phPrivateKey
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pMechanism`

: [in] pointer to the mechanism to use.

`pPublicKeyTemplate`

: [in] pointer to the public key template.

`usPublicKeyAttributeCount`

: [in] number of attributes in the public key template.

`pPrivateKeyTemplate`

: [in] pointer to the private key template.

`usPrivateKeyAttributeCount`

: [in] number of attributes in the private key template.

`phPublicKey`

: [out] pointer to the location to receive the handle of the new public key.

`phPrivateKey`

: [out] pointer to the location to receive the handle of the new private key.
:::

## Description

:::{container}
`FC_GenerateKeyPair` generates a public/private key pair, creating new key objects. The handles
of new keys are returned.

A user must log into the token (to assume the NSS User role) before calling
`FC_GenerateKeyPair`.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_GenerateKeyPair](/en-US/NSC_GenerateKeyPair)
:::
