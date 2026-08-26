(mozilla-projects-nss-reference-fc-decrypt)=

# FC_Decrypt

## Name

:::{container}
FC_Decrypt - Decrypt a block of data.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_Decrypt(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pEncryptedData,
  CK_ULONG usEncryptedDataLen,
  CK_BYTE_PTR pData,
  CK_ULONG_PTR pusDataLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pEncryptedData`

: [in] pointer to encrypted data block.

`usEncryptedDataLen`

: [in] length of the data in bytes.

`pData`

: [out] pointer to location where recovered data is to be stored.

`pusDataLen`

: [in,out] pointer to location where the length of recovered data is to be stored.
:::

## Description

:::{container}
`FC_Decrypt` decrypts a block of data according to the attributes of the previous call to
`FC_DecryptInit`.

A user must log into the token (to assume the NSS User role) before calling `FC_Decrypt`.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-decryptinit`, [NSC_Decrypt](/en-US/NSC_Decrypt)
:::
