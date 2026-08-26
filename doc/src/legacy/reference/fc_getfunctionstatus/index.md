(mozilla-projects-nss-reference-fc-getfunctionstatus)=

# FC_GetFunctionStatus

## Name

:::{container}
FC_GetFunctionStatus - get the status of a function running in parallel
:::

## Syntax

:::{container}

```{code}
CK_RV FC_GetFunctionStatus(
  CK_SESSION_HANDLE hSession
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.
:::

## Description

:::{container}
`FC_GetFunctionStatus` is a legacy function that simply returns `CKR_FUNCTION_NOT_PARALLEL`.
:::

## Return value

:::{container}
`FC_GetFunctionStatus` always returns `CKR_FUNCTION_NOT_PARALLEL`.
:::

## Examples

## See also

:::{container}

- [NSC_GetFunctionStatus](/en-US/NSC_GetFunctionStatus)
:::
