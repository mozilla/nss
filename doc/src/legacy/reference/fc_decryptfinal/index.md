(mozilla-projects-nss-reference-fc-decryptfinal)=

# FC_DecryptFinal

## Name

:::{container}
FC_DecryptFinal - finish a multi-part decryption operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_DecryptFinal(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pLastPart,
  CK_ULONG_PTR pusLastPartLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pLastPart`

: [out] pointer to the location where the last block of recovered data, if any, is to be stored.

`pusLastPartLen`

: [in,out] pointer to location where the number of bytes of recovered data is to be stored.
:::

## Description

:::{container}
`FC_DecryptFinal` returns the last block of data of a multi-part decryption operation.

A user must log into the token (to assume the NSS User role) before calling `FC_DecryptFinal`.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-decryptinit`,
  [NSC_DecryptFinal](/en-US/NSC_DecryptFinal)
:::
