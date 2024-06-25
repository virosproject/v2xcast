/**
 *******************************************************************************
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * This example program is created for demonstrating how to perform CAM (Cooperative
 * awareness basic) service packet sending and receiving procedure which are defined in
 * ETSI EN 302 637-2 V1.4.1 (2019-04), Intelligent Transport Systems (ITS); Vehicular
 * Communications; Basic Set of Applications; Part 2: Specification of Cooperative
 * Awareness Basic Service standard document.
 *
 * Usage:
 *      (1) Correct the toolchain setting then type 'make' to build this example program.
 *      (2) Upload the configuration file 'cam.json' to Caster
 *      (3) Upload the 'v2xcast_cam' execution file to 2 different Unex V2X modules.
 *      (4) Run the 'v2xcast_cam' on module A and module B, then check whether these 2
 *          devices received CAM message from each other.
 *      (5) Open security mode only represent you could config SSP. If you want to send secured
 *          message, you have to upload configuration file 'cam_signed.json' and modify
 *          gnd.json. (Please refer to Unex-APG-ETSI-GN-BTP)
 *
 * @file    v2xcast_cam.c
 * @brief
 * @author  Unex
 *******************************************************************************
 */
#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "error_code_user.h"
#include "poti_caster_service.h"
#include "eu_caster_service.h"
#include "itsmsg_codec.h"
#include "frozen.h"

/*
 *******************************************************************************
 * Macros
 *******************************************************************************
 */

/* Predefined CAM information */
#define CAM_PROTOCOL_VERSION (2) /* ETSI EN 302 637-2 V1.4.1 (2019-04) */
#define CAM_STATION_ID_DEF (168U)
#define CAM_STATION_TYPE_DEF ITS_STATION_SPECIAL_VEHICLE

/** Predefined CAM macro functions
 *  Please correct following macros for getting data from additional INS sensors on host system.
 */
#define CAM_SENSOR_GET_DRIVE_DIRECTION() (0) /* DriveDirection_forward */
#define CAM_SENSOR_GET_VEHICLE_LENGTH_VALUE() (38) /* 0.1 metre. */
#define CAM_SENSOR_GET_VEHICLE_LENGTH_CONF() (0) /* VehicleLengthConfidenceIndication_noTrailerPresent */
#define CAM_SENSOR_GET_VEGICLE_WIDTH_VALUE() (18) /* 0.1 metre. */
#define CAM_SENSOR_GET_LONG_ACCEL_VALUE() (0) /* 0.1 m/s^2. */
#define CAM_SENSOR_GET_LONG_ACCEL_CONF() (102) /* 1 ~ 102 */
#define CAM_SENSOR_GET_CURVATURE_VALUE() (0) /* Curvature, 1 over 30000 meters, (-30000 .. 30001) */
#define CAM_SENSOR_GET_CURVATURE_CONF() (7) /* 0 ~ 7. */
#define CAM_SENSOR_GET_CURVATURE_CONF_CAL_MODE() (2) /* CurvatureCalculationMode_unavailable */
#define CAM_SENSOR_GET_YAW_RATE_VALUE() (0) /* 0,01 degree per second. */
#define CAM_SENSOR_GET_YAW_RATE_CONF() (8) /* YawRateConfidence_unavailable_ITS */

#define IS_CAM_SSP_VALID(x, y) (((x) & (y)) ? true : false)
#define CAM_SSP_LEN (3U)
/* SSP Definitions for Permissions in CAM */
/* Octet Position: 0 , SSP Version control */
/* Octet Position: 1 */
#define CEN_DSRC_TOLLING_ZONE (1 << 7)
#define PUBLIC_TRANSPORT (1 << 6)
#define SPECIAL_TRANSPORT (1 << 5)
#define DANGEROUS_GOODS (1 << 4)
#define ROADWORK (1 << 3)
#define RESCUE (1 << 2)
#define EMERGENCY (1 << 1)
#define SAFETY_CAR (1 << 0)
/* Octet Position: 2 */
#define CLOSED_LANES (1 << 7)
#define REQUEST_FOR_RIGHT_OF_WAY (1 << 6)
#define REQUEST_FOR_FREE_CROSSING_AT_A_TRAFFIC_LIGHT (1 << 5)
#define NO_PASSING (1 << 4)
#define NO_PASSING_FOR_TRUCKS (1 << 3)
#define SPEEED_LIMIT (1 << 2)

#define STATION_CONFIG_FILE_NAME "config_station.json"

#define ERR_MSG_SZ 256
#define MALLOC(sz) malloc(sz)
#define CALLOC(n, sz) calloc((n), (sz))
#define FREE(ptr) free(ptr)
/* clang-format on */

/*
 *******************************************************************************
 * Data type definition
 *******************************************************************************
 */

/* Thread type is using for application send and receive thread, the application thread type is an optional method depend on execute platform */
typedef enum app_thread_type {
    APP_THREAD_TX = 0,
    APP_THREAD_RX = 1
} app_thread_type_t;

/* ITS-S type, defined in ETSI EN 302 636-4-1 V1.2.1 chapter 6.3 Fields of the GeoNetworking address */
typedef enum its_station_type {
    ITS_STATION_UNKNOWN = 0,
    ITS_STATION_PEDESTRAIN = 1,
    ITS_STATION_CYCLIST = 2,
    ITS_STATION_MOPED = 3,
    ITS_STATION_MOTORCYCLE = 4,
    ITS_STATION_PASSENGER_CAR = 5,
    ITS_STATION_BUS = 6,
    ITS_STATION_LIGHT_TRUCK = 7,
    ITS_STATION_HEAVY_TRUCK = 8,
    ITS_STATION_TRAILER = 9,
    ITS_STATION_SPECIAL_VEHICLE = 10,
    ITS_STATION_TRAM = 11,
    ITS_STATION_ROAD_SIDE_UNIT = 15,
} its_station_type_t;

typedef struct station_config {
    uint32_t stationID;
    VehicleRole role;  ///<  Reference to VehicleRole
    bool leftTurnSignalOn;  ///< Left turn signal status, 0 for signal off, 1 for signal on
    bool rightTurnSignalOn;  ///< Right turn signal status, 0 for signal off, 1 for signal on
    bool lightBarInUse;  ///<  Role type: emergency, please refer to LightBarSirenInUse
    bool sirenInUse;  ///<  Role type: emergency, please refer to LightBarSirenInUse
    int32_t causeCode;  ///<  Role type: emergency, please refer to CauseCodeType, -1 for this option not used
} station_config_t;

