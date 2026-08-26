(mozilla-projects-nss-reference-fc-opensession)=

# FC_OpenSession

## Name

:::{container}
FC_OpenSession - open a session between an application and a token.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_OpenSession(
  CK_SLOT_ID slotID,
  CK_FLAGS flags,
  CK_VOID_PTR pApplication,
  CK_NOTIFY Notify,
  CK_SESSION_HANDLE_PTR phSession
);
```

:::

## Parameters

:::{container}
`FC_OpenSession` has the following parameters:

`slotID`

: [in] the ID of the token's slot.

`flags`

: [in]

`pApplication`

`Notify`

: [in] pointer to a notification callback function. Not currently supported.

`phSession`

: [out] pointer to a session handle.
:::

## Description

:::{container}
`FC_OpenSession` opens a session between an application and the token in the slot with the ID
`slotID`.

The NSS cryptographic module currently doesn't call the surrender callback function `Notify`.
(See PKCS #11 v2.20 section 11.17.1.)

A user may call `FC_OpenSession` without logging into the token (to assume the NSS User role).
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-closesession`,
  [NSC_OpenSession](/en-US/NSC_OpenSession)
:::
