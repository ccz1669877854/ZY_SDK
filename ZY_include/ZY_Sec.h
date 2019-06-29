#ifndef __ZY_SEC_H__
#define __ZY_SEC_H__


#define SEC_AUTH_SUCESS  0
#define SEC_AUTH_FALUE   -1


int sec_check_hardware(void);
int sec_auth(void);
int sec_auth_id( int prj_id);






#endif
