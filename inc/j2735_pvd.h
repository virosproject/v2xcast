/* J2735 PVD definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_PVD_H__
#define __J2735_PVD_H__

#include "j2735_data_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ProbeVehicleData {
    BOOL timeStamp_option;
    int32_t timeStamp; /* MinuteOfTheYear (0..527040) */
    BOOL segNum_option;
    int32_t segNum; /* ProbeSegmentNumber (0..32767) */
    BOOL probeID_option;
    VehicleIdent probeID;
    FullPositionVector startVector;
    VehicleClassification vehicleType;
    SnapshotList snapshots;
    BOOL regional_option;
    Reg_ProbeVehicleDataList regional;
} ProbeVehicleData;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_PVD_H__ */
