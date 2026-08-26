(mozilla-projects-nss-reference-fc-digest)=

# FC_Digest

## Name

:::{container}
FC_Digest - digest a block of data.
:::

## Syntax

:::{container}

```{code}
CK_RV FC_Digest(
  CK_SESSION_HANDLE hSession,
  CK_BYTE_PTR pData,
  CK_ULONG usDataLen,
  CK_BYTE_PTR pDigest,
  CK_ULONG_PTR pusDigestLen
);
```

:::

## Parameters

:::{container}
`hSession`

: [in] session handle.

`pData`

: [in] pointer to data block.

`usDataLen`

: [in] length of the data in bytes.

`pDigest`

: [out] pointer to location where recovered data is to be stored.

`pusDigestLen`

: [in, out] pointer to the maximum size of the output buffer, replaced by the length of the
  message digest if the operation is successful.
:::

## Description

:::{container}
`FC_Digest` digests a message in a single operation according to the attributes of the previous
call to `FC_DigestInit`.

A user may call `FC_Digest` without logging into the token (to assume the NSS User role).
:::

## Return value

## Examples

## See also

:::{container}

- {ref}`mozilla-projects-nss-reference-fc-digestinit`, [NSC_Digest](/en-US/NSC_Digest)
:::
