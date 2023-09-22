/*************************************************
  Copyright (C) 2020-2020 ZheJiang XinSheng Electronic Technology CO.,LTD.
  �ļ���:    xs9922_commm.h
  ��  ��:   chen_li(34308)<chen_li3@dahuatech.com>
  ��  ��:   1.0.0
  ��  �ڣ� 2020-07-24
  ��  ��:   �˴�Ϊ�ļ�����������������Ҫ����
  
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

#ifndef __NI_COMM_H__
#define __NI_COMM_H__

#include "ni_type.h"
#include "ni_errno.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */


#define NI_ID_NI                    (0x22)
#define NI_ERR_NI_INVALID_DEVID     NI_DEF_ERR(NI_ID_NI, NI_EN_ERR_LEVEL_ERROR, NI_ERR_INVALID_DEVID)
#define NI_ERR_NI_INVALID_CHNID     NI_DEF_ERR(NI_ID_NI, NI_EN_ERR_LEVEL_ERROR, NI_ERR_INVALID_CHNID)
#define NI_ERR_NI_ILLEGAL_PARAM     NI_DEF_ERR(NI_ID_NI, NI_EN_ERR_LEVEL_ERROR, NI_ERR_ILLEGAL_PARAM)
#define NI_ERR_NI_NULL_PTR          NI_DEF_ERR(NI_ID_NI, NI_EN_ERR_LEVEL_ERROR, NI_ERR_NULL_PTR)
#define NI_ERR_NI_NOT_CONFIG        NI_DEF_ERR(NI_ID_NI, NI_EN_ERR_LEVEL_ERROR, NI_ERR_NOT_CONFIG)
#define NI_ERR_NI_NOT_SUPPORT       NI_DEF_ERR(NI_ID_NI, NI_EN_ERR_LEVEL_ERROR, NI_ERR_NOT_SUPPORT)
#define NI_ERR_NI_NOT_PERM          NI_DEF_ERR(NI_ID_NI, NI_EN_ERR_LEVEL_ERROR, NI_ERR_NOT_PERM)



#define NI_MAX_CHIPS             (1)
#define NI_MAX_LANE_NUMS	     (4)
#define NI_MAX_CHNS              (4)
#define NI_MAX_LINEIN_CHNS		 (5)

/*������Ϣ����*/
typedef enum tagNiMsgType
{
    NI_MSG_TYPE_SILENT,                                     /*��Ĭ��ʽ*/
    NI_MSG_TYPE_ERR,                                        /*���󼶱�*/
    NI_MSG_TYPE_WARN,                                       /*���漶��*/
    NI_MSG_TYPE_INFO,                                       /*��Ϣ����*/
    NI_MSG_TYPE_DEBUG,                                      /*���Լ���*/
    
    NI_MSG_TYPE_BUTT
}NI_MSG_TYPE_E;


/*����������*/
typedef enum tagNiErrId
{
    NI_ERRID_SUCCESS = 0,                  /*����״̬*/             
    NI_ERRIF_FAILED,                       /*ͨ�ô���*/           
    NI_ERRID_TIMEOUT,                      /*��ʱ����*/            
	NI_ERRID_INVPARAM,                     /*��������*/                 
	NI_ERRID_NOINIT,                       /*δ��ʼ��*/                
	NI_ERRID_INVPOINTER,                   /*��ָ��*/                 
	NI_ERRID_UNSUPPORT,                    /*��֧��*/           
    NI_ERRID_UNKNOW,                       /*δ֪����*/            
} NI_ERR_ID_E;


