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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2004
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   imps.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   imps related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*---------------IMPS_MSG_CODE_BEGIN---------------------------*/
    MSG_ID_MMI_IMPS_LOGIN_REQ = MSG_ID_IMPS_CODE_BEGIN,
    MSG_ID_MMI_IMPS_LOGIN_AUTH_IND,
    MSG_ID_MMI_IMPS_LOGIN_RSP,

    MSG_ID_MMI_IMPS_LOGIN_PROGRESS_IND,

    MSG_ID_MMI_IMPS_LOGOUT_REQ,
    MSG_ID_MMI_IMPS_LOGOUT_RSP,

    MSG_ID_MMI_IMPS_DISCONNECT_IND,

    /* WLAN prefer*/
    MSG_ID_MMI_IMPS_BEARER_DISCONNECT_IND,
    MSG_ID_MMI_IMPS_BEARER_RECONNECT_REQ,
    MSG_ID_MMI_IMPS_BEARER_RECONNECT_RSP,
    
    MSG_ID_MMI_IMPS_ABORT_LOGIN_REQ,
    MSG_ID_MMI_IMPS_ABORT_LOGIN_RSP,
    MSG_ID_MMI_IMPS_ABORT_SEARCH_REQ,
    MSG_ID_MMI_IMPS_ABORT_SEARCH_RSP,

    MSG_ID_MMI_IMPS_SEARCH_REQ,
    MSG_ID_MMI_IMPS_SEARCH_RSP,

    MSG_ID_MMI_IMPS_INVITE_REQ,
    MSG_ID_MMI_IMPS_INVITE_RSP,
    MSG_ID_MMI_IMPS_INVITE_IND,
    MSG_ID_MMI_IMPS_INVITE_REPLY_REQ,
    MSG_ID_MMI_IMPS_INVITE_REPLY_RSP,
    MSG_ID_MMI_IMPS_INVITE_RESPONSE_IND,

    MSG_ID_MMI_IMPS_DELIVERY_METHOD_REQ,
    MSG_ID_MMI_IMPS_DELIVERY_METHOD_RSP,
    MSG_ID_MMI_IMPS_SEND_MESSAGE_REQ,
    MSG_ID_MMI_IMPS_SEND_MESSAGE_RSP,
    MSG_ID_MMI_IMPS_SEND_MESSAGE_RESULT_IND,
    MSG_ID_MMI_IMPS_NEWMESSAGE_IND,
    MSG_ID_MMI_IMPS_MESSAGENOTIFY_IND,
    MSG_ID_MMI_IMPS_OFFLINE_MESSAGE_IND,
    MSG_ID_MMI_IMPS_GET_MESSAGE_REQ,
    MSG_ID_MMI_IMPS_GET_MESSAGE_RSP,
    MSG_ID_MMI_IMPS_REJECT_MESSAGE_REQ,
    MSG_ID_MMI_IMPS_REJECT_MESSAGE_RSP,
    MSG_ID_MMI_IMPS_FORWARD_MESSAGE_REQ,
    MSG_ID_MMI_IMPS_FORWARD_MESSAGE_RSP,
    MSG_ID_MMI_IMPS_LIST_MESSAGE_REQ,
    MSG_ID_MMI_IMPS_LIST_MESSAGE_RSP,
    MSG_ID_MMI_IMPS_GET_BLOCK_LIST_REQ,
    MSG_ID_MMI_IMPS_GET_BLOCK_LIST_RSP,
    MSG_ID_MMI_IMPS_BLOCK_ENTITY_REQ,
    MSG_ID_MMI_IMPS_BLOCK_ENTITY_RSP,

    MSG_ID_MMI_IMPS_CREATE_GROUP_REQ,
    MSG_ID_MMI_IMPS_CREATE_GROUP_RSP,
    MSG_ID_MMI_IMPS_DELETE_GROUP_REQ,
    MSG_ID_MMI_IMPS_DELETE_GROUP_RSP,
    MSG_ID_MMI_IMPS_JOIN_GROUP_REQ,
    MSG_ID_MMI_IMPS_JOIN_GROUP_RSP,
    MSG_ID_MMI_IMPS_LEAVE_GROUP_REQ,
    MSG_ID_MMI_IMPS_LEAVE_GROUP_RSP,
    MSG_ID_MMI_IMPS_LEAVE_GROUP_IND,
    MSG_ID_MMI_IMPS_GROUP_CHANGE_NOTIFY_IND,

    MSG_ID_MMI_IMPS_ADD_CONTACT_LIST_REQ,
    MSG_ID_MMI_IMPS_ADD_CONTACT_LIST_RSP,
    MSG_ID_MMI_IMPS_GET_CONTACT_LIST_REQ,
    MSG_ID_MMI_IMPS_GET_CONTACT_LIST_RSP,
    MSG_ID_MMI_IMPS_ABORT_GET_CONTACT_LIST_REQ,
    MSG_ID_MMI_IMPS_ABORT_GET_CONTACT_LIST_RSP,
    MSG_ID_MMI_IMPS_VIEW_CONTACT_LIST_REQ,
    MSG_ID_MMI_IMPS_VIEW_CONTACT_LIST_RSP,
    MSG_ID_MMI_IMPS_ABORT_VIEW_CONTACT_LIST_REQ,
    MSG_ID_MMI_IMPS_ABORT_VIEW_CONTACT_LIST_RSP,
    MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_REQ,
    MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_RSP,
    MSG_ID_MMI_IMPS_DEL_CONTACT_LIST_REQ,
    MSG_ID_MMI_IMPS_DEL_CONTACT_LIST_RSP,
    MSG_ID_MMI_IMPS_SUBS_PA_REQ,
    MSG_ID_MMI_IMPS_SUBS_PA_RSP,
    MSG_ID_MMI_IMPS_ABORT_SUBS_PA_REQ,
    MSG_ID_MMI_IMPS_ABORT_SUBS_PA_RSP,
    MSG_ID_MMI_IMPS_UNSUBS_PA_REQ,
    MSG_ID_MMI_IMPS_UNSUBS_PA_RSP,
    MSG_ID_MMI_IMPS_GET_PA_REQ,
    MSG_ID_MMI_IMPS_GET_PA_RSP,
    MSG_ID_MMI_IMPS_ABORT_GET_PA_REQ,
    MSG_ID_MMI_IMPS_ABORT_GET_PA_RSP,
    MSG_ID_MMI_IMPS_PA_NOTIFY_IND,
    MSG_ID_MMI_IMPS_UPDATE_PA_REQ,
    MSG_ID_MMI_IMPS_UPDATE_PA_RSP,
    MSG_ID_MMI_IMPS_PA_AUTH_IND,
    MSG_ID_MMI_IMPS_PA_AUTH_USER_REQ,
    MSG_ID_MMI_IMPS_PA_AUTH_USER_RSP,
    MSG_ID_MMI_IMPS_PA_CANCEL_AUTH_REQ,
    MSG_ID_MMI_IMPS_PA_CANCEL_AUTH_RSP,
    MSG_ID_MMI_IMPS_GET_WATCHER_LIST_REQ,
    MSG_ID_MMI_IMPS_GET_WATCHER_LIST_RSP,
    MSG_ID_MMI_IMPS_ABORT_GET_WATCHER_LIST_REQ,
    MSG_ID_MMI_IMPS_ABORT_GET_WATCHER_LIST_RSP,
    MSG_ID_MMI_IMPS_PUSH_IND,
    MSG_ID_MMI_IMPS_READY_IND,

    MSG_ID_MMI_IMPS_GET_GROUP_MEMBER_REQ,
    MSG_ID_MMI_IMPS_GET_GROUP_MEMBER_RSP,
    MSG_ID_MMI_IMPS_GET_JOINED_USER_REQ,
    MSG_ID_MMI_IMPS_GET_JOINED_USER_RSP,
    MSG_ID_MMI_IMPS_ADD_GROUP_MEMBER_REQ,
    MSG_ID_MMI_IMPS_ADD_GROUP_MEMBER_RSP,
    MSG_ID_MMI_IMPS_REMOVE_GROUP_MEMBER_REQ,
    MSG_ID_MMI_IMPS_REMOVE_GROUP_MEMBER_RSP,
    MSG_ID_MMI_IMPS_MEMBER_ACCESS_REQ,
    MSG_ID_MMI_IMPS_MEMBER_ACCESS_RSP,
    MSG_ID_MMI_IMPS_REJECT_GROUP_USER_REQ,
    MSG_ID_MMI_IMPS_REJECT_GROUP_USER_RSP,
    MSG_ID_MMI_IMPS_ABORT_GET_GROUP_MEMBER_REQ,
    MSG_ID_MMI_IMPS_ABORT_GET_GROUP_MEMBER_RSP,
    MSG_ID_MMI_IMPS_ABORT_GET_JOINED_USER_REQ,
    MSG_ID_MMI_IMPS_ABORT_GET_JOINED_USER_RSP,
    MSG_ID_MMI_IMPS_ABORT_GET_REJECTED_USER_REQ,
    MSG_ID_MMI_IMPS_ABORT_GET_REJECTED_USER_RSP,

    MSG_ID_MMI_IMPS_SYSTEM_MSG_IND,
    MSG_ID_MMI_IMPS_SYSTEM_MSG_USER_REQ,
    MSG_ID_MMI_IMPS_SYSTEM_MSG_USER_RSP,
    MSG_ID_MMI_IMPS_SUBS_NOTIFY_REQ,
    MSG_ID_MMI_IMPS_SUBS_NOTIFY_RSP,
    MSG_ID_MMI_IMPS_UNSUBS_NOTIFY_REQ,
    MSG_ID_MMI_IMPS_UNSUBS_NOTIFY_RSP,  
    MSG_ID_MMI_IMPS_NOTIFY_REQUEST_IND,
    MSG_ID_MMI_IMPS_GET_PP_REQ,
    MSG_ID_MMI_IMPS_GET_PP_RSP,
    MSG_ID_MMI_IMPS_ABORT_GET_PP_REQ,
    MSG_ID_MMI_IMPS_ABORT_GET_PP_RSP,
    MSG_ID_MMI_IMPS_UPDATE_PP_REQ,
    MSG_ID_MMI_IMPS_UPDATE_PP_RSP,
    MSG_ID_MMI_IMPS_DL_FILE_REQ,
    MSG_ID_MMI_IMPS_DL_FILE_RSP,
    MSG_ID_MMI_IMPS_CREATE_ATTRIBUTE_LIST_REQ,
    MSG_ID_MMI_IMPS_CREATE_ATTRIBUTE_LIST_RSP,
    MSG_ID_MMI_IMPS_HTTP_AUTH_IND,   
    MSG_ID_MMI_IMPS_HTTP_AUTH_RES,
    MSG_ID_MMI_IMPS_EXT_CONV_REQ,
    MSG_ID_MMI_IMPS_EXT_CONV_RSP,
    MSG_ID_MMI_IMPS_EXT_CONV_IND,
    MSG_ID_IMPS_CODE_END = MSG_ID_MMI_IMPS_EXT_CONV_IND,
/*---------------IMPS_MSG_CODE_END---------------------------*/
