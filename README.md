# ZY_SDK API 说明，本SDK仅为海思SDK的补充，让开发海思应用功能更加简单，支持rtsp、rtmp、hls，常见IPC摄像头,录像、回放、字幕、台标、抓拍、U盘和硬盘管理等功能。
使用时需要把相应的头文件和库加进去。库依赖FFmpeg，需要把FFmpeg解压并配置好Makefile，依赖libZY_Media.so，相关的动态库需要复制到板子并配置好环境，如果是购买开发板，一般情况已经配置好。文件夹需要把ZY_include包含进去。

v1.4 2019-06-29 版权归深圳市知扬科技所有  电话：13342993362  陈生


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

1.6 数据类型

1.6.1 RTSP_TYPE，流类型选择，是否有音频

typedef enum _RTSP_TYPE

{

	RTSP_H264 = 1,//只要H.264流视频
	
	RTSP_H265,//只要H.265流视频
	
	RTSP_H264_AAC,//H.264+AAC流
	
	RTSP_H265_AAC,//H.265+AAC流
	
} RTSP_TYPE;



1.6.2 ZY_RTSP_ATTR，rtsp属性结构体

typedef struct _ZY_RTSP_ATTR

{

	ZY_AUDIO_SOUND_MODE_E enSoundmode; //音频声道
	
	ZY_AUDIO_SAMPLERATE samplerate;    //音频采样率
	
	RTSP_TYPE type;                   //rtsp流类型
	
	

} ZY_RTSP_ATTR;



1.7 错误码

#define ZY_ERR_RTSPSERVER_INVALID_CHNID  	0xA0B08000

#define ZY_ERR_RTSPSERVER_INVALID_FILEPATH 	0xA0B08001

#define ZY_ERR_RTSPSERVER_INVALID_OPENFILE 	0xA0B08002

#define ZY_ERR_RTSPSERVER_INVALID_CODECID 	0xA0B08003

#define ZY_ERR_RTSPSERVER_INVALID_NOSUPPORT	0xA0B08004

#define ZY_ERR_RTSPSERVER_INVALID_CHNEXIST 	0xA0B08005

#define ZY_ERR_RTSPSERVER_INVALID_OPENCODEC 0xA0B08006

#define ZY_ERR_RTSPSERVER_INVALID_PARAM		0xA0B08007

#define ZY_ERR_RTSPSERVER_INVALID_CHNUNEXIST 	0xA0B08008

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

2.6 数据类型

2.6.1 RTMP类型

typedef enum _RTMP_TYPE

{

	RTMP_H264, //只有H.264视频
	
	RTMP_H265, //只有H.265视频
	
	RTMP_H264_AAC,  //AAC+H.264
	
	RTMP_H265_AAC,  //AAC+H.265
	
	RTMP_IGNORE //自动类型
	
} RTMP_TYPE;


2.6.2 RTMP属性

typedef struct _RTMP_ATTR

{

	RTMP_TYPE  type;
	
	int ChunkSize; //-1 defaut ，ChunkSize;
	
	int MessageBiggestSize;//-1 defaut ，MessageBiggestSize
	
} RTMP_ATTR;


2.7 错误码

#define ZY_ERR_RTMPPUSH_INVALID_CHNID 	 	0xA0B09000

#define ZY_ERR_RTMPPUSH_INVALID_FILEPATH 	0xA0B09001

#define ZY_ERR_RTMPPUSH_INVALID_OPENFILE 	0xA0B09002

#define ZY_ERR_RTMPPUSH_INVALID_CODECID 	0xA0B09003

#define ZY_ERR_RTMPPUSH_INVALID_NOSUPPORT	0xA0B09004

#define ZY_ERR_RTMPPUSH_INVALID_CHNEXIST 	0xA0B09005

#define ZY_ERR_RTMPPUSH_INVALID_PUSH		0xA0B09006

#define ZY_ERR_RTMPPUSH_INVALID_PARAM		0xA0B09007

#define ZY_ERR_RTMPPUSH_INVALID_CHNUNEXIST 	0xA0B09008

#define ZY_ERR_RTMPPUSH_INVALID_THREAD 		0xA0B09009


/************************************************/

3、 hls push

