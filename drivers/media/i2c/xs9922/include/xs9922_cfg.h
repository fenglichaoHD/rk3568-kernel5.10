/*************************************************
  Copyright (C) 2020-2020 ZheJiang XinSheng Electronic Technology CO.,LTD.
  �ļ���:    xs9910_cfg.h
  ��  ��:   chen_li(34308)<chen_li3@dahuatech.com>
  ��  ��:   1.0.0
  ��  �ڣ� 2020-07-24
  ��  ��:   �ṩ���Ա����Ĭ�ϱ���ƽ̨
  
            1��ʹ��˵��
            xx
           
            2��������
            xx
  
  �޶���ʷ:
  1. ��    ��:
     �޶��汾:
     ��    ��:
     �޶���ע:
     
  2. ��    ��:
     �޶��汾:
     ��    ��:
     �޶���ע:
*************************************************/

#ifndef __NI_CFG_H__
#define __NI_CFG_H__

/* �ɿ��ر���꣬Ϊ�˼��ݸ�����������ֻ���ü򵥵�
    ifdef�����ж�
*/

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

/* Win */
#undef NI_NISDK_WIN

/* Linux ������ */
//#define NI_NISDK_LINUX_DRV
#undef NI_NISDK_LINUX_DRV

/* Linux Ӧ�ò� */
#define NI_NISDK_LINUX_LIB
//#undef NI_NISDK_LINUX_LIB

/* MDK������ */
#undef NI_NISDK_MDK

/* IAR������ */
#undef NI_NISDK_IAR

#ifdef MODULE_NAME
#undef MODULE_NAME
#endif

/* 
    ���ݱ��뿪��ȷ��ͷ�ļ�����,����ƽ̨����
    ���к궨��
*/

/* Linux�� */
#ifdef NI_NISDK_LINUX_LIB

	//#include <stdio.h>
	//#include <pthread.h>
	//#include <string.h>
	//#include <sys/time.h>
	//#include <sys/types.h>
	//#include <unistd.h>
	
    /* ���嵼���������� */
    #define NI_DEF_API
    
    /* ���屾�غ������� */
    #define NI_DEF_LOCAL               static
    
    /* ���庯�����ŵ��� */
    #define NI_DEF_EXP_SYMBOL(x)
    
    /* ����inline */
    #define NI_DEF_INLINE              inline
    
    /* ����ȫ�ֱ����Ƿ�ʹ��static����const */
    #define NI_DEF_GLOBAL_VAR          const
    
    /* ʹ��ϵͳC�� */
    //#define NI_DEF_DEFAULTC
    #undef NI_DEF_DEFAULTC

    #define NI_DEF_XDATA
    
    
    /* ����ģ���� */
    #define MODULE_NAME                 "xs9922_sdk.a"

#endif

#ifdef NI_NISDK_MDK
	
    /* ���嵼���������� */
    #define NI_DEF_API
    
    /* ���屾�غ������� */
    #define NI_DEF_LOCAL					static               
    
    /* ���庯�����ŵ��� */
    #define NI_DEF_EXP_SYMBOL(x)
    
    /* ����inline */
    #define NI_DEF_INLINE
    
    /* ����ȫ�ֱ����Ƿ�ʹ��static����const */
    #define NI_DEF_GLOBAL_VAR			static

	#define NI_DEF_XDATA
    
    /* ʹ��ϵͳC�� */
    #define NI_DEF_DEFAULTC
	//#undef NI_DEF_DEFAULTC
    
    
    /* ����ģ���� */
    #define MODULE_NAME                 "xs9922_sdk.a"
		
		#pragma anon_unions

#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */



#endif /* __NI_CFG_H__ */
