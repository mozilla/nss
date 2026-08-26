(mozilla-projects-nss-reference-fc-decryptupdate)=

# FC_DecryptUpdate

## Name

:::{container}
FC_DecryptUpdate - decrypt a block of a multi-part encryption operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_DecryptUpdate(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pEncryptedPart,
  CK_ULONG usEncryptedPartLen,
  CK_BYTE_PTR pPart,
  CK_ULONG_PTR pusPartLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pEncryptedPart`

: [in] pointer to the next block of data to be decrypted.

`usEncryptedPartLen`

: [in] length of data block in bytes.

`pPart`

: [out] pointer to location where recovered block is to be stored.

`pusPartLen`

: [in,out] pointer the location where the number of bytes of recovered data is to be stored.
:::

## Description

:::{container}
`FC_DecryptUpdate` decrypts a block of data according to the attributes of the previous call to
`FC_DecryptInit`. The block may be part of a multi-part decryption operation.

A user must log into the token (to assume the NSS User role) before calling `FC_DecryptUpdate`.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-decryptinit`,
  [NSC_DecryptUpdate](/en-US/NSC_DecryptUpdate)
:::
