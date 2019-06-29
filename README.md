# ZY_SDK API 说明，本SDK仅为海思SDK的补充，让开发海思应用功能更加简单，支持rtsp、rtmp、hls，常见IPC摄像头,录像、回放、字幕、台标、抓拍、U盘和硬盘管理等功能。
使用时需要把相应的头文件和库加进去。
v1.1 2019-06-29 


/************************************************/

1、RTSPServer

rtsp服务端，支持多个通道，根据主控芯片的编码性能，可以选择通道的数量。支持H.265，H.264，音频，视频等。

默认地址为两类：rtsp://ip:554/ZY_stream_ch%d/h264或者rtsp://ip:554/ZY_stream_ch%d/h265,"%d"为通道号，比如通道号为0，码流为H.265，地址为rtsp://ip:554/ZY_stream_ch0/h265.

比如通道号为1，码流为H.264，地址为rtsp://ip:554/ZY_stream_ch1/h264.

1.1 int ZY_MPI_RtspServer_Init();

功能：初始化rtsp服务端

参数：无

返回：0：成功，-1：失败；


1.2 int ZY_MPI_RtspServer_UnInit();

功能：退出rtsp服务端

参数：无

返回：0：成功，-1：失败；


1.3 int ZY_MPI_RtspServer_CreateChn(unsigned int rtspChn,ZY_RTSP_ATTR attr);

功能：创建一个rtsp服务端通道，具体通道号发送音视频数据。

参数：1：通道号；2：rtsp服务端的属性，可以选择码流种类，需要跟实际编码格式对应，否则解析不了数据。

返回：0：成功，返回其他参数查看错误码；

1.4 int ZY_MPI_RtspServer_SendVideoFrame(unsigned int rtspChn,unsigned char *pdata ,unsigned int length,unsigned long long int pts,ZY_CodecType  type);

功能：发送视频数据，海思编码后把数据之间填进来，支持按帧，按包格式发送。


参数：1：通道号；2：数据；参数3：长度；参数4：时间戳，时间戳为-1为自动时间戳，API会自动处理，默认建议用户填写-1；参数5：编码类别。


返回：0：成功，返回其他参数查看错误码；


1.5 int ZY_MPI_RtspServer_SendAudioFrame(unsigned int rtspChn,unsigned char *pdata ,unsigned int length,unsigned long long int pts,ZY_CodecType  type);

功能：发送音频数据，海思编码后把数据之间填进来，支持按帧，按包格式发送。

参数：1：通道号；2：数据；参数3：长度；参数4：时间戳，时间戳为-1为自动时间戳，API会自动处理，默认建议用户填写-1；参数5：编码类别。

返回：0：成功，返回其他参数查看错误码；

/************************************************/

2、 RTMP push

rtmp推流，支持多个通道，根据主控芯片的编码性能，可以选择通道的数量。支持H.264，音频，视频等。

2.1 int ZY_MPI_RtmpPush_Init();

功能：初始化rtmp推流

参数：无

返回：0：成功，-1：失败；

2.2 int ZY_MPI_RtmpPush_CreateChn(unsigned int rtmpChn,const char * purl,RTMP_ATTR attr);

功能：创建一个rtmp推流通道，具体通道号发送音视频数据。

参数：1：通道号；2：推流地址；3：rtmp推流的属性

返回：0：成功，返回其他参数查看错误码；

2.3 int ZY_MPI_RtmpPush_DestroyChn(unsigned int rtmpChn,RTMP_TYPE type);

功能：销毁一个rtmp推流通道
参数：1：通道号；2：rtmp类型

返回：0：成功，返回其他参数查看错误码；


2.4 int ZY_MPI_RtmpPush_SendVideoFrame(unsigned int rtmpChn,const char *pdata ,unsigned int length,unsigned long long int pts);

功能：发送音频数据，海思编码后把数据之间填进来，支持按帧，按包格式发送。

参数：1：通道号；2：数据；参数3：长度；参数4：时间戳，时间戳为-1为自动时间戳，API会自动处理，默认建议用户填写-1；

返回：0：成功，返回其他参数查看错误码；

2.5 int ZY_MPI_RtmpPush_SendAudioFrame(unsigned int rtmpChn,const char *pdata ,unsigned int length,unsigned long long int pts);

功能：发送音频数据，海思编码后把数据之间填进来，支持按帧，按包格式发送。

参数：1：通道号；2：数据；参数3：长度；参数4：时间戳，时间戳为-1为自动时间戳，API会自动处理，默认建议用户填写-1；

返回：0：成功，返回其他参数查看错误码；


/************************************************/

3、 hls push

hls推流使用rtmp转换，配置好相关的推流服务器即可，这里没有API说明。

/************************************************/

4、 录像，录像支持常见的格式录像，MP4、FLV、MKV、TS等。

4.1 int ZY_MPI_Muxer_Init();

功能：初始化录像；

参数：无；

返回：0：成功，返回其他参数查看错误码；

4.2 int ZY_MPI_Muxer_CreateChn(unsigned int chn,ZY_MUXER_ATTR * pMuxerAttr);

功能：创建录像，开始录像

参数：1：通道号；参数2：录像的属性

返回：0：成功，返回其他参数查看错误码；

4.3 int ZY_MPI_Muxer_DetroyChn(unsigned int chn);

功能：销毁录像，停止录像

参数：1：通道号；

返回：0：成功，返回其他参数查看错误码；


4.4 int ZY_MPI_Muxer_PauseChn(unsigned int chn,ZY_MUXER_IS_PAUSE isPause);

功能：暂停录像

参数：1：通道号；2：暂停、恢复录像

返回：0：成功，返回其他参数查看错误码；


4.5 int ZY_MPI_Muxer_SendVideoFrame(unsigned int chn,unsigned char * pdata ,unsigned int size);

功能：发送视频数据，海思编码后把数据之间填进来，支持按帧，按包格式发送。

参数：1：通道号；2：数据；参数3：长度；

返回：0：成功，返回其他参数查看错误码；

4.6 int ZY_MPI_Muxer_SendAudioFrame(unsigned int chn,unsigned char * pdata ,unsigned int size);

功能：发送音频数据，海思编码后把数据之间填进来，支持按帧，按包格式发送。

参数：1：通道号；2：数据；参数3：长度；

返回：0：成功，返回其他参数查看错误码；






