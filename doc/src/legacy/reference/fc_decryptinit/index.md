(mozilla-projects-nss-reference-fc-decryptinit)=

# FC_DecryptInit

## Name

:::{container}
FC_DecryptInit - initialize a decryption operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_DecryptInit(
  CK_SESSION_HANDLE hSession,
  CK_MECHANISM_PTR pMechanism,
  CK_OBJECT_HANDLE hKey
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pMechanism`

: [in] mechanism to be used for the subsequent decryption operation.

`hKey`

: [in] handle of the key to be used.
:::

## Description

:::{container}
`FC_DecryptInit` initializes a decryption operation.

A user must log into the token (to assume the NSS User role) before calling `FC_DecryptInit`.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_DecryptInit](/en-US/NSC_DecryptInit)
:::
