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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * MT6256_RDS_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio RDS Driver (MT6256)
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#if (defined(MT6256FM)&&defined(__FM_RADIO_RDS_SUPPORT__))
#include "kal_general_types.h"
#include "MT6256.h"

extern kal_bool MT6256_ReadByte(kal_uint8 CW, kal_uint16 * data);
extern kal_bool MT6256_WriteByte(kal_uint8 CW, kal_uint16 data);
extern void Delayus(kal_uint32 u4MicroSec);

void FMDrv_RDS_GetData(kal_uint16 *data)
{
	MT6256_WriteByte(FM_PG_SEL, 3);
	MT6256_ReadByte(RDS_DATA_A_E_REG, &data[0]);
	Delayus(83);
	MT6256_ReadByte(RDS_DATA_A_E_REG, &data[1]);
	Delayus(83);
	MT6256_ReadByte(RDS_DATA_A_E_REG, &data[2]);
	Delayus(83);
	MT6256_ReadByte(RDS_DATA_A_E_REG, &data[3]);
	Delayus(83);
	MT6256_ReadByte(RDS_DATA_CRC_FFOST, &data[4]);
	MT6256_WriteByte(FM_PG_SEL, 0);
}

void FMDrv_RDS_Enable(void)
{
	kal_uint16 dataRead;

	MT6256_ReadByte(FM_MAIN_INTRMASK, &dataRead);
	MT6256_WriteByte(FM_MAIN_INTRMASK, dataRead|INTR_RDS_MASK);
	//MT6256_ReadByte(FM_MAIN_EXTINTRMASK, &dataRead);
	//MT6256_WriteByte(FM_MAIN_EXTINTRMASK, dataRead|EXT_RDS_MASK);
	MT6256_ReadByte(FM_MAIN_CTRL, &dataRead);
	MT6256_WriteByte(FM_MAIN_CTRL, dataRead|RDS_MASK);
	MT6256_WriteByte(FM_PG_SEL, 3);
	MT6256_WriteByte(RDS_FFOST_TRIG_TH, 0xE016);
	MT6256_WriteByte(RDS_BER_THD_SET_REG, 0x2d0);
	MT6256_WriteByte(FM_PG_SEL, 0);
	//MT6256_ReadByte(RDS_BDGRP_ABD_CTRL_REG, &dataRead);
	//MT6256_WriteByte(RDS_BDGRP_ABD_CTRL_REG, dataRead|BDGRP_ABD_EN);
}

void FMDrv_RDS_Disable(void)
{
	kal_uint16 dataRead;

	//MT6256_ReadByte(FM_MAIN_EXTINTRMASK, &dataRead);
	//MT6256_WriteByte(FM_MAIN_EXTINTRMASK, dataRead&(~EXT_RDS_MASK));
	MT6256_ReadByte(FM_MAIN_INTRMASK, &dataRead);
	MT6256_WriteByte(FM_MAIN_INTRMASK, dataRead&(~INTR_RDS_MASK));
	MT6256_ReadByte(FM_MAIN_CTRL, &dataRead);
	MT6256_WriteByte(FM_MAIN_CTRL, dataRead&0xFFEF);
}
kal_bool FMDrv_RDS_RegChk(void)
{
	kal_uint16 dataRead;

	/*MT6256_WriteByte(0x2F, 1);
	MT6256_ReadByte(0x79, &dataRead);
	MT6256_WriteByte(0x2F, 0);
	if(dataRead&0x4000) //RDS not Support
	{
		return 0;
	}
	else //RDS Support */
	{
		return KAL_TRUE;
	}
}

void FMDrv_RDS_Reset(void)
{
	MT6256_WriteByte(FM_PG_SEL, 3);
	MT6256_WriteByte(RDS_RESET, 0x01);
	MT6256_WriteByte(FM_PG_SEL, 0);
}

void FMDrv_RDS_BlockReset(void)
{
	MT6256_WriteByte(FM_DAC_CON2, 0x8702);
	Delayus(85);
	MT6256_WriteByte(FM_DAC_CON2, 0x0702);
}

void FMDrv_RDS_INTR_OnOff(kal_bool isOn)
{
	kal_uint16 dataRead;
	
	if(isOn)
	{
		MT6256_ReadByte(FM_MAIN_INTRMASK, &dataRead);
		MT6256_WriteByte(FM_MAIN_INTRMASK, dataRead|INTR_RDS_MASK);
	}
	else
	{
		MT6256_ReadByte(FM_MAIN_INTRMASK, &dataRead);
		MT6256_WriteByte(FM_MAIN_INTRMASK, dataRead&(~INTR_RDS_MASK));	
	}
}

kal_uint16 FMDrv_RDS_Get_BKValue(kal_uint16 *block, kal_uint8 offset)
{
	kal_uint16 dataRead;
	MT6256_WriteByte(FM_PG_SEL, 3);
	MT6256_ReadByte(RDS_DATA_A_E_REG+offset, &dataRead);
	*(block+offset) = dataRead;
	MT6256_WriteByte(FM_PG_SEL, 0);
}

void FMDrv_RDS_Reset_BKCnt(void)
{
	MT6256_WriteByte(FM_PG_SEL, 3);
	MT6256_WriteByte(RDS_BKCNT_RESET, 0x01);
	MT6256_WriteByte(RDS_BKCNT_RESET, 0x02);
	MT6256_WriteByte(FM_PG_SEL, 0);
}

kal_uint16 FMDrv_RDS_Read_BKCnt(kal_bool Val)
{
	kal_uint16 dataRead;

	MT6256_WriteByte(FM_PG_SEL, 3);
	if(Val)
		MT6256_ReadByte(RDS_GOODBK_CNT, &dataRead);
	else
		MT6256_ReadByte(RDS_BADBK_CNT, &dataRead);
	return dataRead;
	MT6256_WriteByte(FM_PG_SEL, 0);
}

#endif // defined(MT6256&&FM_RADIO_RDS_SUPPORT)