typedef enum tagNiVideoFormat
{
    NI_CVI_1280x720_25HZ,      //0
    NI_CVI_1280x720_30HZ,      //1
    NI_CVI_1280x720_50HZ,      //2
    NI_CVI_1280x720_60HZ,      //3
    NI_CVI_1920x1080_25HZ,     //4
    NI_CVI_1920x1080_30HZ,     //5
    NI_CVI_1280x720_30HZ_V20,  //6
    NI_CVI_1280x720_60HZ_V20,  //7
    NI_CVI_1920x1080_30HZ_V20, //8
    
    NI_AHD_1280x720_25HZ,      //9
    NI_AHD_1280x720_30HZ,      //10
    NI_AHD_1280x720_50HZ,      //11
    NI_AHD_1280x720_60HZ,      //12
    NI_AHD_1920x1080_25HZ,     //13
    NI_AHD_1920x1080_30HZ,     //14

    NI_TVI_1280x720_25HZ,      //15
    NI_TVI_1280x720_30HZ,      //16
    NI_TVI_1280x720_50HZ,      //17
    NI_TVI_1280x720_60HZ,      //18
    NI_TVI3_1280x720_25HZ,     //19
    NI_TVI3_1280x720_30HZ,     //20
    NI_TVI_1920x1080_25HZ,     //21
    NI_TVI_1920x1080_30HZ,     //22
    
    NI_SD_NTSC_JM,             //23
    NI_SD_NTSC_443,            //24
    NI_SD_PAL_M,               //25
    NI_SD_PAL_60,              //26
    NI_SD_PAL_CN,              //27
    NI_SD_PAL_BGHID,           //28
    
    NI_VIDEO_FMT_BUTT
}NI_VIDEO_FORMAT_E;


typedef struct tagNiImgAdj
{
    NI_BOOL       bUserColor;                                  /*�û�����colorʹ��*/
    NI_U8         u8Brightness;                                /*���ȣ�ȡֵ��Χ:[0,0xff];Ĭ��ֵ:0x00*/
    NI_U8         u8Contrast;                                  /*�Աȶȣ�ȡֵ��Χ:[0,0xff];Ĭ��ֵ:0x80*/
    NI_U8         u8Saturation;                                /*���Ͷȣ�ȡֵ��Χ:[0,0xff];Ĭ��ֵ:0x80*/
    NI_U8         u8Hue;                                       /*ɫ����ȡֵ��Χ:[0,0xff];Ĭ��ֵ:0x00*/
    NI_U8         u8Gain;                                      /*���棬������*/
    NI_U8         u8WhiteBalance;                              /*�׵�ƽ,������*/
    NI_U8         u8Sharpness;                                 /*��ȣ�ȡֵ��Χ:[0,0x1f];Ĭ��ֵ:0x00*/
}NI_IMG_ADJ_S;


typedef struct tagNiImgOffset
{
    NI_BOOL   bUserCofig;                                   /*�û����û���Ĭ������ѡ��*/
    NI_U8     u8HorToward;                                  /*ˮƽƫ�Ʒ���[0:����; 1:����]*/
    NI_U8     u8HorOffset;                                  /*ˮƽƫ������ȡֵ��Χ:[0,0x7f]*/ 
	NI_U8     u8VerToward;                                  /*��ֱƫ�Ʒ���[0:����; 1:����]*/
    NI_U8     u8VerOffset;                                  /*��ֱƫ������ȡֵ��Χ:[0,0x7f]*/ 
}NI_IMG_OFFSET_S;


typedef struct tagNiImgAttr
{
	NI_IMG_ADJ_S stImgAdj;                               /*����ͼ�����*/
	NI_IMG_OFFSET_S stImgOffset;                         /*����ͼ��ƫ��*/ 
}NI_IMG_ATTR_S;


typedef enum tagNiCableType
{
    NI_CABLE_TYPE_COAXIAL,                                /*ͬ������*/
    NI_CABLE_TYPE_UTP_10OHM,                              /*10 ohm�迹˫����*/   
    NI_CABLE_TYPE_AVIATION,                               /*����ͷ��������*/
    
    NI_CABLE_TYPE_BUTT 
} NI_CABLE_TYPE_E;


/*��Ƶ״̬*/
typedef enum
{
    NI_VIDEO_CONNECT = 0,                               /*��Ƶ��������*/
    NI_VIDEO_LOST = 1,                                  /*��Ƶ��ʧ*/  
    NI_VIDEO_BUT,
}NI_VIDEO_STATUS_E;


