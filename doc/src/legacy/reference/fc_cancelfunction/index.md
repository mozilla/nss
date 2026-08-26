(mozilla-projects-nss-reference-fc-cancelfunction)=

# FC_CancelFunction

## Name

:::{container}
FC_CancelFunction - cancel a function running in parallel
:::

## Syntax

:::{container}

```{code}
CK_RV FC_CancelFunction(
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
Parallel functions are not implemented. `FC_CancelFunction` is a legacy function that simply
returns `CKR_FUNCTION_NOT_PARALLEL`.
:::

## Return value

:::{container}
`FC_CancelFunction` always returns `CKR_FUNCTION_NOT_PARALLEL`.
:::

## Examples

## See also

:::{container}

- [NSC_CancelFunction](/en-US/NSC_CancelFunction)
:::
