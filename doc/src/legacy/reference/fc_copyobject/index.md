(mozilla-projects-nss-reference-fc-copyobject)=

# FC_CopyObject

## [Name](#name)

:::{container}
FC_CopyObject - create a copy of an object.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_CopyObject(
  CK_SESSION_HANDLE hSession,
  CK_OBJECT_HANDLE hObject,
  CK_ATTRIBUTE_PTR pTemplate,
  CK_ULONG usCount,
  CK_OBJECT_HANDLE_PTR phNewObject
);
```

:::

## [Parameters](#parameters)

:::{container}
`hSession`

: [in] session handle.

`hObject`

: [in] object handle.

`pTemplate`

: [in] object template.

`usCount`

: [in] number of attributes in the template.

`phnewObject`

: [out] pointer to location to receive the new object's handle.
:::

## [Description](#description)

:::{container}
`FC_CopyObject` creates a copy of an object using the attributes specified in the template.

A user must log into the token (to assume the NSS User role) before copying a secret or private
key object.
:::

## [Return value](#return_value)

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-destroyobject`,
  [NSC_CopyObject](/en-US/NSC_CopyObject)
:::
