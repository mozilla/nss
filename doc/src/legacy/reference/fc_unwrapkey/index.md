(mozilla-projects-nss-reference-fc-unwrapkey)=

# FC_UnwrapKey

## Name

:::{container}
FC_UnwrapKey - unwrap a key
:::

## Syntax

:::{container}

```{code}
CK_RV FC_UnwrapKey(
  CK_SESSION_HANDLE hSession,
  CK_MECHANISM_PTR pMechanism,
  CK_OBJECT_HANDLE hUnwrappingKey,
  CK_BYTE_PTR pWrappedKey,
  CK_ULONG usWrappedKeyLen,
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

`hUnwrappingKey`

: [in] handle of the ket to use for unwrapping.

`pWrappedKey`

: [in] pointer to the wrapped key.

`usWrappedKeyLen`

: [in] length of the wrapped key.

`pTemplate`

: [in] pointer to the list of attributes for the unwrapped key.

`usAttributeCount`

: [in] number of attributes in the template.

`phKey`

: [out] pointer to the location to receive the handle of the unwrapped key.
:::

## Description

:::{container}
`FC_UnwrapKey` unwraps (decrypts) a key and creates a new key opbject. If `pWrappedKey` is
NULL the length of the wrapped key is returned in `pusWrappedKeyLen` and FC_UnwrapKey may be
called again with `pWrappedKey` set to retrieve the wrapped key.

A user must log into the token (to assume the NSS User role) before calling `FC_UnwrapKey`.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_UnwrapKey](/en-US/NSC_UnwrapKey)
:::