/*
 *******************************************************************************
 * Global variables
 *******************************************************************************
 */
station_config_t station_config;
bool app_running = true;

/*
 *******************************************************************************
 * Functions declaration
 *******************************************************************************
 */
static void cam_send(caster_comm_config_t *config, bool is_secured);
static void cam_recv(caster_comm_config_t *config);
static void cam_encode(uint8_t **tx_buf, int *tx_buf_len, poti_fix_data_t *p_fix_data);
static int cam_decode(uint8_t *rx_buf, int rx_buf_len, eu_caster_rx_info_t *p_eu_rx_info);
static int cam_check_msg_permission(CAM_V2 *p_cam_msg, uint8_t *p_ssp, uint8_t ssp_len);
static void dump_rx_info(eu_caster_rx_info_t *rx_info);
static void set_tx_info(eu_caster_tx_info_t *tx_info, bool is_secured);

static int32_t cam_set_semi_axis_length(double meter);
static int32_t cam_set_heading_value(double degree);
static int32_t cam_set_altitude_confidence(double metre);
static int32_t cam_set_heading_confidence(double degree);
static int32_t cam_set_speed_confidence(double meter_per_sec);

static int load_station_config(station_config_t *config);
static int32_t app_set_thread_name_and_priority(pthread_t thread, app_thread_type_t type, char *p_name, int32_t priority);

/*
 *******************************************************************************
 * Functions
 *******************************************************************************
 */
void app_signal_handler(int sig_num)
{
    if (sig_num == SIGINT) {
        printf("SIGINT signal!\n");
    }
    if (sig_num == SIGTERM) {
        printf("SIGTERM signal!\n");
    }
    app_running = false;
}

char app_sigaltstack[SIGSTKSZ];
int app_setup_signals(void)
{
    stack_t sigstack;
    struct sigaction sa;
    int ret = -1;

    sigstack.ss_sp = app_sigaltstack;
    sigstack.ss_size = SIGSTKSZ;
    sigstack.ss_flags = 0;
    if (sigaltstack(&sigstack, NULL) == -1) {
        perror("signalstack()");
        goto END;
    }

    sa.sa_handler = app_signal_handler;
    sa.sa_flags = SA_ONSTACK;
    if (sigaction(SIGINT, &sa, 0) != 0) {
        perror("sigaction()");
        goto END;
    }
    if (sigaction(SIGTERM, &sa, 0) != 0) {
        perror("sigaction()");
        goto END;
    }

    ret = 0;
END:
    return ret;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int ret;
    bool is_secured;
    ITSMsgConfig cfg;
    caster_thread_info_t caster_thread_info;
    caster_comm_config_t config;

    if (argc != 4) {
        printf("v2xcast_cam <IP_of_V2Xcast_service> <is_send> <security mode off:0, on:1>\n");
        return -1;
    }
    ret = app_setup_signals();
    if (!IS_SUCCESS(ret)) {
        printf("Fail to app_setup_signals\n");
        return -1;
    }
    is_secured = atoi(argv[3]);

    ret = itsmsg_init(&cfg);
    if (!IS_SUCCESS(ret)) {
        printf("Fail to init ITS message\n");
        return -1;
    }

    config.ip = argv[1];
    config.caster_id = 0;

    if (atoi(argv[2]) == 0) { /* receiving loop */
        eu_caster_init();

        /* If the example is run in Unex device, please using the below functions to set tx and rx message threads name and priority */
        /* If the example is run on other platforms, it is optional to set tx and rx message threads name and priority */
        eu_caster_thread_info_get(&caster_thread_info);
        ret = app_set_thread_name_and_priority(pthread_self(), APP_THREAD_RX, caster_thread_info.rx_thread_name, caster_thread_info.rx_thread_priority_low);

        cam_recv(&config);
        eu_caster_deinit();
    }
    else { /* sending loop */
        eu_caster_init();

        /* Load station setting from configuration file */
        ret = load_station_config(&station_config);
        if (!IS_SUCCESS(ret)) {
            printf("Failed to load station config, ret:%d!\n", ret);
            return -1;
        }
        /* If the example is run in Unex device, please using the below functions to set tx and rx message threads name and priority */
        /* If the example is run on other platforms, it is optional to set tx and rx message threads name and priority */
        eu_caster_thread_info_get(&caster_thread_info);
        ret = app_set_thread_name_and_priority(pthread_self(), APP_THREAD_TX, caster_thread_info.tx_thread_name, caster_thread_info.tx_thread_priority_low);

        cam_send(&config, is_secured);
        eu_caster_deinit();
    }
    return 0;
}

