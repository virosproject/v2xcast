/* ITS-G5 SPATEM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_SSEM_H__
#define __ITSMSG_SSEM_H__


#include "itsmsg_cdd.h"
#include "j2735_ssm.h"
#include "itsmsg_iso19091.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SSEM_V2 {
    ItsPduHeader header;
    SignalStatusMessage ssm;
} SSEM_V2;

#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_SSEM_H__ */
