(mozilla-projects-nss-reference-fc-digestupdate)=

# FC_DigestUpdate

## [Name](#name)

:::{container}
FC_DigestUpdate - process the next block of a multi-part digest operation.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_DigestUpdate(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pPart,
  CK_ULONG usPartLen
);
```

:::

## [Parameters](#parameters)

:::{container}
`hSession`

: [in] session handle.

`pPart`

: [in] pointer to the next block of data to be digested.

`usPartLen`

: [in] length of data block in bytes.
:::

## [Description](#description)

:::{container}
`FC_DigestUpdate` starts or continues a multi-part digest operation. One or more blocks may be
part of the message digest operation. The digest for the entire message is returned by a call to
{ref}`mozilla-projects-nss-reference-fc-digestfinal`.

A user may call `FC_DigestUpdate` without logging into the token (to assume the NSS User role).
:::

## [Return value](#return_value)

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-digestinit`,
  {ref}`mozilla-projects-nss-reference-fc-digestfinal`,
  [NSC_DigestUpdate](/en-US/NSC_DigestUpdate)
:::