hls推流使用rtmp转换，配置好相关的推流服务器即可，这里没有API说明。

/************************************************/

4、 录像，录像支持常见的格式录像，MP4、FLV、AVI、TS等。

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

4.7 数据类型

4.7.1 编码类型

typedef enum {

	ZY_H264   =0,
	
	ZY_H265   =1,
	
}ZY_VECN_TYPE;


4.7.2 录像文件类型

typedef enum {

	ZY_ONLYVIDEO   =0, //只有视频
	
	ZY_ONLYAUDIO   =1, //只有音频
	
	ZY_VIDEOAUDIO  =2, //具有音视频


}ZY_MUXER_TYPE;


4.7.3 暂停和正常运行枚举

typedef enum {

	ZY_MUXER_RUN  =0, //运行
	
	ZY_MUXER_PAUSE   =1, //暂停
	

}ZY_MUXER_IS_PAUSE;

4.7.4 录像属性结构体

typedef struct _ZY_MUXER_ATTR

{

	//video
	
	char fileName[512]; //录像文件名
	
	unsigned int width; //视频宽
	
	unsigned int height; //视频高
	
	ZY_PIC_FPS fps; //帧率
	
	ZY_VECN_TYPE vencType; //编码类型

	//audio
	
	ZY_AUDIO_BIT_WIDTH_E bitWidth; //音频数据宽度
	
	ZY_AUDIO_SOUND_MODE_E chnMode; //声道模式
	
	ZY_AUDIO_SAMPLERATE sample_rate; //采样率
	
	ZY_AUDIO_BIT_RATE_E bitRate;   //比特率
	

	ZY_MUXER_TYPE type;
	


}ZY_MUXER_ATTR,* pZY_MUXER_ATTR;


4.8 错误码

#define ZY_ERR_MUXER_INVALID_CHNID  0xA0A0A000

#define ZY_ERR_MUXER_INVALID_FILEPATH 0xA0A0A001

#define ZY_ERR_MUXER_INVALID_CREATEFILE 0xA0A0A002

#define ZY_ERR_MUXER_INVALID_CODECID 0xA0A0A003

#define ZY_ERR_MUXER_INVALID_PARAM 0xA0A0A004

#define ZY_ERR_MUXER_INVALID_DESTROYFILE 0xA0A0A005

#define ZY_ERR_MUXER_INVALID_THREAD 	0xA0B0A006

#define ZY_ERR_MUXER_INVALID_CHNEXIT 	0xA0B0A007

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


5.8 数据类型

5.8.1 解码数据类型

enum DEMUX_TYPE

{

DEMUX_AUDIO = 0,  //音频数据

DEMUX_VIDEO = 1,  //视频数据


};

5.8.2 视频格式类型

typedef enum _ZY_VIDEO_TYPE

{

VIDEO_TYPE_H264 = 0, //H.264

VIDEO_TYPE_H265 = 1, //H.265

VIDEO_TYPE_JPEG = 2, //JPEG


}ZY_VIDEO_TYPE;

5.8.3 解码播放状态

typedef enum _ZY_DemuxCtrlSignal

{

    DEMUX_CTRL_STOP = 0,  //停止运行
	
    DEMUX_CTRL_SEEK,      //拖动或者快进
	
    DEMUX_CTRL_PAUSE,     //暂停
    
    DEMUX_CTRL_START,     //开始或者恢复正常运行

}ZY_DemuxCtrlSignal;

5.8.4 运行模式选择

typedef enum _ZY_TimeStampMode

{

    ZY_TIMESTAMP_MODE_FULL = 0, //no sleep，即全速运行，对IPC、流媒体适用
	
    ZY_TIMESTAMP_MODE_SYNC,    // sync with time stamp，同步运行，对本地文件适用
    
    ZY_TIMESTAMP_MODE_BLOCK,  //block time，堵塞固定时间运行，可以根据播放状态调整

}ZY_TimeStampMode;

5.8.5 解码器和解码URL绑定属性

typedef struct _ZY_DEMUXBIND_ATTR

