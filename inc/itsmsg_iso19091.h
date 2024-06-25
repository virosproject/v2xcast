/* J2735 data frame and element defintions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_ISO19091_H__
#define __ITSMSG_ISO19091_H__
#include <limits.h>
#include "asn1defs_if.h"
#include "j2735_data_component.h"
#include "itsmsg_cdd.h"
#include "itsmsg_common.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    TimeReference_oneMilliSec = 1,
};

typedef struct ItsStationPosition {
    uint32_t stationID; /* StationID (0..4294967295) */
    BOOL laneID_option;
    int32_t laneID; /* LaneID (0..255) */
    BOOL nodeXY_option;
    NodeOffsetPointXY nodeXY;
    BOOL timeReference_option;
    int32_t timeReference; /* TimeReference V1(0..65535, V2(0..60000) */
} ItsStationPosition;

#define ItsStationPositionList_MAX_SIZE 5
typedef struct ItsStationPositionList {
    ItsStationPosition *tab;
    int count;
} ItsStationPositionList;

typedef struct ConnectionManeuverAssist_addGrpC {
    BOOL itsStationPosition_option;
    ItsStationPositionList itsStationPosition;
    BOOL rsuGNSSOffset_option;
    NodeOffsetPointXY rsuGNSSOffset;
} ConnectionManeuverAssist_addGrpC;

typedef struct ConnectionManeuverAssist_addGrpC_V2 {
    BOOL itsStationPosition_option;
    ItsStationPositionList itsStationPosition;
} ConnectionManeuverAssist_addGrpC_V2;

typedef struct ConnectionTrajectory_addGrpC {
    NodeSetXY nodes;
} ConnectionTrajectory_addGrpC;

typedef struct ConnectionTrajectory_addGrpC_V2 {
    NodeSetXY nodes;
    int32_t connectionID; /* LaneConnectionID (0..255) */
} ConnectionTrajectory_addGrpC_V2;

typedef struct PrioritizationResponse {
    uint32_t stationID; /* StationID (0..4294967295) */
    PrioritizationResponseStatus priorState;
    int32_t signalGroup; /* SignalGroupID (0..255) */
} PrioritizationResponse;

#define PrioritizationResponseList_MAX_SIZE 10
typedef struct PrioritizationResponseList {
    PrioritizationResponse *tab;
    int count;
} PrioritizationResponseList;

typedef struct IntersectionState_addGrpC {
    BOOL activePrioritizations_option;
    PrioritizationResponseList activePrioritizations;
} IntersectionState_addGrpC;

enum {
    VehicleMass_ITS_hundredKg = 1,
    VehicleMass_ITS_unavailable = 1024,
};

typedef struct LaneAttributes_addGrpC {
    BOOL maxVehicleHeight_option;
    int32_t maxVehicleHeight; /* VehicleHeight (0..127) */
    BOOL maxVehicleWeight_option;
    int32_t maxVehicleWeight; /* VehicleMass_ITS (1..1024) */
} LaneAttributes_addGrpC;


typedef enum ExceptionalCondition {
    ExceptionalCondition_unknown,
    ExceptionalCondition_publicTransportPriority,
    ExceptionalCondition_emergencyVehiclePriority,
    ExceptionalCondition_trainPriority,
    ExceptionalCondition_bridgeOpen,
    ExceptionalCondition_vehicleHeight,
    ExceptionalCondition_weather,
    ExceptionalCondition_trafficJam,
    ExceptionalCondition_tunnelClosure,
    ExceptionalCondition_meteringActive,
    ExceptionalCondition_truckPriority,
    ExceptionalCondition_bicyclePlatoonPriority,
    ExceptionalCondition_vehiclePlatoonPriority,
} ExceptionalCondition;

typedef struct MovementEvent_addGrpC {
    BOOL stateChangeReason_option;
    ExceptionalCondition stateChangeReason;
} MovementEvent_addGrpC;

typedef enum PtvRequestType {
    PtvRequestType_preRequest,
    PtvRequestType_mainRequest,
    PtvRequestType_doorCloseRequest,
    PtvRequestType_cancelRequest,
    PtvRequestType_emergencyRequest,
    PtvRequestType_MAX = UINT_MAX
} PtvRequestType;

typedef struct Control_addGrpC {
    PtvRequestType ptvRequest;
} Control_addGrpC;


typedef struct Node {
    int32_t id;
    BOOL lane_option;
    int32_t lane; /* LaneID (0..255) */
    BOOL connectionID_option;
    int32_t connectionID; /* LaneConnectionID (0..255) */
    BOOL intersectionID_option;
    int32_t intersectionID; /* IntersectionID (0..65535) */
} Node;

#define NodeLink_MAX_SIZE 5
typedef struct NodeLink {
    Node *tab;
    int32_t count;
} NodeLink;

typedef struct NodeAttributeSet_addGrpC {
    BOOL ptvRequest_option;
    PtvRequestType ptvRequest;
    BOOL nodeLink_option;
    NodeLink nodeLink;
    BOOL node_option;
    Node node;
} NodeAttributeSet_addGrpC;

typedef struct LaneDataAttribute_addGrpB {
    uint8_t dummy_field;
} LaneDataAttribute_addGrpB;

