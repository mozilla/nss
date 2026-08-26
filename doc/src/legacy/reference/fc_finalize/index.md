(mozilla-projects-nss-reference-fc-finalize)=

# FC_Finalize

## Name

:::{container}
FC_Finalize - indicate that an application is done with the PKCS #11 library.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_Finalize (CK_VOID_PTR pReserved);
```

:::

## Parameters

:::{container}
`FC_Finalize` has one parameter:

`pReserved`

: must be `NULL`
:::

## Description

:::{container}
`FC_Finalize` shuts down the {ref}`mozilla-projects-nss-reference-nss-cryptographic-module` in
the {ref}`mozilla-projects-nss-reference-nss-cryptographic-module-fips-mode-of-operation`. If the
library is not initialized, it does nothing.

The `pReserved` argument is not used and must be `NULL`.
:::

## Return value

::::{container}
`FC_Finalize` always returns `CKR_OK`.

:::{note}
`FC_Finalize` should check the `pReserved` argument and return `CKR_ARGUMENTS_BAD` if
`pReserved` is not `NULL`.

`FC_Finalize` should return `CKR_CRYPTOKI_NOT_INITIALIZED` if the library is not
initialized.
:::
::::

## Examples

:::{container}

```{code}
#include <assert.h>

CK_FUNCTION_LIST_PTR pFunctionList;
CK_RV crv;

crv = FC_GetFunctionList(&pFunctionList);
assert(crv == CKR_OK);

...

/* invoke FC_Finalize as pFunctionList->C_Finalize */
crv = pFunctionList->C_Finalize(NULL);
```

:::

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-initialize`,
  [NSC_Initialize](/en-US/NSC_Initialize), [NSC_Finalize](/en-US/NSC_Finalize)
:::