typedef struct tagNiVideoStatusInfo
{
    NI_VIDEO_STATUS_E       enVideoLost;                   /*1��Ƶ��ʧ��0 ��Ƶ�ָ�*/
    NI_VIDEO_FORMAT_E       enVideoOutFormat;              /*��ǰ��Ƶ�����ʽ*/
    NI_VIDEO_FORMAT_E       enVideoInFormat;               /*��ǰ��⵽����Ƶ��ʽ*/
}NI_VIDEO_STATUS_INFO_S;

typedef enum tagNiNetraMode
{
    NI_NETRA_MODE_DOUBLE,                                  /*˫ͷ��ʽ*/
    NI_NETRA_MODE_SINGLE,                                  /*��ͷ��ʽ*/    
    
    NI_NETRA_MODE_BUTT
}NI_NETRA_MODE_E;

typedef enum tagNiChnIdPos
{
    NI_CHN_ID_POS_NOID,                                /*ID�Ų���*/
    NI_CHN_ID_POS_HBLANK,                              /*ID�ż�����������*/   
    NI_CHN_ID_POS_HEADINFO,                            /*ID�ż���ͷ��Ϣ��*/
    NI_CHN_ID_POS_BOTH,                                /*ID��ͬʱ����������������ͷ��Ϣ��*/
    
    NI_CHN_ID_POS_BUTT
}NI_CHN_ID_POS_E;

typedef enum tagNiChnIdVal
{
    NI_CHN_ID_VAL_0,                                           /*ͨ��ID 0*/
    NI_CHN_ID_VAL_1,                                           /*ͨ��ID 1*/
    NI_CHN_ID_VAL_2,                                           /*ͨ��ID 2*/
    NI_CHN_ID_VAL_3,                                           /*ͨ��ID 3*/  
    
    NI_CHN_ID_VAL_BUTT,
}NI_CHN_ID_VAL_E;

typedef struct tagNiVoIdAttr
{
    NI_CHN_ID_POS_E    enChnIdPos;                      /*ѡ��ͨ��ID���������е�λ��*/
    NI_CHN_ID_VAL_E    enChnId;                         /*��Ƶ���ͨ����Ӧ��ID����*/
}NI_VO_ID_ATTR_S;

typedef enum tagNiInputChn
{
    NI_INPUT_CHN_0,                                        /*ͨ��0*/
    NI_INPUT_CHN_1,                                        /*ͨ��1*/
    NI_INPUT_CHN_2,                                        /*ͨ��2*/
    NI_INPUT_CHN_3,                                        /*ͨ��3*/ 
    
    NI_INPUT_CHN_BUTT,
}NI_INPUT_CHN_E;


typedef struct tagNiVoTdmInfo
{   
    NI_INPUT_CHN_E  enFirstInputChn;                    /*��һ·�ź�Դ��*/
    NI_INPUT_CHN_E  enSecondInputChn;                   /*�ڶ�·�ź�Դ��*/
}NI_VO_TDM_INFO_S;

typedef enum tagNiVoBitMode
{
    NI_VO_MODE_BT1120,                                     /*BT1120*/
    NI_VO_MODE_BT656,                                      /*BT656*/
    
    NI_VO_MODE_BUTT
}NI_VO_BIT_MODE_E;


typedef enum tagNiVoHdGmMode
{
	NI_VO_HD_GM_CLOSE = 0,                            /*��������ѹ��*/ 
	NI_VO_HD_GM_OPEN,                                 /*������ѹ��*/
	
    NI_VO_HD_GM_MODE_BUTT,
}NI_VO_HD_GM_MODE_E;


typedef enum tagNiVoSdFmt
{
    NI_VO_SD_MODE_720H,                                /*720H*/
    NI_VO_SD_MODE_960H,                                /*960H*/
    
    NI_VO_SD_MODE_BUTT
}NI_VO_SD_FMT_E;


typedef enum tagNiVoClkEdge
{
    NI_VO_CLK_EDGE_RISING,                             /*�����زɼ�*/
    NI_VO_CLK_EDGE_DUAL,                               /*���±��زɼ�ģʽ*/   
    
    NI_VO_CLK_EDGE_BUTT
}NI_VO_CLK_EDGE_E;


