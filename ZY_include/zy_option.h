#ifndef __ZY_OPTION_H__
#define __ZY_OPTION_H__


#define HARD_DISK_DIR_TESTFILE "/tmp/00a9b7602913981256776340882974103549925.conf"
#define HARD_DISK_DIR_TESTFILE_LENGTH  128

#define TTF_FONT_DIR "/root/font/simkai.ttf"


#define SCREEN_WIDTH    1920
#define SCREEN_HEIGHT   1080


#define ZY_VECN_RESOLUTION_1920X1080P  "1920X1080P"
#define ZY_VECN_RESOLUTION_1280X720P  "1280X720P"
#define ZY_VECN_RESOLUTION_1024X768P  "1024X768P"


#define ZY_VENC_TYPE_H265  "H.265"
#define ZY_VENC_TYPE_H264  "H.264"
#define ZY_VENC_TYPE_JPEG  "JPEG"
#define ZY_VENC_TYPE_MPEG  "MPEG"


#define ZY_VENC_MODE_CBR  "CBR"
#define ZY_VENC_MODE_VBR  "VBR"
#define ZY_VENC_MODE_AVBR  "AVBR"
#define ZY_VENC_MODE_FIXQP  "FIXQP"

#define ZY_VENC_DEFAULT_WITDH 1920
#define ZY_VENC_DEFAULT_HEIGHT 1080

#define ZY_VENC_DEFAULT_BITRATE  (4 * 1024)
#define ZY_VENC_DEFAULT_MAX_BITRATE  (40 * 1024)
#define ZY_VENC_DEFAULT_MIN_BITRATE  0

#define ZY_VENC_DEFAULT_GOP  60
#define ZY_VENC_DEFAULT_MAX_GOP  6000
#define ZY_VENC_DEFAULT_MIN_GOP  1


#define ZY_VENC_DEFAUTL_MAX_PROFILE  3

#define ZY_VENC_DEFAUTL_PROFILE  0

#define DEFAULT_TIME_BASE   1000


#define ZY_SUCCESS 			0
#define ZY_FAILURE			-1

#define SCREEN_WIDTH    1920
#define SCREEN_HEIGHT   1080

#define ZY_ADD_SEC  1


typedef enum {
    ZY_FALSE = 0,
    ZY_TRUE  = 1,
} ZY_BOOL;


typedef struct _ZY_POINT_S
{
    int s32X;
    int s32Y;
}ZY_POINT_S;


typedef enum _ZY_PIC_FPS
{
    ZY_PIC_FPS_24 = 24,

    ZY_PIC_FPS_25 = 25,
	ZY_PIC_FPS_30 = 30,

    ZY_PIC_FPS_50 = 50,
	ZY_PIC_FPS_60 = 60,
	ZY_PIC_FPS_75 = 75,
    ZY_PIC_FPS_120 = 120,
	ZY_PIC_FPS_240 = 240,	
}ZY_PIC_FPS;

#define ZY_PIC_MIN_WIDTH 64
#define ZY_PIC_MAX_WIDTH 4096
#define ZY_PIC_MIN_HEIGHT 64
#define ZY_PIC_MAX_HEIGHT 4096




typedef enum _ZY_AUDIO_SAMPLERATE
{
	ZY_AUDIO_SAMPLERATE_8000  = 8000,
	ZY_AUDIO_SAMPLERATE_16000  = 16000,
	ZY_AUDIO_SAMPLERATE_32000 = 32000,
	ZY_AUDIO_SAMPLERATE_44100 = 44100,
	ZY_AUDIO_SAMPLERATE_48000 = 48000,
	ZY_AUDIO_SAMPLERATE_96000 = 96000,

} ZY_AUDIO_SAMPLERATE;


typedef enum _ZY_AUDIO_BIT_WIDTH_E
{
    ZY_AUDIO_BIT_WIDTH_8   = 0,   /* 8bit width */
    ZY_AUDIO_BIT_WIDTH_16  = 1,   /* 16bit width*/
    ZY_AUDIO_BIT_WIDTH_24  = 2,   /* 24bit width*/
    ZY_AUDIO_BIT_WIDTH_BUTT,
} ZY_AUDIO_BIT_WIDTH_E;


typedef enum _ZY_AUDIO_BIT_RATE_E
{
    ZY_AUDIO_BIT_RATE_32000   = 32000,   
    ZY_AUDIO_BIT_RATE_64000  =  64000,   
    ZY_AUDIO_BIT_RATE_128000  = 128000,   
    ZY_AUDIO_BIT_RATE_BUTT,
} ZY_AUDIO_BIT_RATE_E;




typedef enum _ZY_AUDIO_SOUND_MODE_E
{
    ZY_AUDIO_SOUND_MODE_MONO   = 1, /*mono*/
    ZY_AUDIO_SOUND_MODE_STEREO = 2, /*stereo*/
    ZY_AUDIO_SOUND_MODE_BUTT
} ZY_AUDIO_SOUND_MODE_E;





typedef enum ZY_CodecType {
    ZY_CodecType_H264 = 1,
    ZY_CodecType_PCMU = 2,
    ZY_CodecType_PCMA = 3,
    ZY_CodecType_AAC  = 4,
    ZY_CodecType_H265 = 5,
    ZY_CodecType_VIDEO  = 6,
    ZY_CodecType_AUDIO = 7,    
} ZY_CodecType;







#endif
