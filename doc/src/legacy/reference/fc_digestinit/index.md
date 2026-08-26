(mozilla-projects-nss-reference-fc-digestinit)=

# FC_DigestInit

## Name

:::{container}
FC_DigestInit - initialize a message-digest operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_DigestInit(
  CK_SESSION_HANDLE hSession,
  CK_MECHANISM_PTR pMechanism
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pMechanism`

: [in] mechanism to be used for the subsequent digest operation.
:::

## Description

:::{container}
`FC_DigestInit` initializes a message-digest operation.

A user may call `FC_DigestInit` without logging into the token (to assume the NSS User role).
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_DigestInit](/en-US/NSC_DigestInit)
:::
