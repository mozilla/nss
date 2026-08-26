(mozilla-projects-nss-reference-fc-digestfinal)=

# FC_DigestFinal

## Name

:::{container}
FC_DigestFinal - finish a multi-part digest operation.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_DigestFinal(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pDigest,
  CK_ULONG_PTR pulDigestLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pDigest`

: [out] pointer to the buffer which will receive the digest or NULL.

`pulDigestLen`

: [in, out] pointer to location containing the maximum buffer size.
:::

## Description

:::{container}
`FC_DigestFinal` finishes a multi-part digest operation by returning the complete digest and
clearing the operation context. If `pDigest` is NULL the length of the digest is returned and
`FC_DigestFinal` may be called again with `pDigest` set to retrieve the digest.

A user may call `FC_DigestFinal` without logging into the token (to assume the NSS User role).
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-digestinit`,
  [NSC_DigestFinal](/en-US/NSC_DigestFinal)
:::
