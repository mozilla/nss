(mozilla-projects-nss-reference-fc-setattributevalue)=

# FC_SetAttributeValue

## Name

:::{container}
FC_SetAttributeValue - set the values of attributes of an object.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_SetAttributeValue(
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
`FC_SetAttributeValue` sets the value of one or more attributes of an object.

A user must log into the token before setting the attribute values of a secret or private key
object.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_SetAttributeValue](/en-US/NSC_SetAttributeValue)
:::
