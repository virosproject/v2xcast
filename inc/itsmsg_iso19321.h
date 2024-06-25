/* ISO19321 data frame and element defintions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_ISO19321_H__
#define __ITSMSG_ISO19321_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>
#include "asn1defs_if.h"
#include "itsmsg_cdd.h"
#include "itsmsg_iso17419.h"
#include "itsmsg_common.h"


typedef struct AxleWeightLimits {
    int32_t maxLadenweightOnAxle1; /* Int2 (0..65535) */
    int32_t maxLadenweightOnAxle2; /* Int2 (0..65535) */
    int32_t maxLadenweightOnAxle3; /* Int2 (0..65535) */
    int32_t maxLadenweightOnAxle4; /* Int2 (0..65535) */
    int32_t maxLadenweightOnAxle5; /* Int2 (0..65535) */
} AxleWeightLimits;

typedef enum UnitType {
    UnitType_mg_km,
    UnitType_mg_kWh,
    UnitType_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} UnitType;

typedef struct DieselEmissionValues_Particulate {
    UnitType unitType;
    int32_t value; /* (0..32767) */
} DieselEmissionValues_Particulate;

typedef struct DieselEmissionValues {
    DieselEmissionValues_Particulate particulate;
    int32_t absorptionCoeff; /* Int2 (0..65535) */
} DieselEmissionValues;

typedef struct ExhaustEmissionValues {
    UnitType unitType;
    int32_t emissionCO; /* (0..32767) */
    int32_t emissionHC; /* Int2 (0..65535) */
    int32_t emissionNOX; /* Int2 (0..65535) */
    int32_t emissionHCNOX; /* Int2 (0..65535) */
} ExhaustEmissionValues;

enum { /* Pre-defined values of EngineCharacteristics */
       EngineCharacteristics_noEntry = 0,
       EngineCharacteristics_noEngine = 1,
       EngineCharacteristics_petrolUnleaded = 2,
       EngineCharacteristics_petrolLeaded = 3,
       EngineCharacteristics_diesel = 4,
       EngineCharacteristics_lPG = 5,
       EngineCharacteristics_battery = 6,
       EngineCharacteristics_solar = 7,
};

typedef enum EuroValue {
    EuroValue_noEntry,
    EuroValue_euro_1,
    EuroValue_euro_2,
    EuroValue_euro_3,
    EuroValue_euro_4,
    EuroValue_euro_5,
    EuroValue_euro_6,
    EuroValue_reservedForUse1,
    EuroValue_reservedForUse2,
    EuroValue_reservedForUse3,
    EuroValue_reservedForUse4,
    EuroValue_reservedForUse5,
    EuroValue_reservedForUse6,
    EuroValue_reservedForUse7,
    EuroValue_reservedForUse8,
    EuroValue_reservedForUse9,
    EuroValue_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} EuroValue;

typedef enum CopValue {
    CopValue_noEntry,
    CopValue_co2class1,
    CopValue_co2class2,
    CopValue_co2class3,
    CopValue_co2class4,
    CopValue_co2class5,
    CopValue_co2class6,
    CopValue_co2class7,
    CopValue_reservedforUse,
    CopValue_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} CopValue;

typedef struct EnvironmentalCharacteristics {
    EuroValue euroValue;
    CopValue copValue;
} EnvironmentalCharacteristics;

typedef struct PassengerCapacity {
    int32_t numberOfSeats; /* Int1 (0..255) */
    int32_t numberOfStandingPlaces; /* Int1 (0..255) */
} PassengerCapacity;

#define CountryCode_MAX_BITS 10

typedef struct Provider {
    BitString countryCode; /* CountryCode (10..10) */
    int32_t providerIdentifier; /* IssuerIdentifier (0..16383) */
} Provider;

typedef struct SoundLevel {
    int32_t soundstationary; /* Int1 (0..255) */
    int32_t sounddriveby; /* Int1 (0..255) */
} SoundLevel;

typedef struct VehicleDimensions {
    int32_t vehicleLengthOverall; /* Int1 (0..255) */
    int32_t vehicleHeigthOverall; /* Int1 (0..255) */
    int32_t vehicleWidthOverall; /* Int1 (0..255) */
} VehicleDimensions;

typedef struct VehicleWeightLimits {
    int32_t vehicleMaxLadenWeight; /* Int2 (0..65535) */
    int32_t vehicleTrainMaximumWeight; /* Int2 (0..65535) */
    int32_t vehicleWeightUnladen; /* Int2 (0..65535) */
} VehicleWeightLimits;

typedef enum EuVehicleCategoryL {
    EuVehicleCategoryL_l1,
    EuVehicleCategoryL_l2,
    EuVehicleCategoryL_l3,
    EuVehicleCategoryL_l4,
    EuVehicleCategoryL_l5,
    EuVehicleCategoryL_l6,
    EuVehicleCategoryL_l7,
    EuVehicleCategoryL_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} EuVehicleCategoryL;

typedef enum EuVehicleCategoryM {
    EuVehicleCategoryM_m1,
    EuVehicleCategoryM_m2,
    EuVehicleCategoryM_m3,
    EuVehicleCategoryM_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} EuVehicleCategoryM;

