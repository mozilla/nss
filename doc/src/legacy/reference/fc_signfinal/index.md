(mozilla-projects-nss-reference-fc-signfinal)=

# FC_SignFinal

## [Name](#name)

:::{container}
FC_SignFinal - finish a multi-part signing operation.
:::

## [Syntax](#syntax)

:::{container}

```{code}
CK_RV FC_SignFinal(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pSignature,
  CK_ULONG_PTR pusSignatureLen
);
```

:::

## [Parameters](#parameters)

:::{container}
`hSession`

: [in] session handle.

`pSignature`

: [out] pointer to the buffer which will receive the digest or NULL.

`pusSignatureLen`

: [in, out] pointer to location containing the maximum buffer size.
:::

## [Description](#description)

:::{container}
`FC_SignFinal` finishes a multi-part signing operation by returning the complete signature and
clearing the operation context. If `pSignature` is NULL the length of the signature is returned
and `FC_SignFinal` may be called again with `pSignature` set to retrieve the signature.

A user must log into the token (to assume the NSS User role) before calling `FC_SignFinal`.
:::

## [Return value](#return_value)

## [Examples](#examples)

## [See also](#see_also)

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-signupdate`, [NSC_SignFinal](/en-US/NSC_SignFinal)
:::