typedef enum tagNiVoBufMode
{
    NI_VO_BUF_DEFAULT = 0,                           /*Ĭ����ʱ���ڲ�����*/
    NI_VO_BUF_MANUAL, 								 /*�ֶ�������ʱ*/
    
    NI_VO_BUF_BUTT                                  
} NI_VO_BUF_MODE_E;


typedef struct tagNiVoBuf
{
    NI_VO_BUF_MODE_E enVoBufMode;                     /*��Ƶ�����ʱ����ģʽѡ��*/
    NI_U16  	     u16VoBufValue;                   /*��Ƶ������������������ʱʱ�䣬ȡֵ��Χ:[0,0x1fff];Ĭ��ֵ:0x00*/
}NI_VO_BUF_S;


typedef enum tagNiVoClkMode
{
    NI_CLK_MODE_37_125 = 0,     					/*Halfģʽ���37.125Mʱ��*/
    NI_CLK_MODE_74_25 = 1, 						    /*Halfģʽ���74.25Mʱ��*/
    NI_CLK_MODE_148_5 = 2,							/*Halfģʽ���148.5Mʱ��*/
    NI_CLK_MODE_144 = 3, 							/*Halfģʽ���144Mʱ��*/
    NI_CLK_MODE_BUT,
}NI_VO_CLK_MODE_E;


//typedef struct tagNiVoHalfAttr
//{
//    NI_BOOL bHalfEn;								/*��Ƶ���Halfģʽʹ��*/
//	NI_VO_CLK_MODE_E enClkMode;					    /*Halfģʽ���ʱ��ѡ��*/
//} NI_VO_HALF_ATTR_S;


typedef struct tagNiVoAttr
{                 
    NI_BOOL            bDataSeqInv;					/*VO������ݰ�bitλ��ת*/
    NI_BOOL            bDataSwapEn;					/*VO������ݰ�Bytλ��ת*/
    NI_NETRA_MODE_E    enNetraMode;                 /*������Ƶ����ͷ��ʽѡ��*/
    NI_VO_ID_ATTR_S    stChnIdAttr;                 /*ͨ��ID����*/	
    NI_VO_TDM_INFO_S   stVoTdmInfo;					/*��Ƶ�����2xģʽ��ͨ���ź�Դѡ��*/
	NI_VO_BIT_MODE_E   enVoBitMode; 			    /*���ģʽѡ��*/
	NI_VO_HD_GM_MODE_E enGmMode;					/*��ǰVOͨ��GMģʽ����*/
	NI_VO_SD_FMT_E     enSdFormat;					/*VO��������ֱ�������*/
    NI_VO_CLK_EDGE_E   enVoClkEdge;                 /*ѡ��ʱ�ӱ��ز�ģʽ*/
    NI_VO_BUF_S        stVoBuffer;					/*��ǰVOͨ����ʱ��������*/
    NI_INPUT_CHN_E     enChnDataSrc;                /*��ǰVOͨ��ӳ����������ݶ˿�*/
    NI_BOOL 		   bHalfEn;						/*��Ƶ���Halfģʽʹ��*/
	NI_VO_CLK_MODE_E   enClkMode;					/*Halfģʽ���ʱ��ѡ��*/
	
}NI_VO_ATTR_S;

typedef enum tagNiFreeRunColor
{
    NI_FREERUN_COLOR_WHITE,                             /*��ɫ*/
    NI_FREERUN_COLOR_YELLOW,                            /*��ɫ*/  
    NI_FREERUN_COLOR_CYAN,                              /*��ɫ*/ 
    NI_FREERUN_COLOR_GREEN,                             /*��ɫ*/    
    NI_FREERUN_COLOR_MAGENTA,                           /*���ɫ*/ 
    NI_FREERUN_COLOR_RED,                               /*��ɫ*/
    NI_FREERUN_COLOR_BLUE,                              /*��ɫ*/
    NI_FREERUN_COLOR_BLACK,                             /*��ɫ*/
    
    NI_FREERUN_COLOR_BUTT
}NI_FREERUN_COLOR_E;