typedef enum EuVehicleCategoryN {
    EuVehicleCategoryN_n1,
    EuVehicleCategoryN_n2,
    EuVehicleCategoryN_n3,
    EuVehicleCategoryN_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} EuVehicleCategoryN;

typedef enum EuVehicleCategoryO {
    EuVehicleCategoryO_o1,
    EuVehicleCategoryO_o2,
    EuVehicleCategoryO_o3,
    EuVehicleCategoryO_o4,
    EuVehicleCategoryO_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} EuVehicleCategoryO;

typedef enum {
    EuVehicleCategoryCode_euVehicleCategoryL,
    EuVehicleCategoryCode_euVehicleCategoryM,
    EuVehicleCategoryCode_euVehicleCategoryN,
    EuVehicleCategoryCode_euVehicleCategoryO,
    EuVehicleCategoryCode_euVehilcleCategoryT,
    EuVehicleCategoryCode_euVehilcleCategoryG,
} EuVehicleCategoryCode_choice;

typedef struct EuVehicleCategoryCode {
    EuVehicleCategoryCode_choice choice;
    union {
        EuVehicleCategoryL euVehicleCategoryL;
        EuVehicleCategoryM euVehicleCategoryM;
        EuVehicleCategoryN euVehicleCategoryN;
        EuVehicleCategoryO euVehicleCategoryO;
    } u;
} EuVehicleCategoryCode;

enum { /* Pre-defined values of Iso3833VehicleType */
       Iso3833VehicleType_passengerCar = 0,
       Iso3833VehicleType_saloon = 1,
       Iso3833VehicleType_convertibleSaloon = 2,
       Iso3833VehicleType_pullmanSaloon = 3,
       Iso3833VehicleType_stationWagon = 4,
       Iso3833VehicleType_truckStationWagon = 5,
       Iso3833VehicleType_coupe = 6,
       Iso3833VehicleType_convertible = 7,
       Iso3833VehicleType_multipurposePassengerCar = 8,
       Iso3833VehicleType_forwardControlPassengerCar = 9,
       Iso3833VehicleType_specialPassengerCar = 10,
       Iso3833VehicleType_bus = 11,
       Iso3833VehicleType_minibus = 12,
       Iso3833VehicleType_urbanBus = 13,
       Iso3833VehicleType_interurbanCoach = 14,
       Iso3833VehicleType_longDistanceCoach = 15,
       Iso3833VehicleType_articulatedBus = 16,
       Iso3833VehicleType_trolleyBus = 17,
       Iso3833VehicleType_specialBus = 18,
       Iso3833VehicleType_commercialVehicle = 19,
       Iso3833VehicleType_specialCommercialVehicle = 20,
       Iso3833VehicleType_specialVehicle = 21,
       Iso3833VehicleType_trailingTowingVehicle = 22,
       Iso3833VehicleType_semiTrailerTowingVehicle = 23,
       Iso3833VehicleType_trailer = 24,
       Iso3833VehicleType_busTrailer = 25,
       Iso3833VehicleType_generalPurposeTrailer = 26,
       Iso3833VehicleType_caravan = 27,
       Iso3833VehicleType_specialTrailer = 28,
       Iso3833VehicleType_semiTrailer = 29,
       Iso3833VehicleType_busSemiTrailer = 30,
       Iso3833VehicleType_generalPurposeSemiTrailer = 31,
       Iso3833VehicleType_specialSemiTrailer = 32,
       Iso3833VehicleType_roadTrain = 33,
       Iso3833VehicleType_passengerRoadTrain = 34,
       Iso3833VehicleType_articulatedRoadTrain = 35,
       Iso3833VehicleType_doubleRoadTrain = 36,
       Iso3833VehicleType_compositeRoadTrain = 37,
       Iso3833VehicleType_specialRoadTrain = 38,
       Iso3833VehicleType_moped = 39,
       Iso3833VehicleType_motorCycle = 40,
};

#define IviIdentificationNumberList_MAX_SIZE 8
typedef struct IviIdentificationNumberList {
    int32_t *tab; /* IviIdentificationNumber (1..32767) */
    int32_t count;
} IviIdentificationNumberList;

enum { /* Pre-defined values of IviStatus */
       IviStatus_New = 0,
       IviStatus_update = 1,
       IviStatus_cancellation = 2,
       IviStatus_negation = 3,
};

typedef struct ManagementContainer_ISO {
    Provider serviceProviderId;
    int32_t iviIdentificationNumber; /* IviIdentificationNumber (1..32767) */
    BOOL timeStamp_option;
    BigInteger timeStamp; /* TimestampIts */
    BOOL validFrom_option;
    BigInteger validFrom; /* TimestampIts */
    BOOL validTo_option;
    BigInteger validTo; /* TimestampIts */
    BOOL connectedIviStructures_option;
    IviIdentificationNumberList connectedIviStructures;
    int32_t iviStatus; /* IviStatus (0..7) */
} ManagementContainer_ISO;

