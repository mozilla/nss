(mozilla-projects-nss-reference-fc-closesession)=

# FC_CloseSession

## Name

:::{container}
FC_CloseSession - close a session opened between an application and a token.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_CloseSession(
  CK_SESSION_HANDLE hSession
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] the session handle to be closed.
:::

## Description

:::{container}
`FC_CloseSession` closes a session between an application and a token.

A user may call `FC_CloseSession` without logging into the token (to assume the NSS User role).
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-opensession`
:::