typedef struct tagNiFreeRunAttr
{
    NI_FREERUN_COLOR_E    enFreeRunColor;				/*Freerun��ɫƷ��ɫ*/
    NI_VIDEO_FORMAT_E     enFreeRunFormat;				/*Freerun��ɫƷ��ʽ*/
}NI_FREERUN_ATTR_S;


typedef struct tagNiVideoAttr
{
    NI_VO_ATTR_S    	stVoAttr;						/*VO��������*/
    NI_FREERUN_ATTR_S   stFreeRunAttr;					/*Freerun����*/
}NI_VIDEO_ATTR_S;


typedef enum tagNiCoAudMode
{
    NI_COAUD_MODE_OLD,									/*ͬ����Ƶ�Ϸ���*/
    NI_COAUD_MODE_NEW,									/*ͬ����Ƶ�·���*/
    
    NI_COAUD_MODE_BUTT
}NI_COAUD_MODE_E;
	

typedef enum tagNiAudSampleRate
{
    NI_AUD_SAMPLERATE_8K,                       /*8K����Ƶ��*/
    NI_AUD_SAMPLERATE_16K,                      /*16K����Ƶ��*/
    NI_AUD_SAMPLERATE_32K,                      /*32K����Ƶ��*/
    NI_AUD_SAMPLERATE_48K,                      /*48K����Ƶ��*/
    NI_AUD_SAMPLERATE_44_1K,                    /*44.1K����Ƶ��*/

    NI_AUD_SAMPLERATE_BUTT
}NI_AUD_SAMPLERATE_E;


typedef enum tagNiAudClkMode
{
	NI_AUD_CLK_MODE_MASTER, 						   /*��ģʽ*/
    NI_AUD_CLK_MODE_SLAVE,                             /*��ģʽ*/
    
    NI_AUD_MODE_BUTT
}NI_AUD_CLK_MODE_E;


typedef enum tagNiAudIntfMode
{
    NI_AUD_INTF_MODE_IIS,							/*I2Sģʽ*/
    NI_AUD_INTF_MODE_DSP,							/*DSPģʽ*/
    
    NI_AUD_INTF_MODE_BUTT
}NI_AUD_INTF_MODE_E;


typedef enum tagNiAudEncSrc
{
    NI_AUD_SRC_LINEIN,								/*ģ����Ƶ����*/
    NI_AUD_SRC_COAXIAL,								/*ͬ����Ƶ����*/

    NI_AUD_SRC_BUTT
}NI_AUD_ENC_SRC_E;


typedef enum tagNiAudDataWidth
{
    NI_AUD_DATA_16BIT,								/*16bitλ��*/
    NI_AUD_DATA_20BIT,								/*20bitλ��*/
    NI_AUD_DATA_24BIT,								/*24bitλ��*/

    NI_AUD_DATA_BUTT
}NI_AUD_DATA_WIDTH_E;


typedef enum tagNiAudDecFreq
{
    NI_AUD_DEC_FREQ_32,                       /*λͬ����֡ͬ��Ƶ�ʵı�����ϵ:32*/
    NI_AUD_DEC_FREQ_64,                       /*λͬ����֡ͬ��Ƶ�ʵı�����ϵ:64*/
    NI_AUD_DEC_FREQ_128,                      /*λͬ����֡ͬ��Ƶ�ʵı�����ϵ:128*/
    NI_AUD_DEC_FREQ_256,                      /*λͬ����֡ͬ��Ƶ�ʵı�����ϵ:256*/

    NI_AUD_DEC_FREQ_BUTT
}NI_AUD_DEC_FREQ_E;


typedef enum tagNiAudDacSrc
{
    NI_AUD_DAC_SRC_IIS,							/*��Ƶ��������I2S*/
    NI_AUD_DAC_SRC_ADC1,						/*��Ƶ��������LINE_IN1*/
    NI_AUD_DAC_SRC_ADC2,						/*��Ƶ��������LINE_IN2*/
    NI_AUD_DAC_SRC_ADC3,						/*��Ƶ��������LINE_IN3*/
    NI_AUD_DAC_SRC_ADC4,						/*��Ƶ��������LINE_IN4*/
    NI_AUD_DAC_SRC_ADC5,						/*��Ƶ��������LINE_IN5*/
    
    NI_AUD_DAC_SRC_BUTT
}NI_AUD_DAC_SRC_E;