{

	//video
	
	int VdecBlock; //视频堵塞解码


	//audio
	int AdecBlock; //音频堵塞解码


	//chn
	unsigned int chn;  //解码器通道，海思实际解码器

	ZY_TimeStampMode timeMode;  //运行模式

	unsigned int usBlock;  //ZY_TIMESTAMP_MODE_BLOCK  effective，运行模式为ZY_TIMESTAMP_MODE_BLOCK时，堵塞时间

	ZY_DemuxCtrlSignal ctrl; //运行状态配置


}ZY_DEMUXBIND_ATTR,* pZY_DEMUXBIND_ATTR;

5.8.6 播放器状态

typedef enum _ZY_DEMUXSTATE{

    ZY_DEMUXSTATE_LOST = 1, //码率断开
    
    ZY_DEMUXSTATE_EOF = 2,  //结束
    
    ZY_DEMUXSTATE_TIMEOUT = 3,  //超时
    
    ZY_DEMUXSTATE_PAUSE = 4,    //暂停
    
    ZY_DEMUXSTATE_STOP = 5,    //停止 
    
    ZY_DEMUXSTATE_RUN = 6,     //正常运行
    
    ZY_DEMUXSTATE_SEEK = 7,    //拖动或快进快退
    
    ZY_DEMUXSTATE_ERROR = 8,   //错误

	
} ZY_DEMUXSTATE;

5.9 错误码

#define ZY_ERR_DEMUX_INVALID_CHNID  	0xA0B0B000

#define ZY_ERR_DEMUX_INVALID_FILEPATH 	0xA0B0B001

#define ZY_ERR_DEMUX_INVALID_OPENFILE 	0xA0B0B002

#define ZY_ERR_DEMUX_INVALID_CODECID 	0xA0B0B003

#define ZY_ERR_DEMUX_INVALID_NOSUPPORT	0xA0B0B004

#define ZY_ERR_DEMUX_INVALID_CHNEXIST 	0xA0B0B005

#define ZY_ERR_DEMUX_INVALID_OPENCODEC 0xA0B0B006

#define ZY_ERR_DEMUX_INVALID_PARAM		0xA0B0B007

#define ZY_ERR_DEMUX_INVALID_CHNUNEXIST 	0xA0B0B008

#define ZY_ERR_DEMUX_INVALID_THREAD 	0xA0B0B009

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

6.10 数据类型

6.10.1 OSD绑定目标

typedef enum _ZY_OSD_DST_TYPE

{

    ZY_OSD_BINDVI, //绑定到VI显示
    
    ZY_OSD_BINDVENC, //绑定到VENC显示
    
    ZY_OSD_BINDVPSS, //绑定到VPSS显示
    
} ZY_OSD_DST_TYPE;


6.10.2 OSD绑定目标熟悉

typedef struct _ZY_OSD_DST_ATTR

{

    ZY_OSD_DST_TYPE dstType;  //目标类型
	
    unsigned int dstChn;     //目标的通道号
	
    unsigned int Osdlayer;  //OSD的layer
	
} ZY_OSD_DST_ATTR;

6.10.3 OSD属性

typedef struct _ZY_OSD_ATTR_S

{

    /* bitmap pixel format*/
	
    ZY_PIXEL_FORMAT_E enPixelFmt;   //yuv数据格式

    /* background color, pixel format depends on "enPixelFmt" */
	
    unsigned int  u32BgColor;  //OSD背景颜色

    /* region size */
	
    Y_SIZE_S stSize;	//区域大小
	
    unsigned int u32CanvasNum; //区域的内存数量
	

}ZY_OSD_ATTR_S;

6.10.4 定义OSD 反色触发模式

typedef enum _ZY_INVERT_COLOR_MODE_E

{

    ZY_LESSTHAN_LUM_THRESH = 0,   /* the lum of the video is less than the lum threshold which is set by u32LumThresh  */ 
    
    ZY_MORETHAN_LUM_THRESH,       /* the lum of the video is more than the lum threshold which is set by u32LumThresh  */
    
    ZY_INVERT_COLOR_BUTT
    
}ZY_INVERT_COLOR_MODE_E;

6.10.5 定义OSD 反色相关属性

typedef struct _ZY_OSD_INVERT_COLOR_S

