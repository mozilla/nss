(mozilla-projects-nss-reference-fc-signupdate)=

# FC_SignUpdate

## Name

:::{container}
FC_SignUpdate - process the next block of a multi-part signing operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_SignUpdate(
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

: [in] pointer to the next block of the data to be signed.

`usPartLen`

: [in] length of data block in bytes.
:::

## Description

:::{container}
`FC_SignUpdate` starts or continues a multi-part signature operation. One or more blocks may be
part of the signature. The signature for the entire message is returned by a call to
{ref}`mozilla-projects-nss-reference-fc-signfinal`.

A user must log into the token (to assume the NSS User role) before calling `FC_SignUpdate`.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-signinit`,
  {ref}`mozilla-projects-nss-reference-fc-signfinal`, [NSC_SignUpdate](/en-US/NSC_SignUpdate)
:::
