# ZY_SDK
v1.1 2019-06-29


/************************************************/

1、RTSPServer

1.1 int ZY_MPI_RtspServer_Init();
参数：无
返回：0：成功，-1：失败；

int ZY_MPI_RtspServer_UnInit();
参数：无
返回：0：成功，-1：失败；

int ZY_MPI_RtspServer_CreateChn(unsigned int rtspChn,ZY_RTSP_ATTR attr);
int ZY_MPI_RtspServer_SendVideoFrame(unsigned int rtspChn,unsigned char *pdata ,unsigned int length,unsigned long long int pts,ZY_CodecType  type);
int ZY_MPI_RtspServer_SendAudioFrame(unsigned int rtspChn,unsigned char *pdata ,unsigned int length,unsigned long long int pts,ZY_CodecType  type);

/************************************************/

2、 RTMP push
int ZY_MPI_RtmpPush_Init();

int ZY_MPI_RtmpPush_CreateChn(unsigned int rtmpChn,const char * purl,RTMP_ATTR attr);

int ZY_MPI_RtmpPush_DestroyChn(unsigned int rtmpChn,RTMP_TYPE type);

int ZY_MPI_RtmpPush_SendVideoFrame(unsigned int rtmpChn,const char *pdata ,unsigned int length,unsigned long long int pts);

int ZY_MPI_RtmpPush_SendAudioFrame(unsigned int rtmpChn,const char *pdata ,unsigned int length,unsigned long long int pts);



