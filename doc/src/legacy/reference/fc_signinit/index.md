(mozilla-projects-nss-reference-fc-signinit)=

# FC_SignInit

## Name

:::{container}
FC_SignInit - initialize a signing operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_SignInit(
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

: [in] mechanism to be used for the subsequent signing operation.

`hKey`

: [in] handle of the key to be used .
:::

## Description

:::{container}
`FC_SignInit` initializes a signature operation.

A user must log into the token (to assume the NSS User role) before calling `FC_SignInit`.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_SignInit](/en-US/NSC_SignInit) {ref}`mozilla-projects-nss-reference-fc-sign`
  {ref}`mozilla-projects-nss-reference-fc-signupdate`
  {ref}`mozilla-projects-nss-reference-fc-signfinal`
:::
