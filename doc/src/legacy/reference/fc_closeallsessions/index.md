(mozilla-projects-nss-reference-fc-closeallsessions)=

# FC_CloseAllSessions

## [Name](#name)

:::{container}
FC_CloseAllSessions - close all sessions between an application and a token.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_CloseAllSessions(
  CK_SLOT_ID slotID
 );
```

:::

## [Parameters](#parameters)

:::{container}
`slotID`

: [in] the ID of the token's slot.
:::

## [Description](#description)

:::{container}
`FC_CloseAllSessions` closes all sessions between an application and the token in the slot with
the ID `slotID`.

The NSS cryptographic module currently doesn't call the surrender callback function `Notify`.
(See PKCS #11 v2.20 section 11.17.1.)

A user may call `FC_CloseAllSessions` without logging into the token (to assume the NSS User
role).
:::

## [Return value](#return_value)

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-closesession`,
  [NSC_CloseAllSessions](/en-US/NSC_CloseAllSessions)
:::