typedef struct MovementEvent_addGrpB {
    BOOL startTime_option;
    int32_t startTime; /* TimeRemaining (0..9001) */
    int32_t minEndTime; /* MinTimetoChange (0..2402) */
    BOOL maxEndTime_option;
    int32_t maxEndTime; /* MaxTimetoChange (0..2402) */
    BOOL likelyTime_option;
    int32_t likelyTime; /* TimeRemaining (0..9001) */
    BOOL confidence_option;
    int32_t confidence; /* TimeIntervalConfidence (0..15) */
    BOOL nextTime_option;
    int32_t nextTime; /* TimeRemaining (0..9001) */
} MovementEvent_addGrpB;

typedef struct Node_LLdms_48b {
    int32_t lon; /* LongitudeDMS (-64800000..64800000) */
    int32_t lat; /* LatitudeDMS (-32400000..32400000) */
} Node_LLdms_48b;

typedef struct LongitudeDMS2 {
    int32_t d; /* DegreesLong (-180..180) */
    int32_t m; /* MinutesAngle (0..59) */
    int32_t s; /* SecondsAngle (0..5999) */
} LongitudeDMS2;

typedef struct LatitudeDMS2 {
    int32_t d; /* DegreesLat (-90..90) */
    int32_t m; /* MinutesAngle (0..59) */
    int32_t s; /* SecondsAngle (0..5999) */
} LatitudeDMS2;

typedef struct Node_LLdms_80b {
    LongitudeDMS2 lon;
    LatitudeDMS2 lat;
} Node_LLdms_80b;

typedef enum {
    NodeOffsetPointXY_addGrpB_posA,
    NodeOffsetPointXY_addGrpB_posB,
} NodeOffsetPointXY_addGrpB_choice;

typedef struct NodeOffsetPointXY_addGrpB {
    NodeOffsetPointXY_addGrpB_choice choice;
    union {
        Node_LLdms_48b posA;
        Node_LLdms_80b posB;
    } u;
} NodeOffsetPointXY_addGrpB;

typedef struct Position3D_addGrpB {
    LatitudeDMS2 latitude;
    LongitudeDMS2 longitude;
    int32_t elevation; /* Elevation_addGrpB (-32768..32767) */
} Position3D_addGrpB;

typedef struct Position3D_addGrpC {
    Altitude altitude;
} Position3D_addGrpC;

typedef enum BatteryStatus {
    BatteryStatus_unknown,
    BatteryStatus_critical,
    BatteryStatus_low,
    BatteryStatus_good,
} BatteryStatus;

typedef struct RequestorDescription_addGrpC {
    BOOL fuel_option;
    int32_t fuel; /* FuelType (0..15) */
    BOOL batteryStatus_option;
    BatteryStatus batteryStatus;
} RequestorDescription_addGrpC;

typedef enum EmissionType {
    EmissionType_euro1,
    EmissionType_euro2,
    EmissionType_euro3,
    EmissionType_euro4,
    EmissionType_euro5,
    EmissionType_euro6,
    EmissionType_MAX = UINT_MAX
} EmissionType;

typedef struct RestrictionUserType_addGrpC {
    BOOL emission_option;
    EmissionType emission;
} RestrictionUserType_addGrpC;


typedef struct RestrictionUserType_addGrpC_V2 {
    BOOL emission_option;
    EmissionType emission;
    BOOL fuel_option;
    int32_t fuel; /* FuelType (0..15) */
} RestrictionUserType_addGrpC_V2;

typedef enum RejectedReason {
    RejectedReason_unknown,
    RejectedReason_exceptionalCondition,
    RejectedReason_maxWaitingTimeExceeded,
    RejectedReason_ptPriorityDisabled,
    RejectedReason_higherPTPriorityGranted,
    RejectedReason_vehicleTrackingUnknown,
} RejectedReason;

typedef struct SignalStatusPackage_addGrpC {
    BOOL synchToSchedule_option;
    int32_t synchToSchedule; /* DeltaTime (-122 .. 121) */
} SignalStatusPackage_addGrpC;

typedef struct SignalStatusPackage_addGrpC_V2 {
    BOOL synchToSchedule_option;
    int32_t synchToSchedule; /* DeltaTime (-122..121) */
    BOOL rejectedReason_option;
    RejectedReason rejectedReason;
} SignalStatusPackage_addGrpC_V2;

typedef struct SignalHeadLocation {
    NodeOffsetPointXY nodeXY;
    int32_t nodeZ; /* DeltaAltitude (-12700..12800) */
    int32_t signalGroup; /* SignalGroupID (0..255) */
} SignalHeadLocation;

#define SignalHeadLocationList_MAX_SIZE 64
typedef struct SignalHeadLocationList {
    SignalHeadLocation *tab;
    int count;
} SignalHeadLocationList;

typedef struct MapData_addGrpC {
    BOOL signalHeadLocations_option;
    SignalHeadLocationList signalHeadLocations;
} MapData_addGrpC;

typedef enum Holiday {
    Holiday_weekday,
    Holiday_holiday,
    Holiday_MAX = UINT_MAX
} Holiday;

typedef enum SummerTime {
    SummerTime_notInSummerTime,
    SummerTime_inSummerTime,
    SummerTime_MAX = UINT_MAX
} SummerTime;

#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_ISO19091_H__ */
