(mozilla-projects-nss-reference-fc-derivekey)=

# FC_DeriveKey

## Name

:::{container}
FC_DeriveKey - derive a key from a base key
:::

## Syntax

:::{container}

```{code}
CK_RV FC_DeriveKey(
  CK_SESSION_HANDLE hSession,
  CK_MECHANISM_PTR pMechanism,
  CK_OBJECT_HANDLE hBaseKey,
  CK_ATTRIBUTE_PTR pTemplate,
  CK_ULONG usAttributeCount,
  CK_OBJECT_HANDLE_PTR phKey
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pMechanism`

: [in] pointer to the mechanism to use.

`hBaseKey`

: [in] handle of the base key.

`pWrappedKey`

: [in] pointer to the wrapped key.

`pTemplate`

: [in] pointer to the list of attributes for the new key.

`usAttributeCount`

: [in] number of attributes in the template.

`phKey`

: [out] pointer to the location to receive the handle of the new key.
:::

## Description

:::{container}
`FC_DeriveKey` derives (decrypts) a key and creates a new key object.

A user must log into the token (to assume the NSS User role) before calling `FC_DeriveKey`.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_DeriveKey](/en-US/NSC_DeriveKey)
:::