static void cam_encode(uint8_t **tx_buf, int *tx_buf_len, poti_fix_data_t *p_fix_data)
{
    ITSMsgCodecErr err;
    CAM_V2 cam_tx_encode_fmt;
    int ret;

    /* Load station setting from configuration file */
    ret = load_station_config(&station_config);
    if (-1 == ret) {
        printf("Using fixed CAM data.\n");
    }
    /* Make sure we reset the data structure at least once. */
    memset((void *)&cam_tx_encode_fmt, 0, sizeof(cam_tx_encode_fmt));

    /* For the present document, the value of the DE protocolVersion shall be set to CAM_PROTOCOL_VERSION.  */
    cam_tx_encode_fmt.header.protocolVersion = CAM_PROTOCOL_VERSION;
    cam_tx_encode_fmt.header.messageID = CAM_Id;
    if (0 == ret) {
        /* Set stationID form station config file */
        cam_tx_encode_fmt.header.stationID = station_config.stationID;
    }
    else {
        /* Set fixed stationID*/
        cam_tx_encode_fmt.header.stationID = CAM_STATION_ID_DEF;
    }


    /*
     * Time corresponding to the time of the reference position in the CAM, considered
     * as time of the CAM generation.
     * The value of the DE shall be wrapped to 65 536. This value shall be set as the
     * remainder of the corresponding value of TimestampIts divided by 65 536 as below:
     *      generationDeltaTime = TimestampIts mod 65 536
     * TimestampIts represents an integer value in milliseconds since 2004-01-01T00:00:00:000Z
     * as defined in ETSI TS 102 894-2 [2].
     */
    cam_tx_encode_fmt.cam.generationDeltaTime = (int32_t)fmod(p_fix_data->time.tai_since_2004 * 1000.0, 65536); /* TAI milliseconds since 2004-01-01 00:00:00.000 UTC. */

    /*
	 * Position and position accuracy measured at the reference point of the originating
	 * ITS-S. The measurement time shall correspond to generationDeltaTime.
	 * If the station type of the originating ITS-S is set to one out of the values 3 to 11
	 * the reference point shall be the ground position of the centre of the front side of
	 * the bounding box of the vehicle.
	 * The positionConfidenceEllipse provides the accuracy of the measured position
	 * with the 95 % confidence level. Otherwise, the positionConfidenceEllipse shall be
	 * set to unavailable.
	 * If semiMajorOrientation is set to 0 degree North, then the semiMajorConfidence
	 * corresponds to the position accuracy in the North/South direction, while the
	 * semiMinorConfidence corresponds to the position accuracy in the East/West
	 * direction. This definition implies that the semiMajorConfidence might be smaller
	 * than the semiMinorConfidence.
	 */
    cam_tx_encode_fmt.cam.camParameters.basicContainer.stationType = CAM_STATION_TYPE_DEF;
    cam_tx_encode_fmt.cam.camParameters.basicContainer.referencePosition.latitude = (int32_t)(p_fix_data->latitude * 10000000.0); /* Convert to 1/10 micro degree. */
    cam_tx_encode_fmt.cam.camParameters.basicContainer.referencePosition.longitude = (int32_t)(p_fix_data->longitude * 10000000.0); /* Convert to 1/10 micro degree. */
    cam_tx_encode_fmt.cam.camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMajorConfidence = cam_set_semi_axis_length(p_fix_data->err_smajor_axis); /* Convert to centimetre. */
    cam_tx_encode_fmt.cam.camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMinorConfidence = cam_set_semi_axis_length(p_fix_data->err_sminor_axis); /* Convert to centimetre. */
    cam_tx_encode_fmt.cam.camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMajorOrientation = cam_set_heading_value(p_fix_data->err_smajor_orientation);
    cam_tx_encode_fmt.cam.camParameters.basicContainer.referencePosition.altitude.altitudeConfidence = cam_set_altitude_confidence(p_fix_data->err_altitude);
    cam_tx_encode_fmt.cam.camParameters.basicContainer.referencePosition.altitude.altitudeValue = (int32_t)(p_fix_data->altitude * 100.0);
    /*
     * The mandatory high frequency container of CAM.
     */

    /* Heading. */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.heading.headingValue = (int32_t)(p_fix_data->course_over_ground * 10.0); /* Convert to 0.1 degree from North. */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.heading.headingConfidence = cam_set_heading_confidence(p_fix_data->err_course_over_ground); /* Convert to 1 ~ 127 enumeration. */

    /* Speed, 0.01 m/s */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.speed.speedValue = (int16_t)(p_fix_data->horizontal_speed * 100.0); /* Convert to 0.01 metre per second. */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.speed.speedConfidence = cam_set_speed_confidence(p_fix_data->err_horizontal_speed);

    /* Direction. */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.driveDirection = CAM_SENSOR_GET_DRIVE_DIRECTION();

    /* Vehicle length, 0.1 metre  */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.vehicleLength.vehicleLengthValue = CAM_SENSOR_GET_VEHICLE_LENGTH_VALUE();
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.vehicleLength.vehicleLengthConfidenceIndication = CAM_SENSOR_GET_VEHICLE_LENGTH_CONF();

    /* Vehicle width, 0.1 metre */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.vehicleWidth = CAM_SENSOR_GET_VEGICLE_WIDTH_VALUE();

    /* Longitudinal acceleration, 0.1 m/s^2 */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.longitudinalAcceleration.longitudinalAccelerationValue = CAM_SENSOR_GET_LONG_ACCEL_VALUE();
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.longitudinalAcceleration.longitudinalAccelerationConfidence = CAM_SENSOR_GET_LONG_ACCEL_CONF();

    /*
     * Curvature value, 1 over 30000 meters, (-30000 .. 30001)
     * The confidence value shall be set to:
     *      0 if the accuracy is less than or equal to 0,00002 m-1
     *      1 if the accuracy is less than or equal to 0,0001 m-1
     *      2 if the accuracy is less than or equal to 0,0005 m-1
     *      3 if the accuracy is less than or equal to 0,002 m-1
     *      4 if the accuracy is less than or equal to 0,01 m-1
     *      5 if the accuracy is less than or equal to 0,1 m-1
     *      6 if the accuracy is out of range, i.e. greater than 0,1 m-1
     *      7 if the information is not available
     */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.curvature.curvatureValue = CAM_SENSOR_GET_CURVATURE_VALUE();
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.curvature.curvatureConfidence = CAM_SENSOR_GET_CURVATURE_CONF();
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.curvatureCalculationMode = CAM_SENSOR_GET_CURVATURE_CONF_CAL_MODE();

    /* YAW rate, 0,01 degree per second. */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.yawRate.yawRateValue = CAM_SENSOR_GET_YAW_RATE_VALUE();
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.yawRate.yawRateConfidence = CAM_SENSOR_GET_YAW_RATE_CONF();

    /* Optional fields, disable all by default. */
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.accelerationControl_option = FALSE;
    //cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.accelerationControl =
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.lanePosition_option = FALSE;
    //cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.lanePosition =
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.steeringWheelAngle_option = FALSE;
    //cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.steeringWheelAngle =
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.lateralAcceleration_option = FALSE;
    //cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.lateralAcceleration =
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.verticalAcceleration_option = FALSE;
    //cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.verticalAcceleration =
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.performanceClass_option = FALSE;
    //cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.performanceClass =
    cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.cenDsrcTollingZone_option = FALSE;
    //cam_tx_encode_fmt.cam.camParameters.highFrequencyContainer.u.basicVehicleContainerHighFrequency.cenDsrcTollingZone =


    /*
    *   If stationType is set to specialVehicles(10)
    *       LowFrequencyContainer shall be set to BasicVehicleContainerLowFrequency
    *       SpecialVehicleContainer shall be set to EmergencyContainer
    */
    if (cam_tx_encode_fmt.cam.camParameters.basicContainer.stationType == ITS_STATION_SPECIAL_VEHICLE) {
        /*
        * The optional low frequency container of CAM.
        *      vehicleRole: emergency(6)
        *      exteriorLights: select highBeamHeadlightsOn (1)
        *           lowBeamHeadlightsOn (0),
        *           highBeamHeadlightsOn (1),
        *           leftTurnSignalOn (2),
        *           rightTurnSignalOn (3),
        *           daytimeRunningLightsOn (4),
        *           reverseLightOn (5),
        *           fogLightOn (6),
        *           parkingLightsOn (7)
        *      pathHistory: set zero historical path points
        */
        cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer_option = true;
        if (0 == ret) {
            /* Set vehicleRole form station config file */
            cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer.u.basicVehicleContainerLowFrequency.vehicleRole = station_config.role;
        }
        else {
            /* Set fixed vehicleRole*/
            cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer.u.basicVehicleContainerLowFrequency.vehicleRole = VehicleRole_emergency;
        }

        /* alloc and set the bit of bitstring */
        asn1_bstr_alloc_set_bit(&(cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer.u.basicVehicleContainerLowFrequency.exteriorLights), ExteriorLights_MAX_BITS_ITS, ExteriorLights_highBeamHeadlightsOn_ITS);

        /* Set exteriorLights form station config file */
        if (station_config.leftTurnSignalOn) {
            asn1_bstr_set_bit(&(cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer.u.basicVehicleContainerLowFrequency.exteriorLights), ExteriorLights_leftTurnSignalOn_ITS);
        }
        if (station_config.rightTurnSignalOn) {
            asn1_bstr_set_bit(&(cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer.u.basicVehicleContainerLowFrequency.exteriorLights), ExteriorLights_rightTurnSignalOn_ITS);
        }

        cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer.u.basicVehicleContainerLowFrequency.pathHistory.count = 0;

        /*
        * The optional special vehicle container of CAM.
        *       lightBarSirenInUse: select sirenActivated (1)
        *           lightBarActivated (0)
        *           sirenActivated (1)
        *       emergencyPriority: enable , select requestForFreeCrossingAtATrafficLight (1)
        *           requestForRightOfWay (0)
        *           requestForFreeCrossingAtATrafficLight (1)
        *       causeCode/subCauseCode: disable
        */
        cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer_option = true;

        switch (cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer.u.basicVehicleContainerLowFrequency.vehicleRole) {
            case VehicleRole_emergency:
                cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.choice = SpecialVehicleContainer_emergencyContainer;
                /* Set lightBarSirenInUse from station config file */
                asn1_bstr_alloc(&(cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.lightBarSirenInUse), LightBarSirenInUse_MAX_BITS);
                if (station_config.lightBarInUse) {
                    asn1_bstr_set_bit(&(cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.lightBarSirenInUse), LightBarSirenInUse_lightBarActivated);
                }

                if (station_config.sirenInUse) {
                    asn1_bstr_set_bit(&(cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.lightBarSirenInUse), LightBarSirenInUse_sirenActivated);
                }

                cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.emergencyPriority_option = true;
                asn1_bstr_alloc_set_bit(&(cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.emergencyPriority), EmergencyPriority_MAX_BITS, EmergencyPriority_requestForFreeCrossingAtATrafficLight);

                /* Set incidentIndication from station config file */
                if (-1 == station_config.causeCode) {
                    cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.incidentIndication_option = false;
                }
                else {
                    cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.incidentIndication_option = true;
                    cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.incidentIndication.causeCode = station_config.causeCode;
                    cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.incidentIndication.subCauseCode = 0;
                }
                break;
            default:
                /* Please follow the ETSI EN 302 637-2 mapping special vehicle container according to the vehicle role */
                break;
        }
    }


    /* Allocate a buffer for restoring the decode error information if needed. */
    err.msg_size = 512;
    err.msg = calloc(1, err.msg_size);

    if (err.msg != NULL) {
        /* Encode the CAM message. */
        *tx_buf_len = itsmsg_encode(tx_buf, (ItsPduHeader *)&cam_tx_encode_fmt, &err);

        if (*tx_buf_len <= 0) {
            printf("itsmsg_encode error: %s\n", err.msg);
        }

        /* Release the allocated error message buffer. */
        free(err.msg);
    }
    else {
        printf("Cannot allocate memory for error message buffer.\n");
    }

    if (cam_tx_encode_fmt.cam.camParameters.basicContainer.stationType == ITS_STATION_SPECIAL_VEHICLE) {
        /* free the memory for encoding */
        asn1_bstr_free(&(cam_tx_encode_fmt.cam.camParameters.lowFrequencyContainer.u.basicVehicleContainerLowFrequency.exteriorLights));
        asn1_bstr_free(&(cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.lightBarSirenInUse));
        asn1_bstr_free(&(cam_tx_encode_fmt.cam.camParameters.specialVehicleContainer.u.emergencyContainer.emergencyPriority));
    }


    return;
}


