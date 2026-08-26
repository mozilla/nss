(mozilla-projects-nss-reference-nspr-functions)=

# NSPR functions

:::{container}
[NSPR](https://www.mozilla.org/projects/nspr/) is a platform abstraction library that provides
a cross-platform API to common OS services. NSS uses NSPR internally as the porting layer.
However, a small number of NSPR functions are required for using the certificate verification and
SSL functions in NSS. These NSPR functions are listed in this section.
:::

(nspr-initialization-and-shutdown)=

## NSPR initialization and shutdown

:::{container}
NSPR is automatically initialized by the first NSPR function called by the application. Call
`` `PR_Cleanup `` \</en-US/PR_Cleanup>\`\_\_ to shut down NSPR and clean up its resources.

- [PR_Cleanup](/en-US/PR_Cleanup)
:::

(error-reporting)=

## Error reporting

:::{container}
NSS uses NSPR's thread-specific error code to report errors. Call
`` `PR_GetError `` \</en-US/PR_GetError>\`\_\_ to get the error code of the last failed NSS or NSPR
function. Call `` `PR_SetError `` \</en-US/PR_SetError>\`\_\_ to set the error code, which can be
retrieved with `PR_GetError` later.

The NSS functions `PORT_GetError` and `PORT_SetError` are simply wrappers of `PR_GetError`
and `PR_SetError`.

- [PR_GetError](/en-US/PR_GetError)
- [PR_SetError](/en-US/PR_SetError)
:::

(calendar-time)=

## Calendar time

:::{container}
NSS certificate verification functions take a `PRTime` parameter that specifies the time
instant at which the validity of the certificate should verified. The NSPR function
`` `PR_Now `` \</en-US/PR_Now>\`\_\_ returns the current time in `PRTime`.

- [PR_Now](/en-US/PR_Now)
:::

(interval-time)=

## Interval time

:::{container}
The NSPR socket I/O functions `` `PR_Recv `` \</en-US/PR_Recv>\`\_\_ and
`` `PR_Send `` \</en-US/PR_Send>\`\_\_ (used by the NSS SSL functions) take a `PRIntervalTime`
timeout parameter. `PRIntervalTime` has an abstract, platform-dependent time unit. Call
`` `PR_SecondsToInterval `` \</en-US/PR_SecondsToInterval>\`\_\_ or `PR_MillisecondsToInterval` to
convert a time interval in seconds or milliseconds to `PRIntervalTime`.

- [PR_SecondsToInterval](/en-US/PR_SecondsToInterval)
- [PR_MillisecondsToInterval](/en-US/PR_MillisecondsToInterval)
:::

(nspr-io-layering)=

## NSPR I/O layering

:::{container}
NSPR file descriptors can be layered, corresponding to the layers in the network stack. The SSL
library in NSS implements the SSL protocol as an NSPR I/O layer, which sits on top of another
NSPR I/O layer that represents TCP.

You can implement an NSPR I/O layer that wraps your own TCP socket code. The following NSPR
functions allow you to create your own NSPR I/O layer and manipulate it.

- [PR_GetUniqueIdentity](/en-US/PR_GetUniqueIdentity)
- [PR_CreateIOLayerStub](/en-US/PR_CreateIOLayerStub)
- [PR_GetDefaultIOMethods](/en-US/PR_GetDefaultIOMethods)
- [PR_GetIdentitiesLayer](/en-US/PR_GetIdentitiesLayer)
- [PR_GetLayersIdentity](/en-US/PR_GetLayersIdentity)
- [PR_PushIOLayer](/en-US/PR_PushIOLayer)
- [PR_PopIOLayer](/en-US/PR_PopIOLayer)
:::

(wrapping-a-native-file-descriptor)=

## Wrapping a native file descriptor

:::{container}
If your current TCP socket code uses the standard BSD socket API, a lighter-weight method than
creating your own NSPR I/O layer is to simply import a native file descriptor into NSPR. This
method is convenient and works for most applications.

- [PR_ImportTCPSocket](/en-US/PR_ImportTCPSocket)
:::

(socket-io-functions)=

## Socket I/O functions

:::{container}
As mentioned above, the SSL library in NSS implements the SSL protocol as an NSPR I/O layer.
Users call NSPR socket I/O functions to read from, write to, and shut down an SSL connection, and
to close an NSPR file descriptor.

- [PR_Read](/en-US/PR_Read)
- [PR_Write](/en-US/PR_Write)
- [PR_Recv](/en-US/PR_Recv)
- [PR_Send](/en-US/PR_Send)
- [PR_GetSocketOption](/en-US/PR_GetSocketOption)
- [PR_SetSocketOption](/en-US/PR_SetSocketOption)
- [PR_Shutdown](/en-US/PR_Shutdown)
- [PR_Close](/en-US/PR_Close)
:::