typedef enum tagNiAudAdcInputSelMode
{
    NI_AUD_ADC_SEL_MODE_LINEIN,						/*ͨ��ѡ��LINEIN����*/
    NI_AUD_ADC_SEL_MODE_MIC,						/*ͨ��ѡ��MIC����*/
    
    NI_AUD_ADC_SEL_MODE_BUTT
}NI_AUD_ADC_INPUT_SEL_MODE_E;


typedef enum tagNiAudAdcInputSelLine
{
    NI_AUD_ADC_SEL_LINE_1,						/*��Ƶ��������LINE_1*/
    NI_AUD_ADC_SEL_LINE_2,						/*��Ƶ��������LINE_2*/
	NI_AUD_ADC_SEL_LINE_3,						/*��Ƶ��������LINE_3*/
	
    NI_AUD_ADC_SEL_LINE_BUTT
}NI_AUD_ADC_INPUT_SEL_LINE_E;


typedef struct tagNiAudCasMode
{
    NI_U8 u8CasNum;                                    /*������Ŀ*/
    NI_U8 u8CasPos;                                    /*����λ��*/
}NI_AUD_CAS_MODE_S;


typedef struct tagNiCoaudAttr
{
    NI_BOOL bRecEn;										/*ͬ����Ƶ����ʹ��*/
	NI_BOOL bCheckEn;									/*ͬ������ƵУ��ʹ��*/
	NI_U8   u8AudioGain;								/*ͬ����Ƶ�������棬ȡֵ��Χ:[0,0xff];Ĭ��ֵ:0x80*/
	NI_COAUD_MODE_E enCoaudMode;						/*ͬ����Ƶ���Ϸ���ѡ��*/
} NI_COAUD_ATTR_S;
	

typedef struct tagNiAudEncAttr
{
    NI_BOOL                 bEncEn;                           /*����ʹ��*/
	NI_AUD_DATA_WIDTH_E 	enEncDataWidth;  				  /*��������λ��*/
    NI_AUD_CLK_MODE_E       enEncClkMode;                     /*����ʱ������ģʽѡ��Ӧ��enDecClkModeһ��*/
    NI_AUD_INTF_MODE_E      enEncIntfMode;                    /*��Ƶ�ӿ�ģʽ*/
    NI_AUD_ENC_SRC_E       	aenEncSrc[NI_MAX_CHNS];       	  /*����Դѡ��*/   
}NI_AUD_ENC_ATTR_S;


typedef struct tagNiAudDecAttr
{
    NI_BOOL                 bDecEn;                      /*����ģ��ʹ��*/
	NI_U8 					u8DecOutpSel;				 /*����ͨ������Դѡ��*/
	NI_U8					u8DecChsel;					 /*�����������ͨ��ѡ��0���ң�1����*/
    NI_AUD_CLK_MODE_E       enDecClkMode;                /*����ʱ������ģʽѡ��Ӧ��enEncClkModeһ��*/
    NI_AUD_INTF_MODE_E      enDecIntfMode;               /*��Ƶ�ӿ�ģʽ*/
    NI_AUD_DATA_WIDTH_E     enDecDataWidth;  			 /*��������λ��*/
}NI_AUD_DEC_ATTR_S;


typedef struct tagNiAudDacAttr
{
    NI_BOOL           bDacEn;                                   /*ģ����Ƶ���ʹ��*/
    NI_U8             u8DacGain;                                /*ģ����Ƶ������棬ȡֵ��Χ:[0,0x1f];Ĭ��ֵ:0x1b*/
    NI_AUD_DAC_SRC_E  enAudDacSrc;                              /*ģ����Ƶ�������Դѡ��*/
}NI_AUD_DAC_ATTR_S;
 

