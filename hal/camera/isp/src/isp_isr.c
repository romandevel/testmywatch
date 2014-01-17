/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   isp_isr.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   ISP contorl flow for camera scenario
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "cal_api.h"
#include "cal_if.h"
#include "cal_task_msg_if.h"

#include "isp_comm_def.h"

#include "isp_if.h"
#include "isp_comm_if.h"

#include "IntrCtrl.h"
#include "visualhisr.h"

#include "aaa_process.h"
#include "isp_pca.h"
#include "isp_hw_feature_def.h"
#include "isp_flashlight_if.h"
#include "aaa_ae.h"
#include "aaa_awb.h"



#define FRAME_RATE_BUFFER_SIZE (30)
#define ISP_TIME_MEASURE_1S (1000)
#define ISP_TIME_MEASURE_2S (2000)
#define ISP_TIME_MEASURE_3S (3000)
#define ISP_TIME_MEASURE_PERIOD  ISP_TIME_MEASURE_1S
#define ISP_TIME_MEASURE_DIVIDER  (ISP_TIME_MEASURE_PERIOD/ISP_TIME_MEASURE_1S)

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_CAMCAL_ROCODE", rodata = "DYNAMIC_CODE_CAMCAL_ROCODE"
#endif


kal_eventgrpid IspEventId=NULL;
kal_uint8 IspSleepModeHandler = 0xFF;

volatile kal_uint32 IspIntStatus;
volatile kal_bool IspVsyncTgFlag;
kal_bool IspDynamicSettingFlag=KAL_TRUE;
kal_uint32 IspReszOverrunCnt;
kal_uint32 IspGmcOverrunCnt;
kal_uint32 IspFrameReadyCnt;
kal_uint32 IspVsyncTgCnt;
kal_uint32 IspTimeTickBuff[CAMERA_TIME_TICK_BUFFER_COUNT];
kal_uint32 IspTimeTick;
kal_uint32 IspCurrentFrameRate,IspFrameRateIndex;
kal_uint16 IspFrameRateBuff[FRAME_RATE_BUFFER_SIZE];
kal_uint32 IspCurrentFrameTime;
kal_uint32 IspTimeMeasureBegin, IspTimeMeasureNow,IspTimeMeasurePeriod;
kal_bool   IspWaitAFResult = KAL_FALSE;
SENSOR_AF_DELAY_STRUCT IspAFQueryDelay;
kal_uint32 IspTimeMeasureFrameCount;
CAL_INFORM_MDP_FRAME_RATE_REQ_MSG_STRUCT IspFrameRateInfo;

#if defined(__JPEG_SENSOR_SUPPORT__)
extern CAL_JPEG_SENSOR_PARSE_REQ_MSG_STRUCT JpegSensorInfo;
extern JPEG_SENSOR_SRC_BUFFER_STRUCT JpegSensorParaIn;
extern JPEG_SENSOR_PARSE_DATA_STRUCT JpegSensorParaOut;
#endif

extern void L1SM_SleepDisable( kal_uint8 handle );
extern kal_uint8 L1SM_GetHandle ( void );


/*Register ISP event */
void IspInitEvent(void)
{
    if (NULL==IspEventId)
    {
        IspEventId=kal_create_event_group("ISP_EVT");
    }
}


/*Register ISP LISR, HISR*/
void IspInitISR(void)
{
    if (0xFF==IspSleepModeHandler)
    {
        IspSleepModeHandler = L1SM_GetHandle();
    }
    L1SM_SleepDisable(IspSleepModeHandler);
    IRQ_Register_LISR(IRQ_CAMERA_CODE, IspCameraLISR,"Camera ISR");
    VISUAL_Register_HISR(VISUAL_CAMERA_HISR_ID,IspCameraHISR);
}


