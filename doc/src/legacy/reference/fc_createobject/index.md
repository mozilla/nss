(mozilla-projects-nss-reference-fc-createobject)=

# FC_CreateObject

## [Name](#name)

:::{container}
FC_CreateObject - create a new object.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_CreateObject(
  CK_SESSION_HANDLE hSession,
  CK_ATTRIBUTE_PTR pTemplate,
  CK_ULONG ulCount,
  CK_OBJECT_HANDLE_PTR phObject
);
```

:::

## [Parameters](#parameters)

:::{container}
`hSession`

: [in] session handle.

`pTemplate`

: [in] object template.

`ulCount`

: [in] number of attributes in the template.

`phObject`

: [out] pointer to location to receive the new objects handle.
:::

## [Description](#description)

:::{container}
`FC_CreateObject` creates an object using the attributes specified in the template.

A user must log into the token (to assume the NSS User role) before calling `FC_CreateObject`.
:::

## [Return value](#return_value)

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-destroyobject`,
  [NSC_CreateObject](/en-US/NSC_CreateObject)
:::