typedef struct tagNiAudAdcAttr
{
	NI_BOOL				 		 		bAdcEn;					/*����ʹ��*/
	NI_U8                 				u8PgaGain;              /*PGA ���棬ȡֵ��Χ:[0,0xf];Ĭ��ֵ:0x8*/
    NI_U8                 				u8DigtalGain;           /*Digital ���棬ȡֵ��Χ:[0,0xf];Ĭ��ֵ:0x8*/
	NI_AUD_ADC_INPUT_SEL_MODE_E			enInputSelMode;			/*CHN0-3ģ����Ƶ����ģʽѡ��*/
    NI_AUD_ADC_INPUT_SEL_LINE_E			enInputSelLine;         /*CHN4-5ģ����Ƶ����LINEѡ��*/
 }NI_AUD_ADC_ATTR_S;


typedef struct tagNiAudioAttr
{
	NI_AUD_SAMPLERATE_E enAudSamplerate;						    /*��Ƶ������*/
	NI_AUD_CAS_MODE_S stAudCasMode;									/*��Ƶ����ģʽ*/
	NI_COAUD_ATTR_S stCoAudAttr[NI_MAX_CHNS];						/*ͬ����Ƶ����*/
	NI_AUD_ENC_ATTR_S stAudEncAttr; 								/*��Ƶ��������*/			 
	NI_AUD_DEC_ATTR_S stAudDecAttr;  								/*��Ƶ��������*/
	NI_AUD_DAC_ATTR_S stAudDacAttr;									/*ģ����Ƶ�������*/
	NI_AUD_ADC_ATTR_S stAudAdcAttr[NI_MAX_LINEIN_CHNS];				/*ģ����Ƶ��������*/
}NI_AUDIO_ATTR_S;


typedef enum tagNiWorkMode
{
    NI_WORK_MODE_1Multiplex,                           /*1xģʽ*/
    NI_WORK_MODE_2Multiplex,                           /*2xģʽ*/
    NI_WORK_MODE_4Multiplex,                           /*4xģʽ*/  
    NI_WORK_MODE_BUTT
}NI_WORK_MODE_E;


typedef struct tagNiCo485Attr
{
    NI_BOOL bSendEn; 									/*����485���ݷ���ʹ��*/
	NI_BOOL bSendCheckEn;								/*��485������żУ��λʹ��*/
	NI_BOOL bRecEn; 									/*����485���ݽ���ʹ��*/
	NI_BOOL bUtoEn;										/*�����䳬ʱʹ��*/
	NI_U16  u16UtoTime;									/*�����䣬�趨��ʱĿ��ʱ��(��)*/
	NI_U16  u8IntLevel;									/*�����䣬�趨�ж�ˮλ�����ݳ��ȣ�*/
} NI_CO485_ATTR_S;
	

typedef struct tagNiCo485Buf
{
    NI_U8 *pu8485Buf;                                          /*485����ָ��*/
    NI_U8 u8BufLength;                                         /*���ݳ���*/
}NI_CO485_BUF_S;


typedef struct tagNiDevAttr
{
    NI_WORK_MODE_E          enWorkMode;                     /*Video Out��ͨ������ģʽѡ��*/
	NI_VIDEO_ATTR_S         astVideoAttr[NI_MAX_CHNS];     	/*��Ƶ�����������*/
    NI_AUDIO_ATTR_S         stAudioAttr;                    /*��Ƶ��������*/
	NI_CO485_ATTR_S         astCo485Attr[NI_MAX_CHNS];		/*CO485����*/
}NI_DEV_ATTR_S;

typedef enum tagNiVideoProtocol
{
    NI_VIDEO_PROTOCOL_AUTO,                                /*�Զ�ģʽ*/
    NI_VIDEO_PROTOCOL_CVI,                                 /*CVIЭ��*/
    NI_VIDEO_PROTOCOL_AHD,                                 /*AHDЭ��*/
    NI_VIDEO_PROTOCOL_TVI,                                 /*TVIЭ��*/
    NI_VIDEO_PROTOCOL_SD,                                  /*����*/
    
    NI_VIDEO_PROTOCOL_BUTT  
}NI_VIDEO_PROTOCOL_E;


