(mozilla-projects-nss-reference-fc-verifyrecover)=

# FC_VerifyRecover

## Name

:::{container}
FC_VerifyRecover - Verify data in a single recoverable operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_VerifyRecover(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pSignature,
  CK_ULONG usSignatureLen,
  CK_BYTE_PTR pData,
  CK_ULONG_PTR pusDataLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pSignature`

: [in] mechanism to be used for the signing operation.

`usSignatureLen`

: [in] handle of the key to be usedn.

`pData`

: [out] pointer to the buffer or NULL.

`pusDataLen`

: [in, out] pointer to the size of the output buffer, replaced by the length of the signature if
  the operation is successful.
:::

## Description

:::{container}
`FC_VerifyRecover` verifies data in a single operation where the (digest) data can be recovered
from the signature. If `pSignature` is NULL only the length of the signature is returned in
`*pusSignatureLen`.

A user must log into the token (to assume the NSS User role) before calling `FC_VerifyRecover`.
:::

## Return value

## Examples

## See also

:::{container}

- [NSC_VerifyRecover](/en-US/NSC_VerifyRecover)
:::