typedef struct DeltaPosition {
    int32_t deltaLatitude; /* DeltaLatitude (-131071..131072) */
    int32_t deltaLongitude; /* DeltaLongitude (-131071..131072) */
} DeltaPosition;

#define DeltaPositionList_MAX_SIZE 32
typedef struct DeltaPositionList {
    DeltaPosition *tab;
    int32_t count;
} DeltaPositionList;

#define DeltaReferencePositionList_MAX_SIZE 32
typedef struct DeltaReferencePositionList {
    DeltaReferencePosition *tab;
    int32_t count;
} DeltaReferencePositionList;

typedef struct AbsolutePosition {
    int32_t latitude; /* Latitude (-900000000..900000001) */
    int32_t longitude; /* Longitude (-1800000000..1800000001) */
} AbsolutePosition;

#define AbsolutePositionList_MAX_SIZE 8
typedef struct AbsolutePositionList {
    AbsolutePosition *tab;
    int32_t count;
} AbsolutePositionList;

typedef struct AbsolutePositionWAltitude {
    int32_t latitude; /* Latitude (-900000000..900000001) */
    int32_t longitude; /* Longitude (-1800000000..1800000001) */
    Altitude altitude;
} AbsolutePositionWAltitude;

#define AbsolutePositionWAltitudeList_MAX_SIZE 8
typedef struct AbsolutePositionWAltitudeList {
    AbsolutePositionWAltitude *tab;
    int32_t count;
} AbsolutePositionWAltitudeList;

typedef enum {
    PolygonalLine_deltaPositions,
    PolygonalLine_deltaPositionsWithAltitude,
    PolygonalLine_absolutePositions,
    PolygonalLine_absolutePositionsWithAltitude,
} PolygonalLine_choice;

typedef struct PolygonalLine {
    PolygonalLine_choice choice;
    union {
        DeltaPositionList deltaPositions;
        DeltaReferencePositionList deltaPositionsWithAltitude;
        AbsolutePositionList absolutePositions;
        AbsolutePositionWAltitudeList absolutePositionsWithAltitude;
    } u;
} PolygonalLine;

typedef struct Segment {
    PolygonalLine line;
    BOOL laneWidth_option;
    int32_t laneWidth; /* LaneWidth (0..1023) */
} Segment;

typedef struct ComputedSegment {
    int32_t zoneId; /* Zid (1..32) */
    int32_t laneNumber; /* LanePosition (-1..14) */
    int32_t laneWidth; /* LaneWidth (0..1023) */
    BOOL offsetDistance_option;
    int32_t offsetDistance; /* (-32768..32767) */
    BOOL offsetPosition_option;
    DeltaReferencePosition offsetPosition;
} ComputedSegment;

typedef enum {
    Zone_segment,
    Zone_area,
    Zone_computedSegment,
} Zone_choice;

typedef struct Zone {
    Zone_choice choice;
    union {
        Segment segment;
        PolygonalLine area;
        ComputedSegment computedSegment;
    } u;
} Zone;

typedef struct GlcPart {
    int32_t zoneId; /* Zid (1..32) */
    BOOL laneNumber_option;
    int32_t laneNumber; /* LanePosition (-1..14) */
    BOOL zoneExtension_option;
    int32_t zoneExtension; /* (0..255) */
    BOOL zoneHeading_option;
    int32_t zoneHeading; /* HeadingValue (0..3601) */
    BOOL zone_option;
    Zone zone;
} GlcPart;

#define GlcPartList_MAX_SIZE 16
typedef struct GlcPartList {
    GlcPart *tab;
    int32_t count;
} GlcPartList;

typedef struct GeographicLocationContainer {
    ReferencePosition referencePosition;
    BOOL referencePositionTime_option;
    BigInteger referencePositionTime; /* TimestampIts */
    BOOL referencePositionHeading_option;
    Heading referencePositionHeading;
    BOOL referencePositionSpeed_option;
    Speed referencePositionSpeed;
    GlcPartList parts;
} GeographicLocationContainer;

#define ZidList_MAX_SIZE 8
typedef struct ZidList {
    int32_t *tab; /* Zid (1..32) */
    int32_t count;
} ZidList;

enum { /* Pre-defined values of Direction */
       Direction_sameDirection = 0,
       Direction_oppositeDirection = 1,
       Direction_bothDirections = 2,
       Direction_valueNotUsed = 3,
};

#define LanePositionList_MAX_SIZE 8
typedef struct LanePositionList {
    int32_t *tab; /* LanePosition (-1..14) */
    int32_t count;
} LanePositionList;

enum { /* Pre-defined values of IviType */
       IviType_immediateDangerWarningMessages = 0,
       IviType_regulatoryMessages = 1,
       IviType_trafficRelatedInformationMessages = 2,
       IviType_pollutionMessages = 3,
       IviType_notTrafficRelatedInformationMessages = 4,
};

enum { /* Pre-defined values of IviPurpose */
       IviPurpose_safety = 0,
       IviPurpose_environmental = 1,
       IviPurpose_trafficOptimisation = 2,
};

