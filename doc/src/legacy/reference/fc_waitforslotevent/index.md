(mozilla-projects-nss-reference-fc-waitforslotevent)=

# FC_WaitForSlotEvent

## Name

:::{container}
FC_WaitForSlotEvent - waits for a slot event, such as token insertion or token removal, to occur.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_WaitForSlotEvent(CK_FLAGS flags, CK_SLOT_ID_PTR pSlot CK_VOID_PTR pReserved);
```

:::

## Parameters

:::{container}
`FC_WaitForSlotEvent` takes three parameters:

`flags`
`pSlot`.
`pReserved`.
:::

## Description

:::{container}
This function is not supported by the NSS cryptographic module.
:::

## Return value

:::{container}
`FC_WaitForSlotEvent` always returns `CKR_FUNCTION_NOT_SUPPORTED`.
:::

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-waitforslotevent`
:::
