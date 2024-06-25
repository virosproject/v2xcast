/* ITS-G5 SPATEM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_SREM_H__
#define __ITSMSG_SREM_H__


#include "itsmsg_cdd.h"
#include "j2735_srm.h"
#include "itsmsg_iso19091.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SREM_V2 {
    ItsPduHeader header;
    SignalRequestMessage srm;
} SREM_V2;

#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_SREM_H__ */