{

    ZY_SIZE_S              stInvColArea;                //it must be multipe of 16 but not more than 64.
    
    unsigned int              u32LumThresh;                //the threshold to decide whether invert the OSD's color or not.
    
    ZY_INVERT_COLOR_MODE_E enChgMod;      
    
    ZY_BOOL             bInvColEn;                   //the switch of inverting color.
    
}ZY_OSD_INVERT_COLOR_S;

6.10.6 定义OSD编码QP值
typedef struct _ZY_OSD_SHOW_QPINFO

{

    ZY_BOOL	 bQpDisable;
	
    ZY_BOOL  bAbsQp;
	
    int   s32Qp;
	
}ZY_OSD_SHOW_QPINFO;


6.10.6 定义显示属性
typedef struct _ZY_OSD_SHOW_ATTR_S

{

    /* start point */
	 
    ZY_POINT_S stPoint;
    
    /* foreground transparence */

    unsigned int u32FgAlpha; //default 255

    /* background transparence */
	
    unsigned int u32BgAlpha; //default 255

    /* QP infomation when venc*/
	
    ZY_OSD_SHOW_QPINFO stQpInfo;  

    /* invertColor infomation*/
	
    ZY_OSD_INVERT_COLOR_S stInvertColor;
}ZY_OSD_SHOW_ATTR_S;

6.10.7 定义显示位置

typedef enum _ZY_OSD_AUTO_POSITION

{

    AUTO_NULL = -1,
    
    AUTO_LEFT_TOP = 0,   
    
    AUTO_LEFT_BOTTOM,     
    
    AUTO_RIGHT_TOP,
    
    AUTO_RIGHT_BOTTOM,   
    
    AUTO_LEFT_MIDDLE,
    
    AUTO_RIGHT_MIDDLE,
    
    AUTO_CENTRE_TOP,   
    
    AUTO_CENTRE_MIDDLE, 
    
    AUTO_CENTRE_BOTTOM, 
    
}ZY_OSD_AUTO_POSITION;


6.11 错误码

#define ZY_ERR_OSD_INVALID_DEVID  		0xA0038001

#define ZY_ERR_OSD_INVALID_CHNID 		0xA0038002

#define ZY_ERR_OSD_ILLEGAL_PARAM	 	0xA0038003

#define ZY_ERR_OSD_EXIST 				0xA0038004

#define ZY_ERR_OSD_UNEXIST				0xA0038005

#define ZY_ERR_OSD_NULL_PTR			 	0xA0038006

#define ZY_ERR_OSD_NOT_CONFIG  			0xA0038007

#define ZY_ERR_OSD_NOT_SUPPORT			0xA0038008

#define ZY_ERR_OSD_NOT_PERM			 	0xA0038009

#define ZY_ERR_OSD_NOMEM				0xA003800C

#define ZY_ERR_OSD_NOBUF 				0xA003800D

#define ZY_ERR_OSD_BUF_EMPTY			0xA003800E

#define ZY_ERR_OSD_BUF_FULL				0xA003800F

#define ZY_ERR_OSD_NOTREADY				0xA0038010

#define ZY_ERR_OSD_BADADDR				0xA0038011

#define ZY_ERR_OSD_BUSY					0xA0038012



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

7.4 错误码

#define ZY_ERR_DEMUX_INVALID_VPSSDEPTH   0xA1B08000

#define ZY_ERR_DEMUX_INVALID_GETFRAME   0xA1B08001

#define ZY_ERR_DEMUX_INVALID_SENDFRAME   0xA1B08002

#define ZY_ERR_DEMUX_INVALID_JPEGFRAME   0xA1B08003

#define ZY_ERR_DEMUX_INVALID_VPSSMODE   0xA1B08004

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

8.4 错误码


#define ZY_ERR_UDISKORHARDDISK_INVALID_SECID 	0xA0D08001

#define ZY_ERR_UDISKORHARDDISK_INVALID_PARAM 	0xA0D08004

#define ZY_ERR_UDISKORHARDDISK_INVALID_THREAD 	0xA0D08006




/************************************************/

9、QT支持，自动配置QT FB，使用此函数后，不需要关心QT FB配置

9.1 int ZY_MPI_FB_Open(int fb,int width,int height);


功能：初始化QT FB配置

参数：1：指定的fB；2：设置FB的宽；3：设置FB的高

返回：0：成功，返回其他参数查看错误码；