/**************** Assume resizer overrun frame reset will be implemented by Hardware *************/
void IspCameraLISR(void)
{
    kal_uint32 IntStatus;
    kal_uint32 SaveIrqMask;

    SaveIrqMask=SaveAndSetIRQMask();
    {
        IRQMask(IRQ_CAMERA_CODE);
        IspFrameCount++;
        IntStatus=DRV_Reg32(ISP_INT_STATUS_REG);
        IspIntStatus=0;
    }

    RestoreIRQMask(SaveIrqMask);

    /* RESZ Overrun Interrupt */
    if (IntStatus & REG_CAMERA_INT_RESIZER_OVERRUN_ENABLE_BIT)
    {
        IspReszOverrunCnt++;
        IspIntStatus |= ISP_INT_RESIZER_OVERRUN;
    }

    /* Frame Ready Interrupt */
    if (IntStatus & REG_CAMERA_INT_FRAME_READY_ENABLE_BIT)
    {
        if(KAL_TRUE==WaitFirstFrameFlag)
        {
            FirstSensorFrameFlag = KAL_TRUE;
        }

        IspIntStatus |= ISP_INT_FRAME_READY;
        IspFrameReadyCnt++;
    }

    /* Camera Idle Interrupt */
    if (IntStatus & REG_CAMERA_INT_IDLE_ENABLE_BIT)
    {
        IspIdleDoneFlag=KAL_TRUE;
        IspIntStatus |= ISP_INT_IDLE;
    }

    /* ISP Done Interrupt */
    if (IntStatus & REG_CAMERA_INT_ISP_DONE_ENABLE_BIT)
    {
        IspDoneFlag=KAL_TRUE;
        IspIntStatus |= ISP_INT_ISP_DONE;
    }

    /* TG Done Interrupt */
    if ((IntStatus & REG_CAMERA_INT_TG_DONE_ENABLE_BIT)!= 0)
    {
        IspVsyncTgFlag = KAL_TRUE;
        //frame rate check
        IspTimeTickBuff[IspTimeTick]=drv_get_current_time();
        IspTimeTick++;
        IspTimeTick%=CAMERA_TIME_TICK_BUFFER_COUNT;
        IspVsyncTgCnt++;

        if((REG_ISP_INT_ENABLE & REG_CAMERA_INT_FLASH_SEL_ENABLE_BIT)== 0)
        {
            IspIntStatus |= ISP_INT_TG_DONE;/* TG Done Interrupt */
        }
        else
        {
            IspIntStatus |= ISP_INT_VD_DONE;/* VD Done Interrupt */
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if ( IntStatus & REG_CAMERA_INT_AVSYNC_DONE_ENABLE_BIT) {
        IspVsyncTgFlag = KAL_TRUE;
        //frame rate check
        IspTimeTickBuff[IspTimeTick]=drv_get_current_time();
        IspTimeTick++;
        IspTimeTick%=CAMERA_TIME_TICK_BUFFER_COUNT;

        IspIntStatus |= ISP_INT_AVSYNC;
    }


    if ( IntStatus & REG_CAMERA_INT_GMC_OVERRUN_ENABLE_BIT) {
        IspGmcOverrunCnt++;
    }

    /* Activate Camera HISR */
    if (IspIntStatus!=0)
    {
        visual_active_hisr(VISUAL_CAMERA_HISR_ID);
    }
    else
    {
        IRQUnmask(IRQ_CAMERA_CODE);
    }
}	/* isp_LISR() */


void IspRecordFrameRate(void)
{
    kal_uint32 TimePeriod;
    
    if(IspTimeTickBuff[(IspTimeTick+CAMERA_TIME_TICK_BUFFER_COUNT-1)%CAMERA_TIME_TICK_BUFFER_COUNT] != IspTimeTickBuff[(IspTimeTick+CAMERA_TIME_TICK_BUFFER_COUNT-2)%CAMERA_TIME_TICK_BUFFER_COUNT])
    {
        TimePeriod =drv_get_duration_tick(IspTimeTickBuff[(IspTimeTick+CAMERA_TIME_TICK_BUFFER_COUNT-2)%CAMERA_TIME_TICK_BUFFER_COUNT],
                                          IspTimeTickBuff[(IspTimeTick+CAMERA_TIME_TICK_BUFFER_COUNT-1)%CAMERA_TIME_TICK_BUFFER_COUNT]);
        IspFrameRateBuff[IspFrameRateIndex]=327680/TimePeriod;

        IspCurrentFrameTime = (TimePeriod>>5);   // (TimePeriod << 10 )  >>15 ~= TimePeriod *1000/32768
        IspCurrentFrameRate = IspFrameRateBuff[IspFrameRateIndex];
        IspFrameRateIndex++;
        IspFrameRateIndex%=FRAME_RATE_BUFFER_SIZE;
    }
    IspTimeMeasureNow = IspTimeTickBuff[IspTimeTick];
    IspTimeMeasurePeriod = (drv_get_duration_tick(IspTimeMeasureBegin, IspTimeMeasureNow))>>5; //ms

    if(IspTimeMeasurePeriod>=ISP_TIME_MEASURE_PERIOD)
    {
        //send frame count   IspTimeMeasureFrameCount
        IspTimeMeasureFrameCount =  IspTimeMeasureFrameCount /ISP_TIME_MEASURE_DIVIDER; 
        IspFrameRateInfo.CurrentPreiodAvgFrames=IspTimeMeasureFrameCount;
        IspFrameRateInfo.CurrentFrameTime=IspCurrentFrameTime;
        IspFrameRateInfo.CurrentFrameRate=IspCurrentFrameRate;
        if(VIEW_FINDER_MODE_IS_ENABLE)
            SendMsgToCal(MSG_ID_CAL_INFORM_MDP_FRAME_RATE_REQ, &IspFrameRateInfo);

        IspTimeMeasureFrameCount=0;
        IspTimeMeasureBegin = IspTimeMeasureNow;
    }
    else
    {
        IspTimeMeasureFrameCount++;

    }
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


void IspYuvHISR(void)
{
    IMAGE_SENSOR_COMM_DATA_STRUCT SensorCommData;

    if (IspIntStatus & ISP_INT_ISP_DONE )
    {
        //if((REG_ISP_PATH_CONFIG & REG_CAMERA_PATH_JPGINF_EN_BIT) ==REG_CAMERA_PATH_JPGINF_EN_BIT)
       #if 0//defined(__JPEG_SENSOR_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if (defined(MT6276)||defined(MT6256)||defined(MT6255))
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
        #endif
    }

    if (IspIntStatus & ISP_INT_IDLE)
    {
        kal_set_eg_events(IspEventId,CAMERA_ISP_IDLE_EVENT,KAL_OR);
    }

    if (IspIntStatus & ISP_INT_FRAME_READY)
    {
        kal_set_eg_events(IspEventId,CAMERA_ISP_FRAME_READY_EVENT,KAL_OR);
        if ((IspImageSettingIndex!=0)&&(IspOperationState!=ISP_STANDBY_STATE)&&(stack_query_boot_mode()!=FACTORY_BOOT))
        {
            IspBackgndImageSetting();
        }
    #if defined (__AUTO_SCENE_DETECT_SUPPORT__)
        if (IspAsdCompensationIndex!=0)
        {
             IspBackgndSetAsdCompensation();
        }
    #endif
    }

    if ((IspIntStatus & ISP_INT_VD_DONE)||(IspIntStatus & ISP_INT_TG_DONE))
    {
    #if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
        IspPreviewFrameCount++;
    #endif

    #if (defined(WEBCAM_SUPPORT))
        IspWebcamBackgroundSettingAttr();       
    #endif
        /* //temporary marked
             if (KAL_TRUE==yuv_capture_check_enable)
             {
                 yuv_capture_vd_count++;
             }
             */
    #if (defined(AF_SUPPORT))
        if (IspWaitAFResult && pfImageSensor != NULL)        //Query AF result
        {
            if ((DELAYFRAME == IspAFQueryDelay.type) && (IspAFQueryDelay.count >0))
            {
                IspAFQueryDelay.count--;
            }
            else if (IspAFQueryDelay.count >0)
            {
                IspAFQueryDelay.count = IspAFQueryDelay.count - (IspTimeTickBuff[(IspTimeTick+CAMERA_TIME_TICK_BUFFER_COUNT-1)%CAMERA_TIME_TICK_BUFFER_COUNT]
                                       -IspTimeTickBuff[(IspTimeTick+CAMERA_TIME_TICK_BUFFER_COUNT-2)%CAMERA_TIME_TICK_BUFFER_COUNT]);
                if (IspAFQueryDelay.count <0)
                   IspAFQueryDelay.count = 0;
            }
            if (IspAFQueryDelay.count <=0)
            {
                SendMsgToCal(MSG_ID_CAL_LOW_GET_AF_RESULT, NULL);
            }
        }
    #endif
        kal_set_eg_events(IspEventId,CAMERA_ISP_VD_READY_EVENT,KAL_OR);

        IspRecordFrameRate();

        //if(IspCheckFirstVsync==KAL_TRUE){
        //CustomDriverFunc.SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE, &SensorCommCtrl, NULL, 0, NULL);
        if(pfImageSensor!=NULL)
        {
            SensorCommData.FeatureValue = IspCurrentFrameTime;
            pfImageSensor->SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME, &SensorCommData, NULL, 0, NULL);        
        }
        IspCheckFirstVsync=KAL_FALSE;
        //}
    }

    IRQUnmask(IRQ_CAMERA_CODE);

}


void IspCameraHISR(void)
{
    IspYuvHISR();
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

