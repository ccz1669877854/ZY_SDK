#ifndef __ZY_UDISKORHARDDISK__
#define __ZY_UDISKORHARDDISK__




#define ZY_ERR_UDISKORHARDDISK_INVALID_SECID 	0xA0D08001
#define ZY_ERR_UDISKORHARDDISK_INVALID_PARAM 	0xA0D08004

#define ZY_ERR_UDISKORHARDDISK_INVALID_THREAD 	0xA0D08006



#define  ZY_DEVTYPE_HDISK  2

#define  ZY_DEVTYPE_UDISK  3


#define ZY_UDISK_MOUNT_POINT "/tmp/usbDisk"
#define ZY_HDISK_MOUNT_POINT "/tmp/hardDisk"
#define ZY_DISK_DEVICENAME "sdx"
#define ZY_DISK_DEVICEPARTITION_NAME "sdx/sdx1"


typedef struct _UDiskOrHardDiskInfo
{
    char sdName[64];
    char mountName[1024];
}UDiskOrHardDiskInfo;


void ZY_MPI_UDiskOrHardDisk_Init();
int ZY_MPI_UDiskOrHardDisk_HotPlug_Start();
int ZY_MPI_UDiskOrHardDisk_HotPlug_Stop();




#endif