static int cam_decode(uint8_t *p_rx_payload, int rx_payload_len, eu_caster_rx_info_t *p_eu_rx_info)
{
    ITSMsgCodecErr err;
    ItsPduHeader *p_rx_decode_hdr = NULL;
    CAM *p_rx_decode_cam = NULL;
    CAM_V2 *p_rx_decode_cam_v2 = NULL;
    int result;

    /* Allocate a buffer for restoring the decode error information if needed. */
    err.msg_size = 256;
    err.msg = calloc(1, err.msg_size);

    if (err.msg == NULL) {
        printf("Cannot allocate memory for error message buffer.\n");
        return -1;
    }

    /* Determine and decode the content in RX payload. */
    result = itsmsg_decode(&p_rx_decode_hdr, p_rx_payload, rx_payload_len, &err);

    /* Check whether this is a ITS message. */
    if (result > 0 && p_rx_decode_hdr != NULL) {
        /* Check whether this is a ITS CAM message. */
        if (p_rx_decode_hdr->messageID == CAM_Id) {
            /* Display ITS message version. */
            printf("ITS msg protocol version: v%d\n", p_rx_decode_hdr->protocolVersion);

            /* Mapping data format base on protocol version. */
            switch (p_rx_decode_hdr->protocolVersion) {
                case 1:
                    /* Convert to version 1 CAM data format. */
                    p_rx_decode_cam = (CAM *)p_rx_decode_hdr;

                    /* Extract other message element, the example only extract contents of newest version Unex supported */
                    printf("[ Received CAM from station %u ]\n", p_rx_decode_cam->header.stationID);
                    break;
                case 2:
                    /* Convert to version 2 CAM data format. */
                    p_rx_decode_cam_v2 = (CAM_V2 *)p_rx_decode_hdr;

                    /* Check CAM msg permission */
                    if (p_eu_rx_info->security.status == EU_SEC_DECAP_VERIFIED_PKT) {
                        result = cam_check_msg_permission(p_rx_decode_cam_v2, p_eu_rx_info->security.ssp, p_eu_rx_info->security.ssp_len);
                        printf("Check msg permissions: ");
                        if (IS_SUCCESS(result)) {
                            printf("trustworthy\n");
                        }
                        else {
                            printf("untrustworthy\n");
                        }
                    }

                    /* Display the decoded CAM content. */
                    printf("[ Received CAM from station %u ]\n", p_rx_decode_cam_v2->header.stationID);
                    printf("\tStation type: %d\n", p_rx_decode_cam_v2->cam.camParameters.basicContainer.stationType);
                    printf("\tgenerationDeltaTime: %d\n", p_rx_decode_cam_v2->cam.generationDeltaTime);
                    printf("\tLatitude: %d\n", p_rx_decode_cam_v2->cam.camParameters.basicContainer.referencePosition.latitude);
                    printf("\tLongitude: %d\n", p_rx_decode_cam_v2->cam.camParameters.basicContainer.referencePosition.longitude);
                    printf("\tAltitude: %d\n", p_rx_decode_cam_v2->cam.camParameters.basicContainer.referencePosition.altitude.altitudeValue);
                    break;
                default:
                    printf("Received unsupported CAM protocol version: %d\n", p_rx_decode_hdr->protocolVersion);
                    break;
            }
        }
        else {
            printf("Received unrecognized ITS message type: %d\n", p_rx_decode_hdr->messageID);
        }

        /* Release the decode message buffer. */
        itsmsg_free(p_rx_decode_hdr);
    }
    else {
        printf("Unable to decode RX packet: %s\n", err.msg);
    }

    /* Release the allocated error message buffer. */
    free(err.msg);

    return 0;
}

