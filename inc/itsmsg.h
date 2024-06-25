/* ITS-G5 message definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_H__
#define __ITSMSG_H__


#ifdef __cplusplus
extern "C" {
#endif


typedef enum ITSmsgID {
    DENM_Id = 1,
    CAM_Id = 2,
    /*  POI_Id = 3, */
    SPATEM_Id = 4,
    MAPEM_Id = 5,
    IVIM_Id = 6,
    /*  EV_RSR_Id = 7 */
    /*  TISTPGTRANSACTION_Id = 8, */
    SREM_Id = 9,
    SSEM_Id = 10,
    /*  EVCSN_Id = 11, */
    SAEM_Id = 12,
    RTCMEM_Id = 13,
    VAM_Id = 14,
} ITSmsgID;

#include "itsmsg_denm.h"
#include "itsmsg_cam.h"
#include "itsmsg_spatem.h"
#include "itsmsg_mapem.h"
#include "itsmsg_ivim.h"
#include "itsmsg_srem.h"
#include "itsmsg_ssem.h"
#include "itsmsg_saem.h"
#include "itsmsg_rtcmem.h"
#include "itsmsg_vam.h"


#ifdef __cplusplus
}
#endif


#endif /* __ITSMSG_H__ */
