# ZY_SDK API 说明，本SDK仅为海思SDK的补充，让开发海思应用功能更加简单，支持rtsp、rtmp、hls，常见IPC摄像头,录像、回放、字幕、台标、抓拍、U盘和硬盘管理等功能。
使用时需要把相应的头文件和库加进去。

v1.1 2019-06-29 版权归深圳市知扬科技所有  电话：13342993362  陈生


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

/************************************************/

5、回放模块，支持本地文件回放、rtsp IPC、rtmp 拉流等功能。

5.1 int ZY_MPI_Demux_Init();

功能：初始化Demux模块；

参数：无；

返回：0：成功，返回其他参数查看错误码；


5.2 int ZY_MPI_Demux_CreateChn(unsigned int Chn,const char * pstring);

功能：创建Demux通道，打开指定的URL文件或者地址

参数：1：通道号；参数2：URL

返回：0：成功，返回其他参数查看错误码；

5.3 int ZY_MPI_Demux_DestroyChn(unsigned int Chn);

功能：销毁Demux通道

参数：1：通道号；

返回：0：成功，返回其他参数查看错误码；

5.4 int ZY_MPI_Demux_GetFrame(unsigned int Chn,unsigned char ** ppdata ,unsigned int * psize);

功能：获取一帧数据，Get和Release配对使用

参数：1：通道号；2：获取到的数据，需要双重指针；3：获取到的长度

返回：0：成功，返回其他参数查看错误码；


5.5 int ZY_MPI_Demux_ReleaseFrame(unsigned int Chn,unsigned char * pdata ,unsigned int size);


功能：释放一帧数据，Get和Release配对使用

参数：1：通道号；2：数据；3：数据长度

返回：0：成功，返回其他参数查看错误码；

5.6 int ZY_MPI_Demux_BindVdecAdec(unsigned int chn,ZY_DEMUXBIND_ATTR Attr);
功能：绑定指定的Demux通道到海思解码器，绑定后会自动关联解码器并把解码后的数据传输给VPSS.

参数：1：通道号；2：绑定属性

返回：0：成功，返回其他参数查看错误码；

5.7 int ZY_MPI_Demux_UnBindVdecAdec(unsigned int chn,ZY_DEMUXBIND_ATTR Attr);

功能：解绑指定的Demux通道到海思解码器

参数：1：通道号；2：绑定属性

返回：0：成功，返回其他参数查看错误码；


/************************************************/

6、字幕、台标、OSD、时间显示等功能，支持文字输入，BMP图片输入，PNG透明度图片输入

6.1 int ZY_MPI_OSD_CreateChn(int chn);

功能：创建OSD通道

参数：1：通道号；

返回：0：成功，返回其他参数查看错误码；

6.2 int ZY_MPI_OSD_DestroyChn(int chn);

功能：销毁OSD通道

参数：1：通道号；

返回：0：成功，返回其他参数查看错误码；

6.3 int ZY_MPI_OSD_SetChnAttr(int chn,ZY_OSD_ATTR_S attr);

功能：设置OSD通道属性

参数：1：通道号；2：OSD属性

返回：0：成功，返回其他参数查看错误码；

6.4 int ZY_MPI_OSD_GetChnAttr(int chn,ZY_OSD_ATTR_S * pattr);

功能：获取OSD通道属性

参数：1：通道号；2：OSD属性

返回：0：成功，返回其他参数查看错误码；

6.5 int ZY_MPI_OSD_BindDst(int OsdChn,ZY_OSD_DST_ATTR dstAttr,ZY_BOOL show,ZY_OSD_SHOW_ATTR_S showAttr);

功能：绑定OSD到指定的VPSS显示，这是由于海思的框架决定

参数：1：通道号；2：绑定属性；3：是否显示OSD；4：显示属性

返回：0：成功，返回其他参数查看错误码；


6.6 int ZY_MPI_OSD_UnBindDst(int OsdChn,ZY_OSD_DST_ATTR dstAttr);

