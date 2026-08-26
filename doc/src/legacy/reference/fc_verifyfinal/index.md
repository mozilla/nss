(mozilla-projects-nss-reference-fc-verifyfinal)=

# FC_VerifyFinal

## Name

:::{container}
FC_VerifyFinal - finish a multi-part verify operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_VerifyFinal(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pSignature,
  CK_ULONG usSignatureLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pSignature`

: [in] pointer to the buffer which will receive the digest or NULL.

`usSignatureLen`

: [in] length of the signature in bytes.
:::

## Description

:::{container}
`FC_VerifyFinal` finishes a multi-part signature verification operation.

A user must log into the token (to assume the NSS User role) before calling `FC_VerifyFinal`.
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-verifyupdate`,
  [NSC_VerifyFinal](/en-US/NSC_VerifyFinal)
:::