enum { /* Pre-defined values of LaneStatus */
       LaneStatus_open = 0,
       LaneStatus_closed = 1,
       LaneStatus_mergeR = 2,
       LaneStatus_mergeL = 3,
       LaneStatus_mergeLR = 4,
       LaneStatus_provisionallyOpen = 5,
       LaneStatus_diverging = 6,
};

enum { /* Pre-defined values of GoodsType */
       GoodsType_ammunition = 0,
       GoodsType_chemicals = 1,
       GoodsType_empty = 2,
       GoodsType_fuel = 3,
       GoodsType_glass = 4,
       GoodsType_dangerous = 5,
       GoodsType_liquid = 6,
       GoodsType_liveStock = 7,
       GoodsType_dangerousForPeople = 8,
       GoodsType_dangerousForTheEnvironment = 9,
       GoodsType_dangerousForWater = 10,
       GoodsType_perishableProducts = 11,
       GoodsType_pharmaceutical = 12,
       GoodsType_vehicles = 13,
};

typedef struct LoadType {
    int32_t goodsType; /* GoodsType (0..15) */
    DangerousGoodsBasic dangerousGoodsType;
    BitString specialTransportType; /* SpecialTransportType (4..4) */
} LoadType;

typedef enum {
    VehicleCharacteristicsFixValues_simpleVehicleType,
    VehicleCharacteristicsFixValues_euVehicleCategoryCode,
    VehicleCharacteristicsFixValues_iso3833VehicleType,
    VehicleCharacteristicsFixValues_euroAndCo2value,
    VehicleCharacteristicsFixValues_engineCharacteristics,
    VehicleCharacteristicsFixValues_loadType,
    VehicleCharacteristicsFixValues_usage,
} VehicleCharacteristicsFixValues_choice;

typedef struct VehicleCharacteristicsFixValues {
    VehicleCharacteristicsFixValues_choice choice;
    union {
        int32_t simpleVehicleType; /* StationType (0..255) */
        EuVehicleCategoryCode euVehicleCategoryCode;
        int32_t iso3833VehicleType; /* Iso3833VehicleType (0..255) */
        EnvironmentalCharacteristics euroAndCo2value;
        int32_t engineCharacteristics; /* EngineCharacteristics (0..255) */
        LoadType loadType;
        VehicleRole usage;
    } u;
} VehicleCharacteristicsFixValues;

enum { /* Pre-defined values of ComparisonOperator */
       ComparisonOperator_greaterThan = 0,
       ComparisonOperator_greaterThanOrEqualTo = 1,
       ComparisonOperator_lessThan = 2,
       ComparisonOperator_lessThanOrEqualTo = 3,
};

typedef enum {
    VehicleCharacteristicsRanges_Limits_numberOfAxles,
    VehicleCharacteristicsRanges_Limits_vehicleDimensions,
    VehicleCharacteristicsRanges_Limits_vehicleWeightLimits,
    VehicleCharacteristicsRanges_Limits_axleWeightLimits,
    VehicleCharacteristicsRanges_Limits_passengerCapacity,
    VehicleCharacteristicsRanges_Limits_exhaustEmissionValues,
    VehicleCharacteristicsRanges_Limits_dieselEmissionValues,
    VehicleCharacteristicsRanges_Limits_soundLevel,
} VehicleCharacteristicsRanges_Limits_choice;

typedef struct VehicleCharacteristicsRanges_Limits {
    VehicleCharacteristicsRanges_Limits_choice choice;
    union {
        int32_t numberOfAxles; /* (0..7) */
        VehicleDimensions vehicleDimensions;
        VehicleWeightLimits vehicleWeightLimits;
        AxleWeightLimits axleWeightLimits;
        PassengerCapacity passengerCapacity;
        ExhaustEmissionValues exhaustEmissionValues;
        DieselEmissionValues dieselEmissionValues;
        SoundLevel soundLevel;
    } u;
} VehicleCharacteristicsRanges_Limits;

typedef struct VehicleCharacteristicsRanges {
    int32_t comparisonOperator; /* ComparisonOperator (0..3) */
    VehicleCharacteristicsRanges_Limits limits;
} VehicleCharacteristicsRanges;

#define VehicleCharacteristicsRangesList_MAX_SIZE 4
typedef struct VehicleCharacteristicsRangesList {
    VehicleCharacteristicsRanges *tab;
    int32_t count;
} VehicleCharacteristicsRangesList;

#define VehicleCharacteristicsFixValuesList_MAX_SIZE 4
typedef struct VehicleCharacteristicsFixValuesList {
    VehicleCharacteristicsFixValues *tab;
    int32_t count;
} VehicleCharacteristicsFixValuesList;

typedef struct TractorCharacteristics {
    BOOL equalTo_option;
    VehicleCharacteristicsFixValuesList equalTo;
    BOOL notEqualTo_option;
    VehicleCharacteristicsFixValuesList notEqualTo;
    BOOL ranges_option;
    VehicleCharacteristicsRangesList ranges;
} TractorCharacteristics;

typedef struct TrailerCharacteristics {
    BOOL equalTo_option;
    VehicleCharacteristicsFixValuesList equalTo;
    BOOL notEqualTo_option;
    VehicleCharacteristicsFixValuesList notEqualTo;
    BOOL ranges_option;
    VehicleCharacteristicsRangesList ranges;
} TrailerCharacteristics;

