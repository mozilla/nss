(mozilla-projects-nss-reference-fc-getobjectsize)=

# FC_GetObjectSize

## Name

:::{container}
FC_GetObjectSize - create a copy of an object.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_GetObjectSize(
  CK_SESSION_HANDLE hSession,
  CK_OBJECT_HANDLE hObject,
  CK_ULONG_PTR pusSize
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`hObject`

: [in] object handle.

`pusSize`

: [out] pointer to location to receive the object's size.
:::

## Description

:::{container}
`FC_GetObjectSize` gets the size of an object in bytes.

A user must log into the token (to assume the NSS User role) before getting the size of a secret
or private key object.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_GetObjectSize](/en-US/NSC_GetObjectSize)
:::
