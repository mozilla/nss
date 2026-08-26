(mozilla-projects-nss-reference-fc-findobjects)=

# FC_FindObjects

## Name

:::{container}
FC_FindObjects - Search for one or more objects
:::

## Syntax

:::{container}

```{code}
CK_RV FC_FindObjects(
  CK_SESSION_HANDLE hSession,
  CK_OBJECT_HANDLE_PTR phObject,
  CK_ULONG usMaxObjectCount,
  CK_ULONG_PTR pusObjectCount
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pTemplate`

: [out] pointer to location to receive the object handles.

`usMaxObjectCount`

: [in] maximum number of handles to retrieve.

`pusObjectCount`

: [out] pointer to location to receive the number of returned handles.
:::

## Description

:::{container}
`FC_FindObjects` returns the next set of object handles matching the criteria set up by the
previous call to `FC_FindObjectsInit` and sets the object count variable to their number or to
zero if there are none.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-findobjectsinit`,
  [NSC_FindObjects](/en-US/NSC_FindObjects)
:::