#define TrailerCharacteristicsList_MAX_SIZE 3
typedef struct TrailerCharacteristicsList {
    TrailerCharacteristics *tab;
    int32_t count;
} TrailerCharacteristicsList;

typedef TractorCharacteristics TrainCharacteristics;

typedef struct CompleteVehicleCharacteristics {
    BOOL tractor_option;
    TractorCharacteristics tractor;
    BOOL trailer_option;
    TrailerCharacteristicsList trailer;
    BOOL train_option;
    TrainCharacteristics train;
} CompleteVehicleCharacteristics;

#define CompleteVehicleCharacteristicsList_MAX_SIZE 8
typedef struct CompleteVehicleCharacteristicsList {
    CompleteVehicleCharacteristics *tab;
    int32_t count;
} CompleteVehicleCharacteristicsList;

enum { /* Pre-defined values of DriverCharacteristics */
       DriverCharacteristics_unexperiencedDrivers = 0,
       DriverCharacteristics_experiencedDrivers = 1,
       DriverCharacteristics_rfu1 = 2,
       DriverCharacteristics_rfu2 = 3,
};

enum { /* Pre-defined values of VcClass */
       VcClass_classA = 0,
       VcClass_classB = 1,
       VcClass_classC = 2,
       VcClass_classD = 3,
       VcClass_classE = 4,
       VcClass_classF = 5,
       VcClass_classG = 6,
       VcClass_classH = 7,
};

enum { /* Pre-defined values of VcOption */
       VcOption_none = 0,
       VcOption_a = 1,
       VcOption_b = 2,
       VcOption_c = 3,
       VcOption_d = 4,
       VcOption_e = 5,
       VcOption_f = 6,
       VcOption_g = 7,
};

typedef struct DTM_Year {
    int32_t syr; /* (2000..2127,...) */
    int32_t eyr; /* (2000..2127,...) */
} DTM_Year;

typedef struct MonthDay {
    int32_t month; /* (1..12) */
    int32_t day; /* (1..31) */
} MonthDay;

typedef struct DTM_MonthDay {
    MonthDay smd;
    MonthDay emd;
} DTM_MonthDay;

#define PMD_MAX_BITS 4
enum { /* Bit position of BitString: PMD */
       PMD_national_holiday = 0,
       PMD_even_days = 1,
       PMD_odd_days = 2,
       PMD_market_day = 3,
};

typedef struct HoursMinutes {
    int32_t hours; /* (0..23) */
    int32_t mins; /* (0..59) */
} HoursMinutes;

typedef struct DTM_HourMinutes {
    HoursMinutes shm;
    HoursMinutes ehm;
} DTM_HourMinutes;

#define DayOfWeek_MAX_BITS 8

typedef struct DTM {
    BOOL year_option;
    DTM_Year year;
    BOOL month_day_option;
    DTM_MonthDay month_day;
    BOOL pmd_option;
    BitString pmd; /* PMD (4..4) */
    BOOL hourMinutes_option;
    DTM_HourMinutes hourMinutes;
    BOOL dayOfWeek_option;
    BitString dayOfWeek; /* DayOfWeek (8..8) */
    BOOL period_option;
    HoursMinutes period;
} DTM;

#define DTMList_MAX_SIZE 8
typedef struct DTMList {
    DTM *tab;
    int32_t count;
} DTMList;

enum { /* Pre-defined values of RSCUnit */
       RSCUnit_kmperh = 0,
       RSCUnit_milesperh = 1,
       RSCUnit_kilometer = 2,
       RSCUnit_meter = 3,
       RSCUnit_decimeter = 4,
       RSCUnit_centimeter = 5,
       RSCUnit_mile = 6,
       RSCUnit_yard = 7,
       RSCUnit_foot = 8,
       RSCUnit_minutesOfTime = 9,
       RSCUnit_tonnes = 10,
       RSCUnit_hundredkg = 11,
       RSCUnit_pound = 12,
       RSCUnit_rateOfIncline = 13,
};

typedef struct VcCode {
    int32_t roadSignClass; /* VcClass (0..7) */
    int32_t roadSignCode; /* (1..64) */
    int32_t vcOption; /* VcOption (0..7) */
    BOOL validity_option;
    DTMList validity;
    BOOL value_option;
    int32_t value; /* (0..65535) */
    BOOL unit_option;
    int32_t unit; /* RSCUnit (0..15) */
} VcCode;

typedef enum ISO14823Code_TrafficSignPictogram {
    ISO14823Code_TrafficSignPictogram_dangerWarning,
    ISO14823Code_TrafficSignPictogram_regulatory,
    ISO14823Code_TrafficSignPictogram_informative,
    ISO14823Code_TrafficSignPictogram_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} ISO14823Code_TrafficSignPictogram;

typedef enum ISO14823Code_PublicFacilitiesPictogram {
    ISO14823Code_PublicFacilitiesPictogram_publicFacilities,
    ISO14823Code_PublicFacilitiesPictogram_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} ISO14823Code_PublicFacilitiesPictogram;