static void cam_recv(caster_comm_config_t *config)
{
    eu_caster_rx_info_t rx_info = {0};
    uint8_t rx_buf[EU_CASTER_PKT_SIZE_MAX];
    size_t len;
    int ret;
    caster_handler_t rx_handler = INVALID_CASTER_HANDLER;

    config->caster_comm_mode = CASTER_MODE_RX;
    ret = eu_caster_create(&rx_handler, config);
    if (!IS_SUCCESS(ret)) {
        printf("Cannot link to V2Xcast Service, V2Xcast Service create ret: [%d] %s!\n", ret, ERROR_MSG(ret));
        printf("Please confirm network connection by ping the Unex device then upload a V2Xcast config to create a V2Xcast Service.\n");
        return;
    }

    while (app_running) {
        printf("-----------------------\n");
        ret = eu_caster_rx(rx_handler, &rx_info, rx_buf, sizeof(rx_buf), &len);
        if (IS_SUCCESS(ret)) {
            printf("Received %zu bytes!\n", len);

            /* Display ITS-G5 RX information */
            dump_rx_info(&rx_info);

            /* Try to decode the received message. */
            cam_decode(rx_buf, (int)len, &rx_info);
        }
        else {
            printf("Failed to receive data, err code is: [%d] %s\n", ret, ERROR_MSG(ret));
        }
        fflush(stdout);
    }
    eu_caster_release(rx_handler);
}

static void cam_send(caster_comm_config_t *config, bool is_secured)
{
    uint8_t *tx_buf = NULL;
    int tx_buf_len = 0;
    int ret;
    poti_fix_data_t fix_data = {0};
    poti_gnss_info_t gnss_info = {0};
    eu_caster_tx_info_t tx_info = {0}; /* According to C99, all tx_info members will be set to 0 */
    caster_handler_t tx_handler = INVALID_CASTER_HANDLER;
    caster_handler_t poti_handler = INVALID_CASTER_HANDLER;

    config->caster_comm_mode = CASTER_MODE_TX;
    ret = eu_caster_create(&tx_handler, config);
    if (!IS_SUCCESS(ret)) {
        printf("Cannot link to V2Xcast Service, V2Xcast Service create ret: [%d] %s!\n", ret, ERROR_MSG(ret));
        printf("Please confirm network connection by ping the Unex device then upload a V2Xcast config to create a V2Xcast Service.\n");
        return;
    }

    config->caster_comm_mode = CASTER_MODE_POTI;
    ret = eu_caster_create(&poti_handler, config);
    if (!IS_SUCCESS(ret)) {
        printf("Fail to create POTI caster, ret:%d!\n", ret);
        return;
    }

    while (app_running) {
        printf("-----------------------\n");

        /* Get GNSS fix data from POTI caster service */
        ret = poti_caster_fix_data_get(poti_handler, &fix_data);

        if (ret != 0) {
            printf("Fail to receive GNSS fix data from POTI caster service, %d\n", ret);
            /* Waiting for POTI caster service startup */
            usleep(1000000);
            continue;
        }
        else if (fix_data.mode < POTI_FIX_MODE_2D) {
            printf("GNSS not fix, fix mode: %d\n", fix_data.mode);

            /* Optional, APIs for users to get more GNSS information */
            ret = poti_caster_gnss_info_get(poti_handler, &gnss_info);
            if (IS_SUCCESS(ret)) {
                printf("GNSS antenna status:%d, time sync status: %d\n", gnss_info.antenna_status, gnss_info.time_sync_status);
            }

            /* The interval of get GNSS fix data is depend on GNSS data rate */
            usleep(100000);
            continue;
        }

        /* Optional, NAN value check for GNSS data */
        if ((isnan(fix_data.latitude) == 1) || (isnan(fix_data.longitude) == 1) || (isnan(fix_data.altitude) == 1) || (isnan(fix_data.horizontal_speed) == 1) || (isnan(fix_data.course_over_ground) == 1)) {
            printf("GNSS fix data has NAN value, latitude: %f, longitude : %f, altitude : %f, horizontal speed : %f, course over ground : %f\n", fix_data.latitude, fix_data.longitude, fix_data.altitude, fix_data.horizontal_speed, fix_data.course_over_ground);
            continue;
        }

        ret = poti_caster_gnss_info_get(poti_handler, &gnss_info);
        if (IS_SUCCESS(ret)) {
            printf("Access layer time sync state: %d , unsync times: %d\n", gnss_info.acl_time_sync_state, gnss_info.acl_unsync_times);
        }

        cam_encode(&tx_buf, &tx_buf_len, &fix_data);
        if (tx_buf != NULL) {
            printf("CAM encoded data:\n");
            asn1_dump_buf(tx_buf, tx_buf_len);
            set_tx_info(&tx_info, is_secured);

            ret = eu_caster_tx(tx_handler, &tx_info, tx_buf, (size_t)tx_buf_len);
            if (IS_SUCCESS(ret)) {
                printf("Transmitted %d bytes!\n", tx_buf_len);
                printf("Transmitted CAM\n");
            }
            else {
                printf("Failed to transmit data, err code is: [%d] %s\n", ret, ERROR_MSG(ret));
                printf("Failed to transmit CAM\n");
            }
            itsmsg_buf_free(tx_buf);
        }
        fflush(stdout);

        /* The message generation interval please refer to ETSI EN 302 637-2 */
        /* The example generation interval is depend on POTI output rate (default:10Hz) */
    }

    eu_caster_release(tx_handler);
    eu_caster_release(poti_handler);
}

