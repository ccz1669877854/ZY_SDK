#ifndef     __ZY_LOADBMP_H__
#define     __ZY_LOADBMP_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */


/* the color format OSD supported */
typedef enum _ZY_OSD_COLOR_FMT_E
{
    ZY_OSD_COLOR_FMT_RGB444    = 0,
    ZY_OSD_COLOR_FMT_RGB4444   = 1,
    ZY_OSD_COLOR_FMT_RGB555    = 2,
    ZY_OSD_COLOR_FMT_RGB565    = 3,
    ZY_OSD_COLOR_FMT_RGB1555   = 4,
    ZY_OSD_COLOR_FMT_RGB888    = 6,
    ZY_OSD_COLOR_FMT_RGB8888   = 7,
    ZY_OSD_COLOR_FMT_BUTT
}ZY_OSD_COLOR_FMT_E;

typedef struct _ZY_OSD_RGB_S
{
    unsigned char   u8B;
    unsigned char   u8G;
    unsigned char   u8R;
    unsigned char   u8Reserved;
}ZY_OSD_RGB_S;

typedef struct _ZY_OSD_SURFACE_S
{
    ZY_OSD_COLOR_FMT_E enColorFmt;         /* color format */
    unsigned char  *pu8PhyAddr;               /* physical address */
    unsigned short  u16Height;                /* operation height */
    unsigned short  u16Width;                 /* operation width */
    unsigned short  u16Stride;                /* surface stride */
    unsigned short  u16Reserved;
}ZY_OSD_SURFACE_S;

typedef struct _ZY_tag_OSD_Logo
{
    unsigned int    width;        /* out */
    unsigned int    height;       /* out */
    unsigned int    stride;       /* in */
    unsigned char *   pRGBBuffer;   /* in/out */
}ZY_OSD_LOGO_T;

typedef struct _ZY_tag_OSD_BITMAPINFOHEADER{
        unsigned short      biSize;
        unsigned int       biWidth;
        unsigned int       biHeight;
        unsigned short       biPlanes;
        unsigned short       biBitCount;
        unsigned int      biCompression;
        unsigned int      biSizeImage;
        unsigned int       biXPelsPerMeter;
        unsigned int       biYPelsPerMeter;
        unsigned int      biClrUsed;
        unsigned int      biClrImportant;
} ZY_OSD_BITMAPINFOHEADER;

typedef struct _ZY_tag_OSD_BITMAPFILEHEADER {
        unsigned int   bfSize;
        unsigned short    bfReserved1;
        unsigned short    bfReserved2;
        unsigned int   bfOffBits;
} ZY_OSD_BITMAPFILEHEADER; 

typedef struct _ZY_tag_OSD_RGBQUAD {
        unsigned char    rgbBlue;
        unsigned char    rgbGreen;
        unsigned char    rgbRed;
        unsigned char    rgbReserved;
} ZY_OSD_RGBQUAD;

typedef struct _ZY_tag_OSD_BITMAPINFO {
    ZY_OSD_BITMAPINFOHEADER    bmiHeader;
    ZY_OSD_RGBQUAD                 bmiColors[1];
} ZY_OSD_BITMAPINFO;

typedef struct _ZY_OSD_COMPONENT_INFO_S{

    int alen;
    int rlen;
    int glen;
    int blen;
}ZY_OSD_COMP_INFO;

int ZY_MPI_BMP_LoadImage(const char *filename, ZY_OSD_LOGO_T *pVideoLogo);
int ZY_MPI_BMP_LoadBitMap2Surface(const char *pszFileName, const ZY_OSD_SURFACE_S *pstSurface, unsigned char *pu8Virt);
int ZY_MPI_BMP_CreateSurfaceByBitMap(const char *pszFileName, ZY_OSD_SURFACE_S *pstSurface, unsigned char *pu8Virt);
int ZY_MPI_BMP_CreateSurfaceByCanvas(const char *pszFileName, ZY_OSD_SURFACE_S *pstSurface, unsigned char *pu8Virt, unsigned int u32Width, unsigned int u32Height, unsigned int u32Stride);
int ZY_MPI_BMP_GetBmpInfo(const char *filename, ZY_OSD_BITMAPFILEHEADER  *pBmpFileHeader,ZY_OSD_BITMAPINFO *pBmpInfo);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __LOAD_BMP_H__*/

