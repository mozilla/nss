(mozilla-projects-nss-reference-fc-verifyupdate)=

# FC_VerifyUpdate

## Name

:::{container}
FC_VerifyUpdate - process the next block of a multi-part verify operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_VerifyUpdate(
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

: [in] pointer to the next block of the data to be verified.

`usPartLen`

: [in] length of data block in bytes.
:::

## Description

:::{container}
`FC_VerifyUpdate` starts or continues a multi-part signature verification operation where the
signature is an appendix to the data. One or more blocks may be part of the signature. The result
for the entire message is returned by a call to
{ref}`mozilla-projects-nss-reference-fc-verifyfinal`.

A user must log into the token (to assume the NSS User role) before calling `FC_VerifyUpdate`.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-verifyfinal`,
  [NSC_VerifyUpdate](/en-US/NSC_VerifyUpdate)
:::