功能：解绑OSD到指定的VPSS显示

参数：1：通道号；2：绑定属性

返回：0：成功，返回其他参数查看错误码；

6.7 int ZY_MPI_OSD_ShowEnable(int OsdChn,ZY_OSD_DST_ATTR dstAttr,ZY_BOOL show,unsigned int u32X,unsigned int u32Y);


功能：使能显示，可以切换关闭或者显示

参数：1：通道号；2：绑定属性；3：是否显示OSD；4：X位置；5：Y位置

返回：0：成功，返回其他参数查看错误码；

6.8 int ZY_MPI_OSD_SetShowPoint(int OsdChn,ZY_OSD_DST_ATTR dstAttr,unsigned int u32X,unsigned int u32Y);

功能：设置显示位置

参数：1：通道号；2：绑定属性；3：是否显示OSD；4：X位置；5：Y位置

返回：0：成功，返回其他参数查看错误码；

6.9 int ZY_MPI_OSD_SetShow(int OsdChn,const char* pName,ZY_OSD_SRC_TYPE srcType,unsigned int color,unsigned int fontSize,unsigned int * pWidth,unsigned int * pHeight,ZY_BOOL autoShow);

功能：设置显示属性

参数：1：通道号；2：需要显示的字符；3：显示类型，文字、图片等类型；4：文字颜色，仅对文字有效，图片无效；5:文字大小，字号，仅对文字有效；6：实际显示的占用的宽，比如创建OSD宽为1920，但是显示10个字符的长度仅为100像素。7：实际高度，比如字体为36，获取字体的实际高度。

返回：0：成功，返回其他参数查看错误码；

/************************************************/

7、抓拍JPEG图片，自动把抓拍到的图片保存到指定路径

7.1 int ZY_MPI_Snap_StartJPEG(int VencChn,unsigned int u32Width,unsigned int u32Height);

功能：启动抓拍，立刻生效

参数：1：指令抓拍用哪个编码器编码；2：宽；3：高

返回：0：成功，返回其他参数查看错误码；

7.2 int ZY_MPI_Snap_StopJPEG(int VencChn);

功能：停止抓拍，立刻生效

参数：1：指令抓拍用哪个编码器编码；

返回：0：成功，返回其他参数查看错误码；

7.3 int ZY_MPI_Snap_SAVEJPEG(int vpssGroup,int vpssChn,int VencChn,const char * pFileName,unsigned int u32Width,unsigned int u32Height,int timeOut);

功能：保存抓拍到的数据到指定的通道

参数：1：VPSS组号，也即为数据来源；2：VPSS 通道号；3：编码器号；4：保存文件名和路径；5：长；6：宽；7：设置多长超时返回；

返回：0：成功，返回其他参数查看错误码；

/************************************************/

8、U盘和SATA硬盘热插拔管理，支持一个U盘和一个SATA硬盘的自动管理，U盘自动挂载在/tmp/usbDisk，SATA硬盘自动挂载在/tmp/hardDisk

8.1 void ZY_MPI_UDiskOrHardDisk_Init();

功能：初始化硬盘挂载

参数：无

返回：0：无
8.2 int ZY_MPI_UDiskOrHardDisk_HotPlug_Start();

功能：启动硬盘自动挂载

参数：无

返回：0：成功，返回其他参数查看错误码；

8.3 int ZY_MPI_UDiskOrHardDisk_HotPlug_Stop();

功能：停止硬盘自动挂载

参数：无

返回：0：成功，返回其他参数查看错误码；

/************************************************/

9、QT支持，自动配置QT FB，使用此函数后，不需要关心QT FB配置
9.1 int ZY_MPI_FB_Open(int fb,int width,int height);


功能：初始化QT FB配置

参数：1：指定的fB；2：设置FB的宽；3：设置FB的高

返回：0：成功，返回其他参数查看错误码；

