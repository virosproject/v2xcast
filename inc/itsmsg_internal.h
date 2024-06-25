/*  ITS-G5 message API for internal
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_INTERNAL_H__
#define __ITSMSG_INTERNAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itsmsg_codec.h"

extern int itsmsg_xer_encode(uint8_t **buf, ItsPduHeader *msg);
extern int itsmsg_xer_decode(ItsPduHeader **msg, const uint8_t *buf, const unsigned int buf_len, ITSMsgCodecErr *err);

#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_INTERNAL_H__ */