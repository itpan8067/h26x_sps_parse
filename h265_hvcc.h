//
// Created by monktan on 2020/10/21.
//

#ifndef ZLMEDIAKIT_H265_HVCC_H
#define ZLMEDIAKIT_H265_HVCC_H

#include <stdint.h>
#include <assert.h>

#include "bs.h"
#include "h265_stream.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
   AVC decoder configuration record, ISO/IEC 14496-15:2004(E), Section 5.2.4.1
   Seen in seen in mp4 files as 'avcC' atom
   Seen in flv files as AVCVIDEOPACKET with AVCPacketType == 0
*/
typedef struct
{
    int configurationVersion; // = 1
} hvcc_t;

hvcc_t* hvcc_new();
void hvcc_free(hvcc_t* avcc);
int read_hvcc(hvcc_t* avcc, h265_stream_t* h, bs_t* b);
int write_hvcc(hvcc_t* avcc, h265_stream_t* h, bs_t* b);
int write_h265_hvcc(uint8_t* vps, int vps_size, uint8_t* sps, int sps_size, uint8_t* pps, int pps_size, bs_t* b);
void debug_hvcc(hvcc_t* avcc);

#ifdef __cplusplus
}
#endif



#endif //ZLMEDIAKIT_H265_HVCC_H