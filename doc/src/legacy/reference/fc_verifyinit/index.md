(mozilla-projects-nss-reference-fc-verifyinit)=

# FC_VerifyInit

## Name

:::{container}
FC_VerifyInit - initialize a verification operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_VerifyInit(
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

: [in] mechanism to be used for the verification operation.

`hKey`

: [in] handle of the key to be used.
:::

## Description

:::{container}
`FC_VerifyInit` initializes a verification operation where the signature is an appendix to the
data.

A user must log into the token (to assume the NSS User role) before calling `FC_VerifyInit`.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_VerifyInit](/en-US/NSC_VerifyInit)
:::
