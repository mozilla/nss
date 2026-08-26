(mozilla-projects-nss-reference-fc-signupdate)=

# FC_SignUpdate

## [Name](#name)

:::{container}
FC_SignUpdate - process the next block of a multi-part signing operation.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_SignUpdate(
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

: [in] pointer to the next block of the data to be signed.

`usPartLen`

: [in] length of data block in bytes.
:::

## [Description](#description)

:::{container}
`FC_SignUpdate` starts or continues a multi-part signature operation. One or more blocks may be
part of the signature. The signature for the entire message is returned by a call to
{ref}`mozilla-projects-nss-reference-fc-signfinal`.

A user must log into the token (to assume the NSS User role) before calling `FC_SignUpdate`.
:::

## [Return value](#return_value)

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-signinit`,
  {ref}`mozilla-projects-nss-reference-fc-signfinal`, [NSC_SignUpdate](/en-US/NSC_SignUpdate)
:::
