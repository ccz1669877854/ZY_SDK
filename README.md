# ZY_SDK
v1.1 2019-06-29


/************************************************/

1、RTSPServer

rtsp服务端，支持多个通道，根据主控芯片的编码性能，可以选择通道的数量。

默认地址为两类：rtsp://ip:554/ZY_stream_ch%d/h264或者rtsp://ip:554/ZY_stream_ch%d/h265,"%d"为通道号，比如通道号为0，码流为H.265，地址为rtsp://ip:554/ZY_stream_ch0/h265.

比如通道号为1，码流为H.264，地址为rtsp://ip:554/ZY_stream_ch1/h264.

1.1 int ZY_MPI_RtspServer_Init();

参数：无
返回：0：成功，-1：失败；

int ZY_MPI_RtspServer_UnInit();

参数：无
返回：0：成功，-1：失败；

int ZY_MPI_RtspServer_CreateChn(unsigned int rtspChn,ZY_RTSP_ATTR attr);

参数：1：通道号；2：rtsp服务端的属性，可以选择码流种类，需要跟实际编码格式对应，否则解析不了数据。
返回：0：成功，返回其他参数查看错误码；
int ZY_MPI_RtspServer_SendVideoFrame(unsigned int rtspChn,unsigned char *pdata ,unsigned int length,unsigned long long int pts,ZY_CodecType  type);
int ZY_MPI_RtspServer_SendAudioFrame(unsigned int rtspChn,unsigned char *pdata ,unsigned int length,unsigned long long int pts,ZY_CodecType  type);

/************************************************/

2、 RTMP push
int ZY_MPI_RtmpPush_Init();

int ZY_MPI_RtmpPush_CreateChn(unsigned int rtmpChn,const char * purl,RTMP_ATTR attr);

int ZY_MPI_RtmpPush_DestroyChn(unsigned int rtmpChn,RTMP_TYPE type);

int ZY_MPI_RtmpPush_SendVideoFrame(unsigned int rtmpChn,const char *pdata ,unsigned int length,unsigned long long int pts);

int ZY_MPI_RtmpPush_SendAudioFrame(unsigned int rtmpChn,const char *pdata ,unsigned int length,unsigned long long int pts);



