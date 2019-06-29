#ifndef __ZY_OSD_H__
#define __ZY_OSD_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */


#include "zy_option.h"


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










#define ZY_OSD_MAX_WIDTH     1920  
#define ZY_OSD_MAX_HEIGHT    1920  

#define ZY_OSD_POINT_AUTO    -1


#define AUTO_LEFT_INTERVAL    40
#define AUTO_RIGHT_INTERVAL    40

#define AUTO_TOP_INTERVAL  40
#define AUTO_BOTTOM_INTERVAL  40	




typedef  enum _ZY_PIXEL_FORMAT_E
{

	ZY_PIXEL_FORMAT_RGB_1555, 
	ZY_PIXEL_FORMAT_RGB_8888,
}ZY_PIXEL_FORMAT_E;

typedef enum _ZY_OSD_SRC_TYPE
{
    ZY_OSD_TEXT,
    ZY_OSD_PNG,
    ZY_OSD_BMP,
} ZY_OSD_SRC_TYPE;


typedef struct _SIZE_S
{
    unsigned int u32Width;
    unsigned int u32Height;
} ZY_SIZE_S;

typedef enum _ZY_OSD_DST_TYPE
{
    ZY_OSD_BINDVI,
    ZY_OSD_BINDVENC,
    ZY_OSD_BINDVPSS,
} ZY_OSD_DST_TYPE;


typedef struct _ZY_OSD_DST_ATTR
{
    ZY_OSD_DST_TYPE dstType;
	unsigned int dstChn;
	unsigned int Osdlayer;
} ZY_OSD_DST_ATTR;


typedef struct _ZY_OSD_ATTR_S
{
    /* bitmap pixel format*/
    ZY_PIXEL_FORMAT_E enPixelFmt;

    /* background color, pixel format depends on "enPixelFmt" */
    unsigned int  u32BgColor;

    /* region size */
    ZY_SIZE_S stSize;	
	unsigned int u32CanvasNum;

}ZY_OSD_ATTR_S;


typedef enum _ZY_INVERT_COLOR_MODE_E
{
    ZY_LESSTHAN_LUM_THRESH = 0,   /* the lum of the video is less than the lum threshold which is set by u32LumThresh  */ 
    ZY_MORETHAN_LUM_THRESH,       /* the lum of the video is more than the lum threshold which is set by u32LumThresh  */
    ZY_INVERT_COLOR_BUTT
}ZY_INVERT_COLOR_MODE_E;


typedef struct _ZY_OSD_INVERT_COLOR_S
{
    ZY_SIZE_S              stInvColArea;                //it must be multipe of 16 but not more than 64.
    unsigned int              u32LumThresh;                //the threshold to decide whether invert the OSD's color or not.
    ZY_INVERT_COLOR_MODE_E enChgMod;      
    ZY_BOOL             bInvColEn;                   //the switch of inverting color.
}ZY_OSD_INVERT_COLOR_S;


typedef struct _ZY_OSD_SHOW_QPINFO
{
	ZY_BOOL	 bQpDisable;
    ZY_BOOL  bAbsQp;
    int   s32Qp;
}ZY_OSD_SHOW_QPINFO;



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



int ZY_MPI_OSD_CreateChn(int chn);
int ZY_MPI_OSD_DestroyChn(int chn);
int ZY_MPI_OSD_SetChnAttr(int chn,ZY_OSD_ATTR_S attr);
int ZY_MPI_OSD_GetChnAttr(int chn,ZY_OSD_ATTR_S * pattr);
int ZY_MPI_OSD_BindDst(int OsdChn,ZY_OSD_DST_ATTR dstAttr,ZY_BOOL show,ZY_OSD_SHOW_ATTR_S showAttr);
int ZY_MPI_OSD_UnBindDst(int OsdChn,ZY_OSD_DST_ATTR dstAttr);
int ZY_MPI_OSD_ShowEnable(int OsdChn,ZY_OSD_DST_ATTR dstAttr,ZY_BOOL show,unsigned int u32X,unsigned int u32Y);
int ZY_MPI_OSD_SetShowPoint(int OsdChn,ZY_OSD_DST_ATTR dstAttr,unsigned int u32X,unsigned int u32Y);

int ZY_MPI_OSD_SetShow(int OsdChn,const char* pName,ZY_OSD_SRC_TYPE srcType,unsigned int color,unsigned int fontSize,unsigned int * pWidth,unsigned int * pHeight,ZY_BOOL autoShow);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */



#endif

