(mozilla-projects-nss-reference-fc-getmechanismlist)=

# FC_GetMechanismList

## Name

:::{container}
FC_GetMechanismList - get a list of mechanism types supported by a token.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_GetMechanismList(
  CK_SLOT_ID slotID,
  CK_MECHANISM_TYPE_PTR pMechanismList,
  CK_ULONG_PTR pusCount
);
```

:::

## Parameters

:::{container}
`FC_GetMechanismList` takes three parameters:

`slotID`

: [Input]

`pInfo`

: [Output] The address of a variable that will receive a pointer to the list of function
  pointers.
:::

## Description

:::{container}
`FC_GetMechanismList` obtains a list of mechanism types supported by a token.

A user may call `FC_GetMechanismList` without logging into the token (to assume the NSS User
role).
:::

## Return value

:::{container}
`CKR_OK`
:::

## Examples

## See also

:::{container}

- [NSC_GetMechanismList](/en-US/NSC_GetMechanismList)
:::
