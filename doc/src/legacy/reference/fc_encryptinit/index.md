(mozilla-projects-nss-reference-fc-encryptinit)=

# FC_EncryptInit

## Name

:::{container}
FC_EncryptInit - initialize an encryption operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_EncryptInit(
  CK_SESSION_HANDLE hSession,
  CK_MECHANISM_PTR pMechanism,
  CK_OBJECT_HANDLE hKey
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] handle to the session.

`pMechanism`

: [in] pointer to the mechanism to be used for subsequent encryption.

`hKey`

: [in] handle of the encryption key.
:::

## Description

:::{container}
`FC_EncryptInit` initializes an encryption operation with the mechanism and key to be used.

A user must log into the token (to assume the NSS User role) before calling `FC_EncryptInit`.
:::

## Return value

:::{container}
`CKR_OK`

: Slot information was successfully copied.

`CKR_SLOT_ID_INVALID`

: The specified slot number is out of the defined range of values.
:::

## Examples

## See also

:::{container}

- [NSC_EncryptInit](/en-US/NSC_EncryptInit)
:::
