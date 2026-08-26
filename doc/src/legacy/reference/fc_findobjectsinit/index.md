(mozilla-projects-nss-reference-fc-findobjectsinit)=

# FC_FindObjectsInit

## Name

:::{container}
FC_FindObjectsInit - initialize the parameters for an object search.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_FindObjectsInit(
  CK_SESSION_HANDLE hSession,
  CK_ATTRIBUTE_PTR pTemplate,
  CK_ULONG usCount
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pTemplate`

: [in] pointer to template.

`usCount`

: [in] number of attributes in the template.
:::

## Description

:::{container}
`FC_FindObjectsInit` sets the attribute list for an object search. If `FC_FindObjectsInit` is
successful `FC_FindObjects` may be called one or more times to retrieve handles of matching
objects.

A user must log into the token (to assume the NSS User role) before searching for secret or
private key objects.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-findobjects`,
  [NSC_FindObjectsInit](/en-US/NSC_FindObjectsInit)
:::
