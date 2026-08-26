(mozilla-projects-nss-reference-fc-getfunctionlist)=

# FC_GetFunctionList

## Name

:::{container}
FC_GetFunctionList - get a pointer to the list of function pointers in the FIPS mode of
operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_GetFunctionList(CK_FUNCTION_LIST_PTR *ppFunctionList);
```

:::

## Parameters

:::{container}
`FC_GetFunctionList` has one parameter:

`ppFunctionList`

: [Output] The address of a variable that will receive a pointer to the list of function
  pointers.
:::

## Description

:::{container}
`FC_GetFunctionList` stores in `*ppFunctionList` a pointer to the
{ref}`mozilla-projects-nss-reference-nss-cryptographic-module`'s list of function pointers in the
{ref}`mozilla-projects-nss-reference-nss-cryptographic-module-fips-mode-of-operation`.

A user may call `FC_GetFunctionList` without logging into the token (to assume the NSS User
role).
:::

## Return value

:::{container}
`FC_GetFunctionList` always returns `CKR_OK`.
:::

## Examples

:::{container}

```{code}
#include <assert.h>

CK_FUNCTION_LIST_PTR pFunctionList;
CK_RV crv;

crv = FC_GetFunctionList(&pFunctionList);
assert(crv == CKR_OK);

/* invoke the FC_XXX function as pFunctionList->C_XXX */
```

:::

## See also

:::{container}

- [NSC_GetFunctionList](/en-US/NSC_GetFunctionList)
:::
