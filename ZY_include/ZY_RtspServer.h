#ifndef __ZY_RTSPSERVER_H__
#define __ZY_RTSPSERVER_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

#include "zy_option.h"

#define MAX_RTSPCHANNEL_CHANNEL 8


typedef enum _RTSP_TYPE
{
	RTSP_H264 = 1,
	RTSP_H265,
	RTSP_H264_AAC,
	RTSP_H265_AAC,
} RTSP_TYPE;




#if 1
typedef struct _ZY_RTSP_ATTR
{
	ZY_AUDIO_SOUND_MODE_E enSoundmode; 
	ZY_AUDIO_SAMPLERATE samplerate;
	RTSP_TYPE type;
	

} ZY_RTSP_ATTR;

#endif 


#define RTSPSERVER_PTS_AUTO  (-1)


#define ZY_ERR_RTSPSERVER_INVALID_CHNID  	0xA0B08000
#define ZY_ERR_RTSPSERVER_INVALID_FILEPATH 	0xA0B08001
#define ZY_ERR_RTSPSERVER_INVALID_OPENFILE 	0xA0B08002
#define ZY_ERR_RTSPSERVER_INVALID_CODECID 	0xA0B08003
#define ZY_ERR_RTSPSERVER_INVALID_NOSUPPORT	0xA0B08004
#define ZY_ERR_RTSPSERVER_INVALID_CHNEXIST 	0xA0B08005
#define ZY_ERR_RTSPSERVER_INVALID_OPENCODEC 0xA0B08006
#define ZY_ERR_RTSPSERVER_INVALID_PARAM		0xA0B08007
#define ZY_ERR_RTSPSERVER_INVALID_CHNUNEXIST 	0xA0B08008


int ZY_MPI_RtspServer_Init();
int ZY_MPI_RtspServer_UnInit();

int ZY_MPI_RtspServer_CreateChn(unsigned int rtspChn,ZY_RTSP_ATTR attr);
int ZY_MPI_RtspServer_SendVideoFrame(unsigned int rtspChn,unsigned char *pdata ,unsigned int length,unsigned long long int pts,ZY_CodecType  type);
int ZY_MPI_RtspServer_SendAudioFrame(unsigned int rtspChn,unsigned char *pdata ,unsigned int length,unsigned long long int pts,ZY_CodecType  type);



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */


#endif 


