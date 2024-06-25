/* ITS-G5 VAM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_VAM_H__
#define __ITSMSG_VAM_H__


#include "itsmsg_cdd.h"
#include "itsmsg_cam.h"
#include "itsmsg_iso19091.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef Heading VruOrientation;
typedef Heading VruRollAngle;


typedef enum OffRoadLanePosition {
    OffRoadLanePosition_unavailable,
    OffRoadLanePosition_sidewalk,
    OffRoadLanePosition_parkingLane,
    OffRoadLanePosition_bikeLane,
    OffRoadLanePosition_max,
    OffRoadLanePosition_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} OffRoadLanePosition;

typedef struct MapPosition {
    IntersectionReferenceID intersectionId;
    int32_t lane; /* LaneID (0..255) */
} MapPosition;

typedef enum {
    NonIslandLanePosition_offRoadLanePosition,
    NonIslandLanePosition_vehicularLanePosition,
    NonIslandLanePosition_mapPosition,
} NonIslandLanePosition_choice;

typedef struct NonIslandLanePosition {
    NonIslandLanePosition_choice choice;
    union {
        OffRoadLanePosition offRoadLanePosition;
        int32_t vehicularLanePosition; /* LanePosition (-1..14) */
        MapPosition mapPosition;
    } u;
} NonIslandLanePosition;

typedef struct TrafficIslandPosition {
    NonIslandLanePosition oneSide;
    NonIslandLanePosition otherSide;
} TrafficIslandPosition;

typedef enum {
    VruLanePosition_offRoadLanePosition,
    VruLanePosition_vehicularLanePosition,
    VruLanePosition_trafficIslandPosition,
    VruLanePosition_mapPosition,
} VruLanePosition_choice;

typedef struct VruLanePosition {
    VruLanePosition_choice choice;
    union {
        OffRoadLanePosition offRoadLanePosition;
        int32_t vehicularLanePosition; /* LanePosition (-1..14) */
        TrafficIslandPosition trafficIslandPosition;
        MapPosition mapPosition;
    } u;
} VruLanePosition;

