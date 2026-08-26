(mozilla-projects-nss-reference-fc-getattributevalue)=

# FC_GetAttributeValue

## Name

:::{container}
FC_GetAttributeValue - get the value of attributes of an object.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_GetAttributeValue(
  CK_SESSION_HANDLE hSession,
  CK_OBJECT_HANDLE hObject,
  CK_ATTRIBUTE_PTR pTemplate,
  CK_ULONG usCount
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`hObject`

: [in] object handle.

`pTemplate`

: [in, out] pointer to template.

`usCount`

: [in] number of attributes in the template.
:::

## Description

:::{container}
`FC_GetAttributeValue` gets the value of one or more attributes of an object.

A user must log into the token (to assume the NSS User role) before getting the attribute values
of a secret or private key object.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_GetAttributeValue](/en-US/NSC_GetAttributeValue)
:::