static int cam_check_msg_permission(CAM_V2 *p_cam_msg, uint8_t *p_ssp, uint8_t ssp_len)
{
    int rc = 0, fbs;

    if (ssp_len < CAM_SSP_LEN) {
        rc = -1;
        printf("Err: SSP length[%d] is not enough\n", ssp_len);
        goto FAILURE;
    }

    if (p_cam_msg->cam.camParameters.specialVehicleContainer_option) {
        /*
        *   For example, only check emergencyContainer
        *   Please refer to ETSI EN 302 637-2 to check related SSP item
        */
        switch (p_cam_msg->cam.camParameters.specialVehicleContainer.choice) {
            case SpecialVehicleContainer_emergencyContainer:
                if (!IS_CAM_SSP_VALID(EMERGENCY, p_ssp[1])) {
                    printf("Err: certificate not allowed to sign EMERGENCY\n");
                    rc = -1;
                    goto FAILURE;
                }

                if (p_cam_msg->cam.camParameters.specialVehicleContainer.u.emergencyContainer.emergencyPriority_option) {
                    fbs = asn1_bstr_ffs(&(p_cam_msg->cam.camParameters.specialVehicleContainer.u.emergencyContainer.emergencyPriority));
                    switch (fbs) {
                        case EmergencyPriority_requestForRightOfWay:
                            if (!IS_CAM_SSP_VALID(REQUEST_FOR_RIGHT_OF_WAY, p_ssp[2])) {
                                printf("Err: certificate not allowed to sign REQUEST_FOR_RIGHT_OF_WAY\n");
                                rc = -1;
                                goto FAILURE;
                            }
                            break;
                        case EmergencyPriority_requestForFreeCrossingAtATrafficLight:
                            if (!IS_CAM_SSP_VALID(REQUEST_FOR_FREE_CROSSING_AT_A_TRAFFIC_LIGHT, p_ssp[2])) {
                                printf("Err: certificate not allowed to sign REQUEST_FOR_FREE_CROSSING_AT_A_TRAFFIC_LIGHT\n");
                                rc = -1;
                                goto FAILURE;
                            }
                            break;
                    }
                }
                break;
            default:
                // nothing
                break;
        }
    }

FAILURE:
    return rc;
}

static void dump_rx_info(eu_caster_rx_info_t *rx_info)
{
    struct tm *timeinfo;
    char buffer[80];
    time_t t;

    t = rx_info->timestamp.tv_sec;
    timeinfo = localtime(&t);
    strftime(buffer, 80, "%Y%m%d%H%M%S", timeinfo);
    printf("timestamp:%s\n", buffer);
    printf("rssi:%hd\n", rx_info->rssi);
    printf("data rate:%hu\n", rx_info->data_rate);
    printf("remain hop:%hu\n", rx_info->remain_hop_limit);
    printf("decap status:%d\n", rx_info->security.status);
    switch (rx_info->security.status) {
        case EU_SEC_DECAP_VERIFIED_PKT:
            printf("\tSecurity status: this packet is verified\n");
            printf("\tITS-AID: %u\n", rx_info->security.its_aid);
            printf("\tssp_len = %hu\n", rx_info->security.ssp_len);
            for (uint8_t i = 0; i < rx_info->security.ssp_len; i++) {
                printf("\tssp[%hu]=%hu\n", i, rx_info->security.ssp[i]);
            }
            break;
        case EU_SEC_DECAP_UNVERIFIABLE_PKT:
            printf("\tSecurity status:  this packet is untrustworthy\n");
            break;
        case EU_SEC_DECAP_INVALID_FMT:
            printf("\tSecurity status: decapsulation error (%d), the payload content is invalid\n", rx_info->security.status);
            break;
        default:
            printf("\tSecurity status: other (%d)\n", rx_info->security.status);
            break;
    }
    return;
}

static void set_tx_info(eu_caster_tx_info_t *tx_info, bool is_secured)
{
    /* set data rate*/
    tx_info->data_rate_is_present = true;
    tx_info->data_rate = 12; /* 12 (500kbps) = 6 (Mbps) */

    if (is_secured) {
        /* set security*/
        tx_info->security_is_present = true;
        /*
        * Assign CAM service specific permissions according to the actual content in payload.
        * Please refer to ETSI TS 103 097, ETSI EN 302 637-2 for more details.
        * Please refer to Unex-APG-ETSI-GN-BTP for more information of build-in certificates
        */
        /* SSP Version control */
        tx_info->security.ssp[0] = 0x0;
        /* Service-specific parameter */
        tx_info->security.ssp[1] = EMERGENCY; /* Emergency container */
        tx_info->security.ssp[2] = REQUEST_FOR_FREE_CROSSING_AT_A_TRAFFIC_LIGHT; /* EmergencyPriority */
        tx_info->security.ssp_len = 3;
    }

    return;
}

