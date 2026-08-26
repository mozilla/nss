(mozilla-projects-nss-reference-fc-encrypt)=

# FC_Encrypt

## [Name](#name)

:::{container}
FC_Encrypt - Encrypt a block of data.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_Encrypt(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pData,
  CK_ULONG usDataLen,
  CK_BYTE_PTR pEncryptedData,
  CK_ULONG_PTR pusEncryptedDataLen
);
```

:::

## [Parameters](#parameters)

:::{container}
`hSession`

: [in] session handle.

`pData`

: [in] pointer to the data buffer

`usDataLen`

: [in] length of the data buffer in bytes.

`pEncryptedData`

: [out] pointer to location where encrypted data is to be stored.

`pusEncryptedDataLen`

: [in/out] number of bytes.
:::

## [Description](#description)

:::{container}
`FC_Encrypt` encrypts a block of data according to the attributes of the previous call to
`FC_EncryptInit`.

A user must log into the token (to assume the NSS User role) before calling `FC_Encrypt`.
:::

## [Return value](#return_value)

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-encryptinit`, [NSC_Encrypt](/en-US/NSC_Encrypt)
:::
