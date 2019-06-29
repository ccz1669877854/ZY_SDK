#ifndef __ZY_SNAP__
#define __ZY_SNAP__

#define ZY_ERR_DEMUX_INVALID_VPSSDEPTH   0xA1B08000
#define ZY_ERR_DEMUX_INVALID_GETFRAME   0xA1B08001
#define ZY_ERR_DEMUX_INVALID_SENDFRAME   0xA1B08002
#define ZY_ERR_DEMUX_INVALID_JPEGFRAME   0xA1B08003
#define ZY_ERR_DEMUX_INVALID_VPSSMODE   0xA1B08004

int ZY_MPI_Snap_StartJPEG(int VencChn,unsigned int u32Width,unsigned int u32Height);
int ZY_MPI_Snap_StopJPEG(int VencChn);


int ZY_MPI_Snap_SAVEJPEG(int vpssGroup,int vpssChn,int VencChn,const char * pFileName,unsigned int u32Width,unsigned int u32Height,int timeOut);


#endif