/**
 * function_example - Function example
 *
 * @param   [in]    input       Example input.
 * @param   [out]   *p_output   Example output.
 *
 * @return  [int]   Function executing result.
 * @retval  [0]     Success.
 * @retval  [-1]    Fail.
 *
 */
static int32_t cam_set_semi_axis_length(double meter)
{
    /*
     * According to ETSI TS 102 894-2 V1.2.1 (2014-09)
     * The value shall be set to:
     * 1 if the accuracy is equal to or less than 1 cm,
     * n (n > 1 and n < 4 093) if the accuracy is equal to or less than n cm,
     * 4 093 if the accuracy is equal to or less than 4 093 cm,
     * 4 094 if the accuracy is out of range, i.e. greater than 4 093 cm,
     * 4 095 if the accuracy information is unavailable.
     */
    double centimeter;
    int32_t value;

    centimeter = meter * 100.0;

    if (centimeter < 1.0) {
        value = 1;
    }
    else if (centimeter > 1.0 && centimeter < 4093.0) {
        value = (int32_t)centimeter;
    }
    else {
        value = 4094;
    }

    return value;
}

/**
 * function_example - Function example
 *
 * @param   [in]    input       Example input.
 * @param   [out]   *p_output   Example output.
 *
 * @return  [int]   Function executing result.
 * @retval  [0]     Success.
 * @retval  [-1]    Fail.
 *
 */
static int32_t cam_set_heading_value(double degree)
{
    int32_t value;

    if (isnan(degree) == 1) {
        value = 3601;
    }
    else {
        value = degree * 10;
    }

    return value;
}

/**
 * function_example - Function example
 *
 * @param   [in]    input       Example input.
 * @param   [out]   *p_output   Example output.
 *
 * @return  [int]   Function executing result.
 * @retval  [0]     Success.
 * @retval  [-1]    Fail.
 *
 */
static int32_t cam_set_altitude_confidence(double metre)
{
    /*
	 * According to ETSI TS 102 894-2 V1.2.1 (2014-09)
	 * Absolute accuracy of a reported altitude value of a geographical point for a predefined
	 * confidence level (e.g. 95 %). The required confidence level is defined by the
	 * corresponding standards applying the usage of this DE.
	 * The value shall be set to:
	 * 	0 if the altitude accuracy is equal to or less than 0,01 metre
	 * 	1 if the altitude accuracy is equal to or less than 0,02 metre
	 * 	2 if the altitude accuracy is equal to or less than 0,05 metre
	 * 	3 if the altitude accuracy is equal to or less than 0,1 metre
	 * 	4 if the altitude accuracy is equal to or less than 0,2 metre
	 * 	5 if the altitude accuracy is equal to or less than 0,5 metre
	 * 	6 if the altitude accuracy is equal to or less than 1 metre
	 * 	7 if the altitude accuracy is equal to or less than 2 metres
	 * 	8 if the altitude accuracy is equal to or less than 5 metres
	 * 	9 if the altitude accuracy is equal to or less than 10 metres
	 * 	10 if the altitude accuracy is equal to or less than 20 metres
	 * 	11 if the altitude accuracy is equal to or less than 50 metres
	 * 	12 if the altitude accuracy is equal to or less than 100 metres
	 * 	13 if the altitude accuracy is equal to or less than 200 metres
	 * 	14 if the altitude accuracy is out of range, i.e. greater than 200 metres
	 * 	15 if the altitude accuracy information is unavailable
	 */

    int32_t enum_value;

    if (metre <= 0.01) {
        enum_value = AltitudeConfidence_alt_000_01;
    }
    else if (metre <= 0.02) {
        enum_value = AltitudeConfidence_alt_000_02;
    }
    else if (metre <= 0.05) {
        enum_value = AltitudeConfidence_alt_000_05;
    }
    else if (metre <= 0.1) {
        enum_value = AltitudeConfidence_alt_000_10;
    }
    else if (metre <= 0.2) {
        enum_value = AltitudeConfidence_alt_000_20;
    }
    else if (metre <= 0.5) {
        enum_value = AltitudeConfidence_alt_000_50;
    }
    else if (metre <= 1.0) {
        enum_value = AltitudeConfidence_alt_001_00;
    }
    else if (metre <= 2.0) {
        enum_value = AltitudeConfidence_alt_002_00;
    }
    else if (metre <= 5.0) {
        enum_value = AltitudeConfidence_alt_005_00;
    }
    else if (metre <= 10.0) {
        enum_value = AltitudeConfidence_alt_010_00;
    }
    else if (metre <= 20.0) {
        enum_value = AltitudeConfidence_alt_020_00;
    }
    else if (metre <= 50.0) {
        enum_value = AltitudeConfidence_alt_050_00;
    }
    else if (metre <= 100.0) {
        enum_value = AltitudeConfidence_alt_100_00;
    }
    else if (metre <= 200.0) {
        enum_value = AltitudeConfidence_alt_200_00;
    }
    else {
        enum_value = AltitudeConfidence_outOfRange;
    }

    return enum_value;
}

/**
 * function_example - Function example
 *
 * @param   [in]    input       Example input.
 * @param   [out]   *p_output   Example output.
 *
 * @return  [int]   Function executing result.
 * @retval  [0]     Success.
 * @retval  [-1]    Fail.
 *
 */
static int32_t cam_set_heading_confidence(double degree)
{
    /*
	 * According to ETSI TS 102 894-2 V1.2.1 (2014-09)
	 *
	 * The absolute accuracy of a reported heading value for a predefined confidence level
	 * (e.g. 95 %). The required confidence level is defined by the corresponding standards
	 * applying the DE.
	 * The value shall be set to:
	 * ??1 if the heading accuracy is equal to or less than 0,1 degree,
	 * ??n (n > 1 and n < 125) if the heading accuracy is equal to or less than
	 * n ? 0,1 degree,
	 * 	125 if the heading accuracy is equal to or less than 12,5 degrees,
	 * 	126 if the heading accuracy is out of range, i.e. greater than 12,5 degrees,
	 * 	127 if the heading accuracy information is not available.
	 */

    int32_t value;

    if (degree <= 0.1) {
        value = 1;
    }
    else if (degree > 0.1 && degree <= 12.5) {
        value = (int32_t)(degree * 10);
    }
    else {
        value = 126;
    }

    return value;
}

