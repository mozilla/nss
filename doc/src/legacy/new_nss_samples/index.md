(mozilla-projects-nss-new-nss-samples)=

# New NSS Samples

(new-nss-sample-code)=

## New NSS Sample Code

:::{container}
This collection of sample code demonstrates how NSS can be used for cryptographic operations,
certificate handling, SSL, etc. It also demonstrates some best practices in the application of
cryptography.

These new examples are a work in progress. See

<https://bugzilla.mozilla.org/show_bug.cgi?id=490238>

How to download the samples:

```{code} sh
hg clone https://hg.mozilla.org/projects/nss; cd nss; hg update SAMPLES_BRANCH
```

Samples list:

1. {ref}`mozilla_projects_nss_nss_sample_code_sample1_-_hashing`
2. {ref}`mozilla_projects_nss_nss_sample_code_sample2_-_initialize_nss_database`
3. {ref}`mozilla-projects-nss-encrypt-decrypt-mac-using-token`
4. {ref}`mozilla-projects-nss-encrypt-decrypt-mac-keys-as-session-objects`
5. {ref}`mozilla-projects-nss-nss-sample-code-enc-dec-mac-output-plblic-key-as-csr`
6. {ref}`mozilla-projects-nss-nss-sample-code-enc-dec-mac-using-key-wrap-certreq-pkcs10-csr`

Common code used by these samples:

1. {ref}`mozilla-projects-nss-nss-sample-code-utiltiies-for-nss-samples`

Thanks are due to Shailendra Jain, Mozilla Community member, who is the principal author of these
samples.
:::
