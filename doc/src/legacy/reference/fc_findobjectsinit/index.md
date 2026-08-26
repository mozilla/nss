(mozilla-projects-nss-reference-fc-findobjectsinit)=

# FC_FindObjectsInit

## [Name](#name)

:::{container}
FC_FindObjectsInit - initialize the parameters for an object search.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_FindObjectsInit(
  CK_SESSION_HANDLE hSession,
  CK_ATTRIBUTE_PTR pTemplate,
  CK_ULONG usCount
);
```

:::

## [Parameters](#parameters)

:::{container}
`hSession`

: [in] session handle.

`pTemplate`

: [in] pointer to template.

`usCount`

: [in] number of attributes in the template.
:::

## [Description](#description)

:::{container}
`FC_FindObjectsInit` sets the attribute list for an object search. If `FC_FindObjectsInit` is
successful `FC_FindObjects` may be called one or more times to retrieve handles of matching
objects.

A user must log into the token (to assume the NSS User role) before searching for secret or
private key objects.
:::

## [Return value](#return_value)

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-findobjects`,
  [NSC_FindObjectsInit](/en-US/NSC_FindObjectsInit)
:::