typedef enum VruEnvironment {
    VruEnvironment_unavailable,
    VruEnvironment_intersectionCrossing,
    VruEnvironment_zebraCrossing,
    VruEnvironment_sidewalk,
    VruEnvironment_onVehicleRoad,
    VruEnvironment_protectedGeographicArea,
    VruEnvironment_max,
    VruEnvironment_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruEnvironment;

typedef enum VruMovementControl {
    VruMovementControl_unavailable,
    VruMovementControl_braking,
    VruMovementControl_hardBraking,
    VruMovementControl_stopPedaling,
    VruMovementControl_brakingAndStopPedaling,
    VruMovementControl_hardBrakingAndStopPedaling,
    VruMovementControl_noReaction,
    VruMovementControl_max,
    VruMovementControl_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruMovementControl;

typedef enum VruDeviceUsage {
    VruDeviceUsage_unavailable,
    VruDeviceUsage_other,
    VruDeviceUsage_idle,
    VruDeviceUsage_listeningToAudio,
    VruDeviceUsage_typing,
    VruDeviceUsage_calling,
    VruDeviceUsage_playingGames,
    VruDeviceUsage_reading,
    VruDeviceUsage_viewing,
    VruDeviceUsage_max,
    VruDeviceUsage_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruDeviceUsage;

typedef struct VruHighFrequencyContainer {
    Heading heading; /* Heading (0..28800) */
    Speed speed; /* Speed (0..8191) */
    LongitudinalAcceleration longitudinalAcceleration;
    BOOL curvature_option;
    Curvature curvature;
    BOOL curvatureCalculationMode_option;
    CurvatureCalculationMode curvatureCalculationMode;
    BOOL yawRate_option;
    YawRate yawRate; /* YawRate (-32767..32767) */
    BOOL lateralAcceleration_option;
    LateralAcceleration lateralAcceleration;
    BOOL verticalAcceleration_option;
    VerticalAcceleration verticalAcceleration; /* VerticalAcceleration (-127..127) */
    BOOL vruLanePosition_option;
    VruLanePosition vruLanePosition;
    BOOL environment_option;
    VruEnvironment environment;
    BOOL movementControl_option;
    VruMovementControl movementControl;
    BOOL orientation_option;
    VruOrientation orientation;
    BOOL rollAngle_option;
    VruRollAngle rollAngle;
    BOOL deviceUsage_option;
    VruDeviceUsage deviceUsage;
} VruHighFrequencyContainer;

typedef enum VruSubProfilePedestrian {
    VruSubProfilePedestrian_unavailable,
    VruSubProfilePedestrian_ordinary_pedestrian,
    VruSubProfilePedestrian_road_worker,
    VruSubProfilePedestrian_first_responder,
    VruSubProfilePedestrian_max,
    VruSubProfilePedestrian_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruSubProfilePedestrian;

typedef enum VruSubProfileBicyclist {
    VruSubProfileBicyclist_unavailable,
    VruSubProfileBicyclist_bicyclist,
    VruSubProfileBicyclist_wheelchair_user,
    VruSubProfileBicyclist_horse_and_rider,
    VruSubProfileBicyclist_rollerskater,
    VruSubProfileBicyclist_e_scooter,
    VruSubProfileBicyclist_personal_transporter,
    VruSubProfileBicyclist_pedelec,
    VruSubProfileBicyclist_speed_pedelec,
    VruSubProfileBicyclist_max,
    VruSubProfileBicyclist_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruSubProfileBicyclist;

typedef enum VruSubProfileMotorcyclist {
    VruSubProfileMotorcyclist_unavailable,
    VruSubProfileMotorcyclist_moped,
    VruSubProfileMotorcyclist_motorcycle,
    VruSubProfileMotorcyclist_motorcycle_and_sidecar_right,
    VruSubProfileMotorcyclist_motorcycle_and_sidecar_left,
    VruSubProfileMotorcyclist_max,
    VruSubProfileMotorcyclist_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruSubProfileMotorcyclist;

typedef enum VruSubProfileAnimal {
    VruSubProfileAnimal_unavailable,
    VruSubProfileAnimal_wild_animal,
    VruSubProfileAnimal_farm_animal,
    VruSubProfileAnimal_service_animal,
    VruSubProfileAnimal_max,
    VruSubProfileAnimal_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruSubProfileAnimal;

typedef enum {
    VruProfileAndSubprofile_pedestrian,
    VruProfileAndSubprofile_bicyclist,
    VruProfileAndSubprofile_motorcylist,
    VruProfileAndSubprofile_animal,
} VruProfileAndSubprofile_choice;

typedef struct VruProfileAndSubprofile {
    VruProfileAndSubprofile_choice choice;
    union {
        VruSubProfilePedestrian pedestrian;
        VruSubProfileBicyclist bicyclist;
        VruSubProfileMotorcyclist motorcylist;
        VruSubProfileAnimal animal;
    } u;
} VruProfileAndSubprofile;

#define VruSpecificExteriorLights_MAX_BITS 8
enum { /* Bit position of BitString: VruSpecificExteriorLights */
       VruSpecificExteriorLights_unavailable = 0,
       VruSpecificExteriorLights_backFlashLight = 1,
       VruSpecificExteriorLights_helmetLight = 2,
       VruSpecificExteriorLights_armLight = 3,
       VruSpecificExteriorLights_legLight = 4,
       VruSpecificExteriorLights_wheelLight = 5,
};

typedef struct VruExteriorLights {
    BitString vruSpecific; /* VruSpecificExteriorLights (8..8) */
    BitString vehicular; /* ExteriorLights (9..9) */
} VruExteriorLights;

typedef enum VruSizeClass {
    VruSizeClass_unavailable,
    VruSizeClass_low,
    VruSizeClass_medium,
    VruSizeClass_high,
    VruSizeClass_max,
    VruSizeClass_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruSizeClass;

typedef struct VruLowFrequencyContainer {
    BOOL profileAndSubprofile_option;
    VruProfileAndSubprofile profileAndSubprofile;
    BOOL exteriorLights_option;
    VruExteriorLights exteriorLights;
    BOOL sizeClass_option;
    VruSizeClass sizeClass;
} VruLowFrequencyContainer;

typedef enum {
    NodeOffsetPointZ_node_Z1,
    NodeOffsetPointZ_node_Z2,
    NodeOffsetPointZ_node_Z3,
    NodeOffsetPointZ_node_Z4,
    NodeOffsetPointZ_node_Z5,
    NodeOffsetPointZ_node_Z6,
} NodeOffsetPointZ_choice;

typedef struct NodeOffsetPointZ {
    NodeOffsetPointZ_choice choice;
    union {
        int32_t node_Z1; /* Offset_B10 (-512..511) */
        int32_t node_Z2; /* Offset_B11 (-1024..1023) */
        int32_t node_Z3; /* Offset_B12 (-2048..2047) */
        int32_t node_Z4; /* Offset_B13 (-4096..4095) */
        int32_t node_Z5; /* Offset_B14 (-8192..8191) */
        int32_t node_Z6; /* Offset_B16 (-32768..32767) */
    } u;
} NodeOffsetPointZ;

typedef struct OffsetPoint {
    NodeOffsetPointXY nodeOffsetPointXY;
    BOOL nodeOffsetPointZ_option;
    NodeOffsetPointZ nodeOffsetPointZ;
} OffsetPoint;

enum { /* Pre-defined values of SemiRangeLength */
       SemiRangeLength_zeroPointOneMeter = 1,
       SemiRangeLength_oneMeter = 10,
};

enum { /* Pre-defined values of WGS84AngleValue */
       WGS84AngleValue_wgs84North = 0,
       WGS84AngleValue_wgs84East = 900,
       WGS84AngleValue_wgs84South = 1800,
       WGS84AngleValue_wgs84West = 2700,
       WGS84AngleValue_unavailable = 3601,
};

typedef struct AreaRectangle {
    BOOL nodeCenterPoint_option;
    OffsetPoint nodeCenterPoint;
    int32_t semiMajorRangeLength; /* SemiRangeLength (0..10000) */
    int32_t semiMinorRangeLength; /* SemiRangeLength (0..10000) */
    int32_t semiMajorRangeOrientation; /* WGS84AngleValue (0..3601) */
    BOOL semiHeight_option;
    int32_t semiHeight; /* SemiRangeLength (0..10000) */
} AreaRectangle;

enum { /* Pre-defined values of Radius */
       Radius_zeroPointOneMeter = 1,
       Radius_oneMeter = 10,
};

typedef struct AreaCircular {
    BOOL nodeCenterPoint_option;
    OffsetPoint nodeCenterPoint;
    int32_t radius; /* Radius (0..10000) */
} AreaCircular;

#define PolyPointList_MAX_SIZE 16
typedef struct PolyPointList {
    OffsetPoint *tab;
    int32_t count;
} PolyPointList;

typedef struct AreaPolygon {
    PolyPointList polyPointList;
} AreaPolygon;

typedef enum {
    ClusterBoundingBoxShape_clusterRectangle,
    ClusterBoundingBoxShape_clusterCircle,
    ClusterBoundingBoxShape_clusterPolygon,
} ClusterBoundingBoxShape_choice;

typedef struct ClusterBoundingBoxShape {
    ClusterBoundingBoxShape_choice choice;
    union {
        AreaRectangle clusterRectangle;
        AreaCircular clusterCircle;
        AreaPolygon clusterPolygon;
    } u;
} ClusterBoundingBoxShape;

enum { /* Pre-defined values of ClusterCardinalitySize */
       ClusterCardinalitySize_unavailable = 0,
       ClusterCardinalitySize_onlyLeader = 1,
};

#define ClusterProfiles_MAX_BITS 4
enum { /* Bit position of BitString: ClusterProfiles */
       ClusterProfiles_pedestrian = 0,
       ClusterProfiles_bicyclist = 1,
       ClusterProfiles_motorcyclist = 2,
       ClusterProfiles_animal = 3,
};

typedef struct VruClusterInformationContainer {
    int32_t clusterId; /* ClusterId (0..255) */
    ClusterBoundingBoxShape clusterBoundingBoxShape;
    int32_t clusterCardinalitySize; /* ClusterCardinalitySize (0..255) */
    BitString clusterProfiles; /* ClusterProfiles (4..4) */
} VruClusterInformationContainer;

typedef struct ClusterJoinInfo {
    int32_t clusterId; /* ClusterId (0..255) */
    int32_t joinTime; /* VruClusterOpTimestamp (1..255) */
} ClusterJoinInfo;

typedef enum ClusterLeaveReason {
    ClusterLeaveReason_notProvided,
    ClusterLeaveReason_clusterLeaderLost,
    ClusterLeaveReason_clusterDisbandedByLeader,
    ClusterLeaveReason_outOfClusterBoundingBox,
    ClusterLeaveReason_outOfClusterSpeedRange,
    ClusterLeaveReason_joiningAnotherCluster,
    ClusterLeaveReason_cancelledJoin,
    ClusterLeaveReason_failedJoin,
    ClusterLeaveReason_safetyCondition,
    ClusterLeaveReason_max,
    ClusterLeaveReason_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} ClusterLeaveReason;

typedef struct ClusterLeaveInfo {
    int32_t clusterId; /* ClusterId (0..255) */
    ClusterLeaveReason clusterLeaveReason;
} ClusterLeaveInfo;

typedef enum ClusterBreakupReason {
    ClusterBreakupReason_notProvided,
    ClusterBreakupReason_clusteringPurposeCompleted,
    ClusterBreakupReason_leaderMovedOutOfClusterBoundingBox,
    ClusterBreakupReason_joiningAnotherCluster,
    ClusterBreakupReason_enteringLowRiskAreaBasedOnMaps,
    ClusterBreakupReason_receptionOfCpmContainingCluster,
    ClusterBreakupReason_max,
    ClusterBreakupReason_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} ClusterBreakupReason;

typedef struct ClusterBreakupInfo {
    ClusterBreakupReason clusterBreakupReason;
    int32_t breakupTime; /* VruClusterOpTimestamp (1..255) */
} ClusterBreakupInfo;

typedef struct VruClusterOperationContainer {
    BOOL clusterJoinInfo_option;
    ClusterJoinInfo clusterJoinInfo;
    BOOL clusterLeaveInfo_option;
    ClusterLeaveInfo clusterLeaveInfo;
    BOOL clusterBreakupInfo_option;
    ClusterBreakupInfo clusterBreakupInfo;
    BOOL clusterIdChangeTimeInfo_option;
    int32_t clusterIdChangeTimeInfo; /* VruClusterOpTimestamp (1..255) */
} VruClusterOperationContainer;

typedef struct VruPathPoint {
    ReferencePosition pathPosition;
    BOOL pathDeltaTime_option;
    int32_t pathDeltaTime; /* PathDeltaTime (1..65535) */
} VruPathPoint;

#define SequenceOfVruPathPoint_MAX_SIZE 0
typedef struct SequenceOfVruPathPoint {
    VruPathPoint *tab;
    int32_t count;
} SequenceOfVruPathPoint;

enum { /* Pre-defined values of ActionDeltaTime */
       ActionDeltaTime_zero = 0,
       ActionDeltaTime_hundredMs = 1,
       ActionDeltaTime_twoHundredMs = 2,
       ActionDeltaTime_unavailable = 127,
};

typedef struct VruSafeDistanceIndication {
    BOOL subjectStation_option;
    uint32_t subjectStation; /* StationID (0..4294967295) */
    BOOL stationSafeDistanceIndication; /* StationSafeDistanceIndication */
    BOOL timeToCollision_option;
    int32_t timeToCollision; /* ActionDeltaTime (0..127) */
} VruSafeDistanceIndication;

#define SequenceOfVruSafeDistanceIndication_MAX_SIZE 8
typedef struct SequenceOfVruSafeDistanceIndication {
    VruSafeDistanceIndication *tab;
    int32_t count;
} SequenceOfVruSafeDistanceIndication;

enum { /* Pre-defined values of TrajectoryInterceptionProbability */
       TrajectoryInterceptionProbability_zero = 0,
       TrajectoryInterceptionProbability_twoPercent = 1,
       TrajectoryInterceptionProbability_fourPercent = 2,
       TrajectoryInterceptionProbability_oneHundredPercent = 50,
       TrajectoryInterceptionProbability_unavailable = 63,
};

enum { /* Pre-defined values of TrajectoryInterceptionConfidence */
       TrajectoryInterceptionConfidence_lessthan50percent = 0,
       TrajectoryInterceptionConfidence_between50and70Percent = 1,
       TrajectoryInterceptionConfidence_between70and90Percent = 2,
       TrajectoryInterceptionConfidence_above90Percent = 3,
};

typedef struct TrajectoryInterceptionIndication {
    BOOL subjectStation_option;
    uint32_t subjectStation; /* StationID (0..4294967295) */
    int32_t trajectoryInterceptionProbability; /* TrajectoryInterceptionProbability (0..63) */
    BOOL trajectoryInterceptionConfidence_option;
    int32_t trajectoryInterceptionConfidence; /* TrajectoryInterceptionConfidence (0..3) */
} TrajectoryInterceptionIndication;

#define SequenceOfTrajectoryInterceptionIndication_MAX_SIZE 8
typedef struct SequenceOfTrajectoryInterceptionIndication {
    TrajectoryInterceptionIndication *tab;
    int32_t count;
} SequenceOfTrajectoryInterceptionIndication;

typedef enum AccelOrDecel {
    AccelOrDecel_accelerate,
    AccelOrDecel_decelerate,
    AccelOrDecel_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} AccelOrDecel;

typedef struct AccelerationChangeIndication {
    AccelOrDecel accelOrDecel;
    int32_t actionDeltaTime; /* ActionDeltaTime (0..127) */
} AccelerationChangeIndication;

typedef enum LeftOrRight {
    LeftOrRight_left,
    LeftOrRight_right,
    LeftOrRight_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} LeftOrRight;

typedef struct HeadingChangeIndication {
    LeftOrRight direction;
    int32_t actionDeltaTime; /* ActionDeltaTime (0..127) */
} HeadingChangeIndication;

enum { /* Pre-defined values of StabilityLossProbability */
       StabilityLossProbability_zero = 0,
       StabilityLossProbability_twoPercent = 1,
       StabilityLossProbability_fourPercent = 2,
       StabilityLossProbability_unavailable = 63,
};

typedef struct StabilityChangeIndication {
    int32_t lossProbability; /* StabilityLossProbability (0..63) */
    int32_t actionDeltaTime; /* ActionDeltaTime (0..127) */
} StabilityChangeIndication;

typedef struct VruMotionPredictionContainer {
    BOOL pathHistory_option;
    PathHistory_ITS pathHistory;
    BOOL pathPrediction_option;
    SequenceOfVruPathPoint pathPrediction;
    BOOL safeDistance_option;
    SequenceOfVruSafeDistanceIndication safeDistance;
    BOOL trajectoryInterceptionIndication_option;
    SequenceOfTrajectoryInterceptionIndication trajectoryInterceptionIndication;
    BOOL accelerationChangeIndication_option;
    AccelerationChangeIndication accelerationChangeIndication;
    BOOL headingChangeIndication_option;
    HeadingChangeIndication headingChangeIndication;
    BOOL stabilityChangeIndication_option;
    StabilityChangeIndication stabilityChangeIndication;
} VruMotionPredictionContainer;

typedef struct VamParameters {
    BasicContainer basicContainer;
    BOOL vruHighFrequencyContainer_option;
    VruHighFrequencyContainer vruHighFrequencyContainer;
    BOOL vruLowFrequencyContainer_option;
    VruLowFrequencyContainer vruLowFrequencyContainer;
    BOOL vruClusterInformationContainer_option;
    VruClusterInformationContainer vruClusterInformationContainer;
    BOOL vruClusterOperationContainer_option;
    VruClusterOperationContainer vruClusterOperationContainer;
    BOOL vruMotionPredictionContainer_option;
    VruMotionPredictionContainer vruMotionPredictionContainer;
} VamParameters;

typedef struct VruAwareness {
    int32_t generationDeltaTime; /* GenerationDeltaTime (0..65535) */
    VamParameters vamParameters;
} VruAwareness;

typedef struct VAM {
    ItsPduHeader header;
    VruAwareness vam;
} VAM;

typedef enum VruProfile {
    VruProfile_unavailable,
    VruProfile_pedestrian,
    VruProfile_cyclist,
    VruProfile_motorcyclist,
    VruProfile_animal,
    VruProfile_max,
    VruProfile_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} VruProfile;


#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_VAM_H__ */
