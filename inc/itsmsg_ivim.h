/* ITS-G5 IVIM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_IVIM_H__
#define __ITSMSG_IVIM_H__


#include "itsmsg_cdd.h"
#include "itsmsg_iso19321.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct IVIM_V2 {
    ItsPduHeader header;
    IviStructure ivi;
} IVIM_V2;

#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_IVIM_H__ */
