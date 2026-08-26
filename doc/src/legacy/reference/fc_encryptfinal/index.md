(mozilla-projects-nss-reference-fc-encryptfinal)=

# FC_EncryptFinal

## Name

:::{container}
FC_EncryptFinal - finish a multi-part encryption operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_EncryptFinal(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pLastEncryptedPart,
  CK_ULONG_PTR pusLastEncryptedPartLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pLastEncryptedPart`

: [out] pointer to the location that receives the last encrypted data part, if any

`pusLastEncryptedPartLen`

: [in,out] pointer to location where the number of bytes of the last encrypted data part is to
  be stored.
:::

## Description

:::{container}
`FC_EncryptFinal` returns the last block of data of a multi-part encryption operation.

A user must log into the token (to assume the NSS User role) before calling `FC_EncryptFinal`.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-encryptinit`,
  [NSC_EncryptFinal](/en-US/NSC_EncryptFinal)
:::