/**
 * function_example - Function example
 *
 * @param   [in]    input       Example input.
 * @param   [out]   *p_output   Example output.
 *
 * @return  [int]   Function executing result.
 * @retval  [0]     Success.
 * @retval  [-1]    Fail.
 *
 */
static int32_t cam_set_speed_confidence(double meter_per_sec)
{
    /*
	 * According to ETSI TS 102 894-2 V1.2.1 (2014-09)
	 * The value shall be set to:
	 * 	1 if the speed accuracy is equal to or less than 1 cm/s.
	 * 	n (n > 1 and n < 125) if the speed accuracy is equal to or less than n cm/s.
	 * 	125 if the speed accuracy is equal to or less than 125 cm/s.
	 * 	126 if the speed accuracy is out of range, i.e. greater than 125 cm/s.
	 * 	127 if the speed accuracy information is not available.
	 */

    double cm_per_sec;
    int32_t value;

    cm_per_sec = meter_per_sec * 100.0;

    if (cm_per_sec <= 1.0) {
        value = 1;
    }
    else if (cm_per_sec > 1.0 && cm_per_sec < 125.0) {
        value = (int32_t)(cm_per_sec);
    }
    else if (cm_per_sec >= 125.0 && cm_per_sec < 126.0) {
        value = 125;
    }
    else {
        value = 126;
    }

    return value;
}

/**
 *
 * @fn load_station_config(station_config_t *config)
 * @brief   load station config from file
 * @param   [out] config configuration read form file
 *
 * @return  [int]   Function executing result.
 * @retval  [0]     Success.
 * @retval  [-1]    Fail.
 */
static int load_station_config(station_config_t *config)
{
    char *content = json_fread(STATION_CONFIG_FILE_NAME);
    if (content == NULL) {
        /* File read failed, create the default config file */
        printf("The station config file not exist, create the default config file!\n");
        json_fprintf(STATION_CONFIG_FILE_NAME,
                     "{ \
                        SendCAM : [   \
                        { \
                            stationID : 168, \
                            exteriorLights : \
                            { \
                                leftTurnSignalOn : 0, \
                                rightTurnSignalOn : 0, \
                            }, \
                            role : emergency, \
                            emergency :  \
                            { \
                                lightBarInUse : 0, \
                                sirenInUse : 1, \
                                causeCode : -1, \
                            } \
                        } \
                        ] \
                    }");
        json_prettify_file(STATION_CONFIG_FILE_NAME);  // Optional
        content = json_fread(STATION_CONFIG_FILE_NAME);
    }

    if (content != NULL) {
        /* Extract setting form JSON format */
        struct json_token t_root;
        int i, len = strlen(content);

        for (i = 0; json_scanf_array_elem(content, len, ".SendCAM", i, &t_root) > 0; i++) {
            char *role = NULL;

            printf("Index %d, token %.*s\n", i, t_root.len, t_root.ptr);
            json_scanf(t_root.ptr, t_root.len, "{stationID: %d}", &(config->stationID));
            json_scanf(t_root.ptr, t_root.len, "{exteriorLights: {leftTurnSignalOn: %d, rightTurnSignalOn: %d}}", &(config->leftTurnSignalOn), &(config->rightTurnSignalOn));
            json_scanf(t_root.ptr, t_root.len, "{role: %Q}", &role);

            if (0 == strcmp("emergency", role)) {
                config->role = VehicleRole_emergency;
                json_scanf(t_root.ptr, t_root.len, "{emergency: {lightBarInUse: %d, sirenInUse: %d, causeCode: %d}}", &(config->lightBarInUse), &(config->sirenInUse), &(config->causeCode));
            }
            else {
                config->role = VehicleRole_Default;
            }
            if (role != NULL) {
                free(role);
            }
        }
        free(content);
        return 0;
    }
    else {
        printf("Load station config file failed!\n");
        return -1;
    }

    return 0;
}

static int32_t app_set_thread_name_and_priority(pthread_t thread, app_thread_type_t type, char *p_name, int32_t priority)
{
    int32_t result;
    caster_thread_info_t limited_thread_config;

#ifdef __SET_PRIORITY__
    struct sched_param param;
#endif  // __SET_PRIORITY__
    if (p_name == NULL) {
        return -1;
    }

    /* Check thread priority is in the limited range */
    eu_caster_thread_info_get(&limited_thread_config);

    if (APP_THREAD_TX == type) {
        /* Check the limited range for tx thread priority */
        if ((priority < limited_thread_config.tx_thread_priority_low) || (priority > limited_thread_config.tx_thread_priority_high)) {
            /* Thread priority is out of range */
            printf("The tx thread priority is out of range (%d-%d): %d \n", limited_thread_config.tx_thread_priority_low, limited_thread_config.tx_thread_priority_high, priority);
            return -1;
        }
    }
    else if (APP_THREAD_RX == type) {
        /* Check the limited range for rx thread priority */
        if ((priority < limited_thread_config.rx_thread_priority_low) || (priority > limited_thread_config.rx_thread_priority_high)) {
            /* Thread priority is out of range */
            printf("The rx thread priority is out of range (%d-%d): %d \n", limited_thread_config.rx_thread_priority_low, limited_thread_config.rx_thread_priority_high, priority);
            return -1;
        }
    }
    else {
        /* Target thread type is unknown */
        printf("The thread type is unknown: %d \n", type);
        return -1;
    }

    result = pthread_setname_np(thread, p_name);
    if (result != 0) {
        printf("Can't set thread name: %d (%s) \n", result, strerror(result));
        return -1;
    }

#ifdef __SET_PRIORITY__
    param.sched_priority = priority;
    result = pthread_setschedparam(thread, SCHED_FIFO, &param);
    if (result != 0) {
        printf("Can't set thread priority: %d (%s) \n", result, strerror(result));
        return -1;
    }
#endif  // __SET_PRIORITY__
    return 0;
}