typedef enum ISO14823Code_AmbientOrRoadConditionPictogram {
    ISO14823Code_AmbientOrRoadConditionPictogram_ambientCondition,
    ISO14823Code_AmbientOrRoadConditionPictogram_roadCondition,
    ISO14823Code_AmbientOrRoadConditionPictogram_MAX = UINT_MAX /* keep size of enum be always 4bytes */
} ISO14823Code_AmbientOrRoadConditionPictogram;

typedef enum {
    ISO14823Code_ServiceCategoryCode_TrafficSignPictogram,
    ISO14823Code_ServiceCategoryCode_PublicFacilitiesPictogram,
    ISO14823Code_ServiceCategoryCode_ambientOrRoadConditionPictogram,
} ISO14823Code_ServiceCategoryCode_choice;

typedef struct ISO14823Code_ServiceCategoryCode {
    ISO14823Code_ServiceCategoryCode_choice choice;
    union {
        ISO14823Code_TrafficSignPictogram trafficSignPictogram;
        ISO14823Code_PublicFacilitiesPictogram publicFacilitiesPictogram;
        ISO14823Code_AmbientOrRoadConditionPictogram ambientOrRoadConditionPictogram;
    } u;
} ISO14823Code_ServiceCategoryCode;

typedef struct ISO14823Code_PictogramCategoryCode {
    int32_t nature; /* (1..9) */
    int32_t serialNumber; /* (0..99) */
} ISO14823Code_PictogramCategoryCode;

typedef struct ISO14823Code_PictogramCode {
    BOOL countryCode_option;
    OctetString countryCode;
    ISO14823Code_ServiceCategoryCode serviceCategoryCode;
    ISO14823Code_PictogramCategoryCode pictogramCategoryCode;
} ISO14823Code_PictogramCode;

enum { /* Pre-defined values of DFL */
       DFL_sDL = 1,
       DFL_sLT = 2,
       DFL_sRT = 3,
       DFL_lTO = 4,
       DFL_rTO = 5,
       DFL_cLL = 6,
       DFL_cRI = 7,
       DFL_oVL = 8,
};

typedef struct Distance {
    int32_t value; /* (1..16384) */
    int32_t unit; /* RSCUnit (2..4|6..8)*/
} Distance;

typedef struct Weight {
    int32_t value; /* (1..16384) */
    int32_t unit; /* RSCUnit (10..12) */
} Weight;

typedef struct VED {
    BOOL hei_option;
    Distance hei;
    BOOL wid_option;
    Distance wid;
    BOOL vln_option;
    Distance vln;
    BOOL wei_option;
    Weight wei;
} VED;

typedef struct SPE {
    BOOL spm_option;
    int32_t spm; /* (0..250) */
    BOOL mns_option;
    int32_t mns; /* (0..250) */
    int32_t unit; /* RSCUnit (0..1) */
} SPE;

enum { /* Pre-defined values of DDD_DEP */
       DDD_DEP_none = 0,
       DDD_DEP_importantArea = 1,
       DDD_DEP_principalArea = 2,
       DDD_DEP_generalArea = 3,
       DDD_DEP_wellKnownPoint = 4,
       DDD_DEP_country = 5,
       DDD_DEP_city = 6,
       DDD_DEP_street = 7,
       DDD_DEP_industrialArea = 8,
       DDD_DEP_historicArea = 9,
       DDD_DEP_touristicArea = 10,
       DDD_DEP_culturalArea = 11,
       DDD_DEP_touristicRoute = 12,
       DDD_DEP_recommendedRoute = 13,
       DDD_DEP_touristicAttraction = 14,
       DDD_DEP_geographicArea = 15,
};

typedef struct DestinationPlace {
    int32_t depType; /* DDD_DEP (0..15) */
    BOOL depRSCode_option;
    struct ISO14823Code *depRSCode;
    BOOL depBlob_option;
    OctetString depBlob;
    BOOL plnId_option;
    int32_t plnId; /* (1..999) */
    BOOL plnText_option;
    OctetString plnText;
} DestinationPlace;

#define DestinationPlaceList_MAX_SIZE 4
typedef struct DestinationPlaceList {
    DestinationPlace *tab;
    int32_t count;
} DestinationPlaceList;

enum { /* Pre-defined values of DDD_DER */
       DDD_DER_none = 0,
       DDD_DER_nationalHighway = 1,
       DDD_DER_localHighway = 2,
       DDD_DER_tollExpresswayMotorway = 3,
       DDD_DER_internationalHighway = 4,
       DDD_DER_highway = 5,
       DDD_DER_expressway = 6,
       DDD_DER_nationalRoad = 7,
       DDD_DER_regionalProvincialRoad = 8,
       DDD_DER_localRoad = 9,
       DDD_DER_motorwayJunction = 10,
       DDD_DER_diversion = 11,
       DDD_DER_rfu1 = 12,
       DDD_DER_rfu2 = 13,
       DDD_DER_rfu3 = 14,
       DDD_DER_rfu4 = 15,
};

typedef struct DestinationRoad {
    int32_t derType; /* DDD_DER (0..15) */
    BOOL ronId_option;
    int32_t ronId; /* (1..999) */
    BOOL ronText_option;
    OctetString ronText;
} DestinationRoad;

