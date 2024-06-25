/* J2735 PDM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_PDM_H__
#define __J2735_PDM_H__

#include "j2735_data_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ProbeDataManagement {
    BOOL timeStamp_option;
    int32_t timeStamp; /* MinuteOfTheYear (0..527040) */
    Sample sample;
    BitString directions; /* HeadingSlice (16..16) */
    TermConfig term;
    SnapshotConfig snapshot;
    int32_t txInterval; /* SecondOfTime (0..61) */
    BOOL dataElements_option;
    VehicleStatusRequestList dataElements;
    BOOL regional_option;
    Reg_ProbeDataManagementList regional;
} ProbeDataManagement;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_PDM_H__ */
