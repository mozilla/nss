(mozilla-projects-nss-reference-fc-getmechanisminfo)=

# FC_GetMechanismInfo

## Name

:::{container}
FC_GetMechanismInfo - get information on a particular mechanism.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_GetMechanismInfo(
  CK_SLOT_ID slotID,
  CK_MECHANISM_TYPE type,
  CK_MECHANISM_INFO_PTR pInfo
);
```

:::

## Parameters

:::{container}
`FC_GetMechanismInfo` takes three parameters:

`slotID`

: [Input]

`type`

: [Input] .

`pInfo`

: [Output] .
:::

## Description

:::{container}
`FC_GetMechanismInfo` obtains information about a particular mechanism possibly supported by a
token.

A user may call `FC_GetMechanismInfo` without logging into the token (to assume the NSS User
role).
:::

## Return value

:::{container}
`CKR_OK`
:::

## Examples

## See also

:::{container}

- [NSC_GetMechanismInfo](/en-US/NSC_GetMechanismInfo)
:::
