(mozilla-projects-nss-reference-fc-signrecoverinit)=

# FC_SignRecoverInit

## Name

:::{container}
FC_SignRecoverInit - initialize a sign recover operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_SignRecoverInit(
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

: [in] mechanism to be used for the signing operation.

`hKey`

: [in] handle of the key to be used.
:::

## Description

:::{container}
`FC_SignRecoverInit` initializes a initializes a signature operation where the (digest) data
can be recovered from the signature.

A user must log into the token (to assume the NSS User role) before calling
`FC_SignRecoverInit`.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_SignRecoverInit](/en-US/NSC_SignRecoverInit)
:::