typedef enum tagNiDetectMode
{
    NI_DETECT_NORMAL_MODE,                                /*����ʶ��ģʽ��ʶ���ٶ�һ��*/
    NI_DETECT_FAST_MODE,                                  /*����ʶ��ģʽ��ʶ���ٶȽϿ�*/
    
    NI_DETECT_BUTT  
}NI_DETECT_MODE_E;


typedef struct tagNiDetectOpt
{
    NI_BOOL                     bUseDetectOptEn;				/*ѡ��ʹ���û�����ʹ��*/
	NI_DETECT_MODE_E            enDetectMode;					/*����Ӧģʽѡ��*/	
    NI_CABLE_TYPE_E             enCableType;					/*��������ѡ��*/
    NI_VIDEO_FORMAT_E           enVideoFormat;					/*ǿ��������Ƶ��ʽ*/
    NI_VIDEO_PROTOCOL_E         enVideoProtocol;				/*ǿ��������ƵЭ��*/
    NI_BOOL                     bReLockEn;						/*���ʱ������������*/
    NI_BOOL                     bEqEn;							/*EQ����Ӧʹ��*/
}NI_DETECT_OPT_S;


typedef struct tagNiDevInfo
{
    NI_U8              u8I2cDev;      /*iic�豸��*/   
    NI_U8              u8DevAddr;     /*������ַ*/  
}NI_DEV_INFO_S;


typedef struct tagNiRegFunc
{
    NI_S32  (*NI_WriteByte)(NI_U8 u8I2cDev, NI_U8 u8DevAddr, NI_U16 u16RegAddr, NI_U8 u8RegValue);
    NI_S32  (*NI_ReadByte)(NI_U8 u8I2cDev, NI_U8 u8DevAddr, NI_U16 u16RegAddr, NI_U8 *pu8RegValue);
    NI_VOID (*NI_MSleep)(NI_U8 u8MsDly);
    NI_VOID (*NI_Printf)(NI_CHAR *pszStr);
    NI_VOID (*NI_GetLock)(NI_VOID);
    NI_VOID (*NI_ReleaseLock)(NI_VOID);

}NI_REG_FUNC_S;

typedef enum tagNiMipiLaneNum
{
    NI_MIPI_LANE_MODE_1,											/*lane_num=1*/
    NI_MIPI_LANE_MODE_2,											/*lane_num=2*/
	NI_MIPI_LANE_MODE_4,											/*lane_num=4*/
	
    NI_MIPI_LANE_MODE_BUTT
}NI_MIPI_LANE_NUM_E;


typedef struct tagNiMipiLaneAttr
{
    NI_MIPI_LANE_NUM_E     stMipiLaneNum;      					/*Mipi lane num*/
	NI_BOOL   			   bMipiLanePnSwap[NI_MAX_LANE_NUMS];	/*Mipi lane swap pn*/
    NI_U16                 u16MipiLaneFreq;    					/*Mipi lane freq(Mbps) ����Ϊ100�ı��� Ĭ��Ϊ1.5G*/  
}NI_MIPI_LANE_ATTR_S;


typedef enum tagNiChipPack
{
    NI_CHIP_PACK_BT,												/*BT���*/
    NI_CHIP_PACK_MIPI,												/*MIPI���*/

    NI_CHIP_PACK_BUTT
}NI_CHIP_PACK_E;

typedef struct tagNiRegInfo
{
    NI_CHIP_PACK_E         enChipPack[NI_MAX_CHIPS];           /*оƬ����*/
	NI_MIPI_LANE_ATTR_S    stMipiLaneAttr;                     /*Mipi lane����*/
    NI_BOOL                bCheckChipId;                       /*Ч��оƬ��ID*/ 
    NI_U8                  u8AdCount;                          /*оƬ����*/
    NI_DEV_INFO_S          astNiDevInfo[NI_MAX_CHIPS];         /*��¼ÿ��оƬ��I2C��Ϣ*/
    NI_REG_FUNC_S          stNiRegFunc;                        /*�û�����ע��*/
}NI_REG_INFO_S;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */



#endif /*__NI_COMM_H__*/

