
#ifndef __ZY_MUXERBUF_H_
#define __ZY_MUXERBUF_H_

#include <stdint.h>
#include <sys/uio.h>

#define MUXER_CACHED         (0x1)
#define MUXER_RDONLY         (0x2)
#define MUXER_WRONLY         (0x4)
#define MUXER_OLDEST         (0x8)

int Muxer_MkFifo(char *name, size_t size);
int Muxer_UnLink(char *name);

long Muxer_Open(char *name, int mode);
int Muxer_Close(long handle);

ssize_t Muxer_Write(long handle, void *buf, size_t nbyte);
ssize_t Muxer_Read (long handle, void *buf, size_t nbyte, int milliseconds);

ssize_t Muxer_WriteV(long handle, struct iovec *iov, size_t iovcnt);
ssize_t Muxer_ReadV (long handle, struct iovec *iov, size_t iovcnt, int milliseconds);

ssize_t Muxer_WriteBlock(long handle, size_t maxsize, ssize_t (*write_cb)(struct iovec *iovs, int iovcnt, void *priv_data), void *priv_data);

int Muxer_Left(long handle);
int Muxer_ForEach(long handle, int (*cb)(struct iovec *iovs, int iovcnt, void *priv_data), void *priv_data);

int Muxer_Reset(long handle);

#endif /* __MUXER_H_ */
