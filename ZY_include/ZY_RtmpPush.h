#ifndef __ZY_RTMPPUSH_H__
#define __ZY_RTMPPUSH_H__



#define MAX_RTMPPUSH_CHANNEL 8

#define ZY_ERR_RTMPPUSH_INVALID_CHNID 	 	0xA0B08000
#define ZY_ERR_RTMPPUSH_INVALID_FILEPATH 	0xA0B08001
#define ZY_ERR_RTMPPUSH_INVALID_OPENFILE 	0xA0B08002
#define ZY_ERR_RTMPPUSH_INVALID_CODECID 	0xA0B08003
#define ZY_ERR_RTMPPUSH_INVALID_NOSUPPORT	0xA0B08004
#define ZY_ERR_RTMPPUSH_INVALID_CHNEXIST 	0xA0B08005
#define ZY_ERR_RTMPPUSH_INVALID_PUSH		0xA0B08006
#define ZY_ERR_RTMPPUSH_INVALID_PARAM		0xA0B08007
#define ZY_ERR_RTMPPUSH_INVALID_CHNUNEXIST 	0xA0B08008
#define ZY_ERR_RTMPPUSH_INVALID_THREAD 		0xA0B08009


typedef enum _RTMP_TYPE
{
	RTMP_H264,
	RTMP_H265,
	RTMP_H264_AAC,
	RTMP_H265_AAC,
	RTMP_IGNORE
} RTMP_TYPE;

typedef struct _RTMP_ATTR
{
	RTMP_TYPE  type;
	int ChunkSize; //-1 defaut 
	int MessageBiggestSize;//-1 defaut 
} RTMP_ATTR;


int ZY_MPI_RtmpPush_Init();

int ZY_MPI_RtmpPush_CreateChn(unsigned int rtmpChn,const char * purl,RTMP_ATTR attr);
int ZY_MPI_RtmpPush_DestroyChn(unsigned int rtmpChn,RTMP_TYPE type);
int ZY_MPI_RtmpPush_SendVideoFrame(unsigned int rtmpChn,const char *pdata ,unsigned int length,unsigned long long int pts);
int ZY_MPI_RtmpPush_SendAudioFrame(unsigned int rtmpChn,const char *pdata ,unsigned int length,unsigned long long int pts);




#endif 



