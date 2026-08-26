(mozilla-projects-nss-reference-fc-createobject)=

# FC_CreateObject

## Name

:::{container}
FC_CreateObject - create a new object.
:::

## Syntax

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

## Parameters

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

## Description

:::{container}
`FC_CreateObject` creates an object using the attributes specified in the template.

A user must log into the token (to assume the NSS User role) before calling `FC_CreateObject`.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-destroyobject`,
  [NSC_CreateObject](/en-US/NSC_CreateObject)
:::
