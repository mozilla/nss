(mozilla-projects-nss-reference-fc-digestupdate)=

# FC_DigestUpdate

## Name

:::{container}
FC_DigestUpdate - process the next block of a multi-part digest operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_DigestUpdate(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pPart,
  CK_ULONG usPartLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pPart`

: [in] pointer to the next block of data to be digested.

`usPartLen`

: [in] length of data block in bytes.
:::

## Description

:::{container}
`FC_DigestUpdate` starts or continues a multi-part digest operation. One or more blocks may be
part of the message digest operation. The digest for the entire message is returned by a call to
{ref}`mozilla-projects-nss-reference-fc-digestfinal`.

A user may call `FC_DigestUpdate` without logging into the token (to assume the NSS User role).
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-digestinit`,
  {ref}`mozilla-projects-nss-reference-fc-digestfinal`,
  [NSC_DigestUpdate](/en-US/NSC_DigestUpdate)
:::
