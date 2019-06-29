#ifndef __ZY_DEMUX_H__
#define __ZY_DEMUX_H__


#define MAX_DEMUX_CHANNEL 8
#define ZY_ERR_DEMUX_INVALID_CHNID  	0xA0B08000
#define ZY_ERR_DEMUX_INVALID_FILEPATH 	0xA0B08001
#define ZY_ERR_DEMUX_INVALID_OPENFILE 	0xA0B08002
#define ZY_ERR_DEMUX_INVALID_CODECID 	0xA0B08003
#define ZY_ERR_DEMUX_INVALID_NOSUPPORT	0xA0B08004
#define ZY_ERR_DEMUX_INVALID_CHNEXIST 	0xA0B08005
#define ZY_ERR_DEMUX_INVALID_OPENCODEC 0xA0B08006
#define ZY_ERR_DEMUX_INVALID_PARAM		0xA0B08007
#define ZY_ERR_DEMUX_INVALID_CHNUNEXIST 	0xA0B08008
#define ZY_ERR_DEMUX_INVALID_THREAD 	0xA0B08009




enum DEMUX_TYPE
{
DEMUX_AUDIO = 0,
DEMUX_VIDEO = 1,

};

typedef enum _ZY_VIDEO_TYPE
{
VIDEO_TYPE_H264 = 0,
VIDEO_TYPE_H265 = 1,
VIDEO_TYPE_JPEG = 2,


}ZY_VIDEO_TYPE;



typedef enum _ZY_DemuxCtrlSignal
{
	DEMUX_CTRL_STOP = 0,
	DEMUX_CTRL_SEEK,
	DEMUX_CTRL_PAUSE,
    
    DEMUX_CTRL_START,

}ZY_DemuxCtrlSignal;


typedef enum _ZY_TimeStampMode
{
	ZY_TIMESTAMP_MODE_FULL = 0, //no sleep 
	ZY_TIMESTAMP_MODE_SYNC,    // sync with time stamp
    
    ZY_TIMESTAMP_MODE_BLOCK,  //block time

}ZY_TimeStampMode;


typedef struct _ZY_DEMUXBIND_ATTR
{
	//video
	int VdecBlock;


	//audio
	int AdecBlock;


	//chn
	unsigned int chn;

	ZY_TimeStampMode timeMode;

	unsigned int usBlock;  //ZY_TIMESTAMP_MODE_BLOCK  effective

	ZY_DemuxCtrlSignal ctrl;


}ZY_DEMUXBIND_ATTR,* pZY_DEMUXBIND_ATTR;


typedef enum _ZY_DEMUXSTATE{
    ZY_DEMUXSTATE_LOST = 1,
    ZY_DEMUXSTATE_EOF = 2,
    ZY_DEMUXSTATE_TIMEOUT = 3,
    ZY_DEMUXSTATE_PAUSE = 4,   
    ZY_DEMUXSTATE_STOP = 5,     
	ZY_DEMUXSTATE_RUN = 6, 	  
	ZY_DEMUXSTATE_SEEK = 7,	  
	ZY_DEMUXSTATE_ERROR = 8,   

	
} ZY_DEMUXSTATE;


int ZY_MPI_Demux_Init();
int ZY_MPI_Demux_CreateChn(unsigned int Chn,const char * pstring);
int ZY_MPI_Demux_DestroyChn(unsigned int Chn);
int ZY_MPI_Demux_GetFrame(unsigned int Chn,unsigned char ** ppdata ,unsigned int * psize);
int ZY_MPI_Demux_ReleaseFrame(unsigned int Chn,unsigned char * pdata ,unsigned int size);
int ZY_MPI_Demux_BindVdecAdec(unsigned int chn,ZY_DEMUXBIND_ATTR Attr);
int ZY_MPI_Demux_UnBindVdecAdec(unsigned int chn,ZY_DEMUXBIND_ATTR Attr);






#endif

