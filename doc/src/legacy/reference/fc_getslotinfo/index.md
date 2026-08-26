(mozilla-projects-nss-reference-fc-getslotinfo)=

# FC_GetSlotInfo

## Name

:::{container}
FC_GetSlotInfo - get information about a particular slot in the system.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_GetSlotInfo(
  CK_SLOT_ID slotID,
  CK_SLOT_INFO_PTR pInfo
);
```

:::

## Parameters

:::{container}
`FC_GetSlotInfo` takes two parameters:

`slotID`

: [in]

`pInfo`

: [out] The address of a `CK_SLOT_INFO` structure.
:::

## Description

:::{container}
`FC_GetSlotInfo` stores the information about the slot in the `CK_SLOT_INFO` structure that
`pInfo` points to.

A user may call `FC_GetSlotInfo` without logging into the token (to assume the NSS User role).
:::

## Return value

:::{container}
`CKR_OK`

: Slot information was successfully copied.

`CKR_SLOT_ID_INVALID`

: The specified slot number is out of the defined range of values.
:::

## Examples

## See also

:::{container}

- [NSC_GetSlotInfo](/en-US/NSC_GetSlotInfo)
:::
