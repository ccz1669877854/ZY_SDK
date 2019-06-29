
#ifndef __ZY_RTMPBUF_H_
#define __ZY_RTMPBUF_H_


#include <stdint.h>
#include <sys/uio.h>

#define ZY_RTMP_CACHED         (0x1)
#define ZY_RTMP_RDONLY         (0x2)
#define ZY_RTMP_WRONLY         (0x4)
#define ZY_RTMP_OLDEST         (0x8)

int ZY_RTMP_MkFifo(char *name, size_t size);
int ZY_RTMP_UnLink(char *name);

long ZY_RTMP_Open(char *name, int mode);
int ZY_RTMP_Close(long handle);

ssize_t ZY_RTMP_Write(long handle, void *buf, size_t nbyte);
ssize_t ZY_RTMP_Read (long handle, void *buf, size_t nbyte, int milliseconds);

ssize_t ZY_RTMP_WriteV(long handle, struct iovec *iov, size_t iovcnt);
ssize_t ZY_RTMP_ReadV (long handle, struct iovec *iov, size_t iovcnt, int milliseconds);

ssize_t ZY_RTMP_WriteBlock(long handle, size_t maxsize, ssize_t (*write_cb)(struct iovec *iovs, int iovcnt, void *priv_data), void *priv_data);

int ZY_RTMP_Left(long handle);
int ZY_RTMP_ForEach(long handle, int (*cb)(struct iovec *iovs, int iovcnt, void *priv_data), void *priv_data);

int ZY_RTMP_Reset(long handle);

#endif /* __ZY_RTMP_H_ */
