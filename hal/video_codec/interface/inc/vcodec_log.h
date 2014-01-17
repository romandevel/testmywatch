#ifndef VCODEC_LOG_H
#define VCODEC_LOG_H

#include "vcodec_if.h"


//Add your index here
typedef enum
{
    /* MPEG4 ENCODER */
    VCODEC_LOG_INDEX_MP4ENC_ENCODE_ERROR,
    VCODEC_LOG_INDEX_MP4ENC_ERROR_GET_BITSTREAM,
    VCODEC_LOG_INDEX_MP4ENC_ALLOCATE_EXT_MEMORY,
    VCODEC_LOG_INDEX_MP4ENC_FREE_EXT_MEMORY,
    VCODEC_LOG_INDEX_MP4ENC_QPHDR,
    VCODEC_LOG_INDEX_MP4ENC_FRAMETYPE,
    VCODEC_LOG_INDEX_MP4ENC_SETTING,
    VCODEC_LOG_INDEX_MP4ENC_GET_BITSTREAM,
    
    /* MPEG4 DECODER */
    VCODEC_LOG_INDEX_MP4DEC_DECODE_ERROR,
    VCODEC_LOG_INDEX_MP4DEC_DECODE_FIRST_FRAME,
    VCODEC_LOG_INDEX_MP4DEC_DECODE_VOP_TYPE,
    VCODEC_LOG_INDEX_MP4DEC_DECODE_RESOLUTION,
    VCODEC_LOG_INDEX_MP4DEC_DECODE_EOF,
    VCODEC_LOG_INDEX_MP4DEC_SET_FRAME_RATE,
    VCODEC_LOG_INDEX_MP4DEC_SET_BIT_RATE,
    VCODEC_LOG_INDEX_SWMP4DEC_SPEEDY_INIT_QTY,
    VCODEC_LOG_INDEX_SWMP4DEC_SPEEDY_INIT_DSWITCH,
    VCODEC_LOG_INDEX_SWMP4DEC_SPEEDY_SWITCH_QTY,
    VCODEC_LOG_INDEX_SWMP4DEC_DYNAMIC_SWITCH1,
    VCODEC_LOG_INDEX_SWMP4DEC_DYNAMIC_SWITCH2,
	
    /* RMVB DECODER */
	VCODEC_LOG_INDEX_RMDEC_DECODE_RESULT1,        
	VCODEC_LOG_INDEX_RMDEC_DECODE_RESULT2,
	VCODEC_LOG_INDEX_RMDEC_ERROR_FRM,
	VCODEC_LOG_INDEX_RMDEC_DECODE_ERROR,
	VCODEC_LOG_INDEX_RMDEC_HOLD_PIC_TYPE_ERROR,
	VCODEC_LOG_INDEX_RMDEC_UNKNOW_ERROR,
	VCODEC_LOG_INDEX_RMDEC_TIMESTAMP1,
	VCODEC_LOG_INDEX_RMDEC_TIMESTAMP2,
	VCODEC_LOG_INDEX_RMDEC_SKIP_FRM,
	VCODEC_LOG_INDEX_RMDEC_SKIP_SETTING2,
	VCODEC_LOG_INDEX_RMDEC_STANDARD_DEC,
	VCODEC_LOG_INDEX_RMDEC_LOSSY_DEC,
	VCODEC_LOG_INDEX_RMDEC_OPEN,
	VCODEC_LOG_INDEX_RMDEC_CLOSE,
	VCODEC_LOG_INDEX_RMDEC_UNSUPPORT,
	
	/* H.264 DECODER */
    VCODEC_LOG_INDEX_H264DEC_INIT,
    VCODEC_LOG_INDEX_H264DEC_DEINIT,
    VCODEC_LOG_INDEX_H264DEC_OPEN,
    VCODEC_LOG_INDEX_H264DEC_CLOSE,
    VCODEC_LOG_INDEX_H264DEC_INIT_ERROR,
    VCODEC_LOG_INDEX_H264DEC_DECODE_RESULT,
    VCODEC_LOG_INDEX_H264DEC_DECODE_ERROR,
    VCODEC_LOG_INDEX_H264DEC_ARGUMENT_ERROR,
    VCODEC_LOG_INDEX_H264DEC_SUPPORT_ERROR,
    VCODEC_LOG_INDEX_H264DEC_DECODING_CONCEAL,
    VCODEC_LOG_INDEX_H264DEC_DISPLAY_INFO,
    VCODEC_LOG_INDEX_H264DEC_CROP_INFO,
    VCODEC_LOG_INDEX_H264DEC_BITSTREAM_INFO,
    VCODEC_LOG_INDEX_H264DEC_PAYLOAD_INFO,
    VCODEC_LOG_INDEX_H264DEC_CHANGE_SPS,
    VCODEC_LOG_INDEX_H264DEC_ABNORMAL_NALU_SIZE,
    VCODEC_LOG_INDEX_H264DEC_HEADER_ERROR,
    VCODEC_LOG_INDEX_H264DEC_OUTPUT_IDR,
    VCODEC_LOG_INDEX_H264DEC_ALIGN_ERROR,
    VCODEC_LOG_INDEX_H264DEC_ALLOCATE_ERROR,
    VCODEC_LOG_INDEX_SWH264DEC_LOSSY_INIT_QTY,
    VCODEC_LOG_INDEX_SWH264DEC_LOSSY_INIT_DSWITCH,
    VCODEC_LOG_INDEX_SWH264DEC_LOSSY_SWITCH_QTY,
    VCODEC_LOG_INDEX_SWH264DEC_MEM_ALLOCATE,
    VCODEC_LOG_INDEX_SWH264DEC_DPB_INIT,
    VCODEC_LOG_INDEX_SWH264DEC_DPB_MARK_REFPIC,
    VCODEC_LOG_INDEX_SWH264DEC_CONCEAL,
    VCODEC_LOG_INDEX_SWH264DEC_OUTPIC1,
    VCODEC_LOG_INDEX_SWH264DEC_OUTPIC2,
    VCODEC_LOG_INDEX_SWH264DEC_EARLIER_OUTPUT,
    VCODEC_LOG_INDEX_SWH264DEC_EARLIER_OUTPUT_POC,
    VCODEC_LOG_INDEX_SWH264DEC_BSDDECODE_OUTPUT,
    VCODEC_LOG_INDEX_SWH264DEC_SPSDPB_CHECK,
    VCODEC_LOG_INDEX_H264DEC_SKIPB,
    VCODEC_LOG_INDEX_H264DEC_TIMESTAMP,
    VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_INIT,
    VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_INFO,
    VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_BP,
    VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_MPHP,
    VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_STATUS,
    VCODEC_LOG_INDEX_H264DEC_MODECHANGE_I,
    VCODEC_LOG_INDEX_H264DEC_MODECHANGE_P,
    VCODEC_LOG_INDEX_H264DEC_INPUT_TIMEINFO,
	
    /* H.264 Recorder */
    VCODEC_LOG_INDEX_H264ENC_STREAMBUFFER_ALLOC,
    VCODEC_LOG_INDEX_H264ENC_STREAMBUFFER_UPDATE,

	/* VP8 Decoder */
    VCODEC_LOG_INDEX_VP8DEC_GETMEMREQ,         
    VCODEC_LOG_INDEX_VP8DEC_OPEN,              
    VCODEC_LOG_INDEX_VP8DEC_CLOSE,             
    VCODEC_LOG_INDEX_VP8DEC_INIT,              
    VCODEC_LOG_INDEX_VP8DEC_DEINIT,            
    VCODEC_LOG_INDEX_VP8DEC_GETPARAM,          
    VCODEC_LOG_INDEX_VP8DEC_SETPARAM,          
    VCODEC_LOG_INDEX_VP8DEC_DECODEONEUNIT1,    
    VCODEC_LOG_INDEX_VP8DEC_GETNEXTDISPLAY,    
    VCODEC_LOG_INDEX_VP8DEC_LOSSY_SWITCH_QTY,     
    VCODEC_LOG_INDEX_VP8DEC_MODECHANGE_I,
    VCODEC_LOG_INDEX_VP8DEC_MODECHANGE_P,
    VCODEC_LOG_INDEX_VP8DEC_SUPPORT_ERROR,
    VCODEC_LOG_INDEX_VP8DEC_INPUT_TIMEINFO,
    VCODEC_LOG_INDEX_VP8DEC_STRM_INFO,
	
    /* COMMON */
    VCODEC_LOG_INDEX_COMMON_0,
    VCODEC_LOG_INDEX_COMMON_1,
    VCODEC_LOG_INDEX_COMMON_2,
    VCODEC_LOG_INDEX_COMMON_4,
    VCODEC_LOG_INDEX_COMMON_8,
    VCODEC_LOG_INDEX_MAX
} VCODEC_LOG_INDEX_T;

typedef enum
{
    VCODEC_LOG_GROUP_HIGH,
    VCODEC_LOG_GROUP_MEDIUM,
    VCODEC_LOG_GROUP_LOW,
    VCODEC_LOG_GROUP_MAX
} VCODEC_LOG_GROUP_T;

void VcodecTraceLog0(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex);
void VcodecTraceLog1(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg);
void VcodecTraceLog2(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2);
void VcodecTraceLog4(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4);
void VcodecTraceLog8(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5, UINT64 arg6, UINT64 arg7, UINT64 arg8);
#endif /* VCODEC_LOG_H */