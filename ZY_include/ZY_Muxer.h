#ifndef __ZY_MUXER_H__
#define __ZY_MUXER_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */


#include "zy_option.h"


#define MAX_MUXER_CHANNEL 8
#define ZY_ERR_MUXER_INVALID_CHNID  0xA0A08000
#define ZY_ERR_MUXER_INVALID_FILEPATH 0xA0A08001
#define ZY_ERR_MUXER_INVALID_CREATEFILE 0xA0A08002
#define ZY_ERR_MUXER_INVALID_CODECID 0xA0A08003
#define ZY_ERR_MUXER_INVALID_PARAM 0xA0A08004
#define ZY_ERR_MUXER_INVALID_DESTROYFILE 0xA0A08005
#define ZY_ERR_MUXER_INVALID_THREAD 	0xA0B08006
#define ZY_ERR_MUXER_INVALID_CHNEXIT 	0xA0B08007


typedef enum {
	ZY_H264   =0,
	ZY_H265   =1,

}ZY_VECN_TYPE;



typedef enum {
	ZY_ONLYVIDEO   =0,
	ZY_ONLYAUDIO   =1,
	ZY_VIDEOAUDIO  =2,

}ZY_MUXER_TYPE;

typedef enum {
	ZY_MUXER_RUN  =0,
	ZY_MUXER_PAUSE   =1,

}ZY_MUXER_IS_PAUSE;



typedef struct _ZY_MUXER_ATTR
{
	//video
	char fileName[512];
	unsigned int width;
	unsigned int height;
	ZY_PIC_FPS fps;
	ZY_VECN_TYPE vencType;

	//audio
	ZY_AUDIO_BIT_WIDTH_E bitWidth;
	ZY_AUDIO_SOUND_MODE_E chnMode;
	ZY_AUDIO_SAMPLERATE sample_rate;
	ZY_AUDIO_BIT_RATE_E bitRate;

	ZY_MUXER_TYPE type;


}ZY_MUXER_ATTR,* pZY_MUXER_ATTR;

int ZY_MPI_Muxer_Init();
int ZY_MPI_Muxer_CreateChn(unsigned int chn,ZY_MUXER_ATTR * pMuxerAttr);
int ZY_MPI_Muxer_DetroyChn(unsigned int chn);
int ZY_MPI_Muxer_PauseChn(unsigned int chn,ZY_MUXER_IS_PAUSE isPause);


int ZY_MPI_Muxer_SendVideoFrame(unsigned int chn,unsigned char * pdata ,unsigned int size);
int ZY_MPI_Muxer_SendAudioFrame(unsigned int chn,unsigned char * pdata ,unsigned int size);



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */



#endif

