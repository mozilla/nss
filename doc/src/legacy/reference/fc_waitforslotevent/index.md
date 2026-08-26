(mozilla-projects-nss-reference-fc-waitforslotevent)=

# FC_WaitForSlotEvent

## [Name](#name)

:::{container}
FC_WaitForSlotEvent - waits for a slot event, such as token insertion or token removal, to occur.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_WaitForSlotEvent(CK_FLAGS flags, CK_SLOT_ID_PTR pSlot CK_VOID_PTR pReserved);
```

:::

## [Parameters](#parameters)

:::{container}
`FC_WaitForSlotEvent` takes three parameters:

`flags`
`pSlot`.
`pReserved`.
:::

## [Description](#description)

:::{container}
This function is not supported by the NSS cryptographic module.
:::

## [Return value](#return_value)

:::{container}
`FC_WaitForSlotEvent` always returns `CKR_FUNCTION_NOT_SUPPORTED`.
:::

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-waitforslotevent`
:::