#define DestinationRoadList_MAX_SIZE 4
typedef struct DestinationRoadList {
    DestinationRoad *tab;
    int32_t count;
} DestinationRoadList;

typedef struct DistanceOrDuration {
    int32_t value;
    int32_t unit; /* RSCUnit (2..9) */
} DistanceOrDuration;

typedef struct DDD_IO {
    int32_t drn; /* (0..7) */
    BOOL dp_option;
    DestinationPlaceList dp;
    BOOL dr_option;
    DestinationRoadList dr;
    BOOL rne_option;
    int32_t rne; /* (1..999) */
    BOOL stnId_option;
    int32_t stnId; /* (1..999) */
    BOOL stnText_option;
    OctetString stnText;
    BOOL dcp_option;
    DistanceOrDuration dcp;
    BOOL ddp_option;
    DistanceOrDuration ddp;
} DDD_IO;

#define DDD_IOList_MAX_SIZE 8
typedef struct DDD_IOList {
    DDD_IO *tab;
    int32_t count;
} DDD_IOList;

typedef struct DDD {
    BOOL dcj_option;
    int32_t dcj; /* (1..128) */
    BOOL dcr_option;
    int32_t dcr; /* (1..128) */
    BOOL tpl_option;
    int32_t tpl; /* (1..128) */
    DDD_IOList ioList;
} DDD;

typedef enum {
    ISO14823Attributes_Data_dtm,
    ISO14823Attributes_Data_edt,
    ISO14823Attributes_Data_dfl,
    ISO14823Attributes_Data_ved,
    ISO14823Attributes_Data_spe,
    ISO14823Attributes_Data_roi,
    ISO14823Attributes_Data_dbv,
    ISO14823Attributes_Data_ddd,
} ISO14823Attributes_Data_choice;

typedef DTM EDT;

typedef Distance DBV;

typedef struct ISO14823Attributes_Data {
    ISO14823Attributes_Data_choice choice;
    union {
        DTM dtm;
        EDT edt;
        int32_t dfl; /* DFL (1..8) */
        VED ved;
        SPE spe;
        int32_t roi; /* ROI (1..32) */
        DBV dbv;
        DDD ddd;
    } u;
} ISO14823Attributes_Data;

#define ISO14823Attributes_MAX_SIZE 8
typedef struct ISO14823Attributes {
    ISO14823Attributes_Data *tab;
    int32_t count;
} ISO14823Attributes;

typedef struct ISO14823Code {
    ISO14823Code_PictogramCode pictogramCode;
    BOOL attributes_option;
    ISO14823Attributes attributes;
} ISO14823Code;

typedef struct AnyCatalogue {
    Provider owner;
    int32_t version; /* (0..255) */
    int32_t pictogramCode; /* (0..65535) */
    BOOL value_option;
    int32_t value; /* (0..65535) */
    BOOL unit_option;
    int32_t unit; /* RSCUnit (0..15) */
    BOOL attributes_option;
    ISO14823Attributes attributes;
} AnyCatalogue;

typedef enum {
    RSCode_Code_viennaConvention,
    RSCode_Code_iso14823,
    RSCode_Code_itisCodes,
    RSCode_Code_anyCatalogue,
} RSCode_Code_choice;

typedef struct RSCode_Code {
    RSCode_Code_choice choice;
    union {
        VcCode viennaConvention;
        ISO14823Code iso14823;
        int32_t itisCodes; /* (0..65535) */
        AnyCatalogue anyCatalogue;
    } u;
} RSCode_Code;

typedef struct RSCode {
    BOOL layoutComponentId_option;
    int32_t layoutComponentId; /* (1..4,...) */
    RSCode_Code code;
} RSCode;

#define RSCodeList_MAX_SIZE 4
typedef struct RSCodeList {
    RSCode *tab;
    int32_t count;
} RSCodeList;

typedef struct Text {
    BOOL layoutComponentId_option;
    int32_t layoutComponentId; /* (1..4,...) */
    BitString language; /* (10..10) */
    OctetString textContent;
} Text;

#define TextList_MAX_SIZE 4
typedef struct TextList {
    Text *tab;
    int32_t count;
} TextList;

typedef struct GicPart {
    BOOL detectionZoneIds_option;
    ZidList detectionZoneIds;
    BOOL its_Rrid_option;
    VarLengthNumber its_Rrid;
    BOOL relevanceZoneIds_option;
    ZidList relevanceZoneIds;
    BOOL direction_option;
    int32_t direction; /* Direction (0..3) */
    BOOL driverAwarenessZoneIds_option;
    ZidList driverAwarenessZoneIds;
    BOOL minimumAwarenessTime_option;
    int32_t minimumAwarenessTime; /* (0..255) */
    BOOL applicableLanes_option;
    LanePositionList applicableLanes;
    int32_t iviType; /* IviType (0..7) */
    BOOL iviPurpose_option;
    int32_t iviPurpose; /* IviPurpose (0..3) */
    BOOL laneStatus_option;
    int32_t laneStatus; /* LaneStatus (0..7) */
    BOOL vehicleCharacteristics_option;
    CompleteVehicleCharacteristicsList vehicleCharacteristics;
    BOOL driverCharacteristics_option;
    int32_t driverCharacteristics; /* DriverCharacteristics (0..3) */
    BOOL layoutId_option;
    int32_t layoutId; /* (1..4,...) */
    BOOL preStoredlayoutId_option;
    int32_t preStoredlayoutId; /* (1..64,...) */
    RSCodeList roadSignCodes;
    BOOL extraText_option;
    TextList extraText;
} GicPart;

#define GeneralIviContainer_MAX_SIZE 16
typedef struct GeneralIviContainer {
    GicPart *tab;
    int32_t count;
} GeneralIviContainer;

enum { /* Pre-defined values of LaneType */
       LaneType_traffic = 0,
       LaneType_through = 1,
       LaneType_reversible = 2,
       LaneType_acceleration = 3,
       LaneType_deceleration = 4,
       LaneType_leftHandTurning = 5,
       LaneType_rightHandTurning = 6,
       LaneType_dedicatedVehicle = 7,
       LaneType_bus = 8,
       LaneType_taxi = 9,
       LaneType_hov = 10,
       LaneType_hot = 11,
       LaneType_pedestrian = 12,
       LaneType_bikeLane = 13,
       LaneType_median = 14,
       LaneType_striping = 15,
       LaneType_trackedVehicle = 16,
       LaneType_parking = 17,
       LaneType_emergency = 18,
       LaneType_verge = 19,
};

typedef struct LaneInformation {
    int32_t laneNumber; /* LanePosition (-1..14) */
    int32_t direction; /* Direction (0..3) */
    BOOL validity_option;
    DTM validity;
    int32_t laneType; /* LaneType (0..31) */
    BOOL laneTypeQualifier_option;
    CompleteVehicleCharacteristics laneTypeQualifier;
    int32_t laneStatus; /* LaneStatus (0..7) */
    BOOL laneWidth_option;
    int32_t laneWidth; /* LaneWidth (0..1023) */
} LaneInformation;

#define LaneInformationList_MAX_SIZE 16
typedef struct LaneInformationList {
    LaneInformation *tab;
    int32_t count;
} LaneInformationList;

typedef struct RccPart {
    ZidList zoneIds;
    RoadType roadType;
    LaneInformationList laneConfiguration;
} RccPart;

#define RoadConfigurationContainer_MAX_SIZE 16
typedef struct RoadConfigurationContainer {
    RccPart *tab;
    int32_t count;
} RoadConfigurationContainer;

typedef struct TcPart {
    BOOL detectionZoneIds_option;
    ZidList detectionZoneIds;
    ZidList relevanceZoneIds;
    BOOL direction_option;
    int32_t direction; /* Direction (0..3) */
    BOOL driverAwarenessZoneIds_option;
    ZidList driverAwarenessZoneIds;
    BOOL minimumAwarenessTime_option;
    int32_t minimumAwarenessTime; /* (0..255)  */
    BOOL applicableLanes_option;
    LanePositionList applicableLanes;
    BOOL layoutId_option;
    int32_t layoutId; /* (1..4,...) */
    BOOL preStoredlayoutId_option;
    int32_t preStoredlayoutId; /* (1..64,...) */
    BOOL text_option;
    TextList text;
    OctetString data;
} TcPart;

#define TextContainer_MAX_SIZE 16
typedef struct TextContainer {
    TcPart *tab;
    int32_t count;
} TextContainer;

typedef struct LayoutComponent {
    int32_t layoutComponentId; /* (1..8,...) */
    int32_t height; /* (10..73) */
    int32_t width; /* (10..265) */
    int32_t x; /* (10..265) */
    int32_t y; /* (10..73) */
    int32_t textScripting; /* (0..1) */
} LayoutComponent;

#define LayoutComponentList_MAX_SIZE 4
typedef struct LayoutComponentList {
    LayoutComponent *tab;
    int32_t count;
} LayoutComponentList;

typedef struct LayoutContainer {
    int32_t layoutId; /* (1..4,...) */
    BOOL height_option;
    int32_t height; /* (10..73) */
    BOOL width_option;
    int32_t width; /* (10..265) */
    LayoutComponentList layoutComponents;
} LayoutContainer;

typedef enum {
    IviContainer_glc,
    IviContainer_giv,
    IviContainer_rcc,
    IviContainer_tc,
    IviContainer_lac,
} IviContainer_choice;

typedef struct IviContainer {
    IviContainer_choice choice;
    union {
        GeographicLocationContainer glc;
        GeneralIviContainer giv;
        RoadConfigurationContainer rcc;
        TextContainer tc;
        LayoutContainer lac;
    } u;
} IviContainer;

#define IviContainerList_MAX_SIZE 8
typedef struct IviContainerList {
    IviContainer *tab;
    int32_t count;
} IviContainerList;

typedef struct IviStructure {
    ManagementContainer_ISO mandatory;
    BOOL optional_option;
    IviContainerList optional;
} IviStructure;

#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_ISO19321_H__ */
