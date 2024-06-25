/**
 *******************************************************************************
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * @file    error_code_enum.h
 * @brief   This header is generated automatically for Unex V2X SDK v1.13.6
 *          please do not modify this file manually.
 * @author  Unex
 *******************************************************************************
 */

#ifndef __ERROR_CODE_ENUM_H__
#define __ERROR_CODE_ENUM_H__

/* Error code definition for Unex V2X SDK v1.13.6 */
typedef enum error_code {

    /* generic */
    SUCCESS                                                          = 0, /* No error */
    ERROR_NULL_POINTER                                               = -1, /* Null pointer access */
    ERROR_INIT_FAIL                                                  = -2, /* Initialization failed */

    ERROR_NOT_INIT                                                   = -4, /* Not yet initialized */
    ERROR_INVALID_ARGS                                               = -5, /* Value of argument is invalid */
    ERROR_NO_MEMORY                                                  = -6, /* No more memory */
    ERROR_TIMEOUT                                                    = -7, /* Timeout */
    ERROR_UNSPECIFIED                                                = -8, /* Unspecified error */
    ERROR_UNSUPPORT_TYPE                                             = -9, /* Unsupported type */
    ERROR_NO_RESOURCE                                                = -10, /* No resource */
    ERROR_BUSY                                                       = -11, /* Busy */
    ERROR_CONN_FAIL                                                  = -12, /* Connect failed */
    ERROR_FILE_NOT_EXISTS                                            = -13, /* Can't find the file */
    ERROR_FILE_CONTENT_INVALID                                       = -14, /* File content is invalid */
    ERROR_FILE_NUM_INVALID                                           = -15, /* File number is invalid */
    ERROR_OVER_BUFFER_SIZE                                           = -16, /* The access exceeds buffer size */
    ERROR_FILE_OPEN_FAIL                                             = -17, /* Can't open file */
    ERROR_DIR_OPEN_FAIL                                              = -18, /* Can't open folder */
    ERROR_DIR_CREATE_FAIL                                            = -19, /* Can't create folder */
    ERROR_UNEXPECTED_VALUE                                           = -20, /* Unexpected value */
    ERROR_NOT_ENOUGH_CERT                                            = -21, /* Can't changeover at cert due to the number of cert is only one */

    /* poti */
    ERROR_POTI_SHM_VER_ERROR                                         = -1024, /* Version of poti shm is wrong */
    ERROR_NOT_SET_TAI_OFFSET                                         = -1025, /* System TAI offset is not set */

    /* gn */
    ERROR_GN_HDLR_IPC_ALLOCATE                                       = -2048, /* Can't allocate GN IPC interface */
    ERROR_GN_HDLR_IPC_SET_CFG                                        = -2049, /* Can't setup GN IPC interface */
    ERROR_GN_HDLR_IPC_INVALID_IDX                                    = -2050, /* Invalid GN handler index */
    ERROR_GN_HDLR_IPC_INVALID_LOCK                                   = -2051, /* Invalid GN IPC lock */
    ERROR_GN_HDLR_IPC_CONN_PUBLIC_IF                                 = -2052, /* Can't connect to GN public channel, please make sure GN daemon is activated */
    ERROR_GN_HDLR_IPC_VERSION_MISMATCH                               = -2053, /* The IPC version is mismatched */
    ERROR_GN_HDLR_IPC_REQ_SIZE_INVALID                               = -2054, /* Wrong GN IPC request message size */
    ERROR_GN_HDLR_IPC_REQ_ISSUE_FAIL                                 = -2055, /* Can't issue GN IPC request */
    ERROR_GN_HDLR_IPC_RSP_SIZE_INVALID                               = -2056, /* Wrong GN IPC response message size */
    ERROR_GN_HDLR_IPC_RSP_HDR_INVALID                                = -2057, /* Wrong GN IPC response content */
    ERROR_GN_HDLR_IPC_RSP_REJECT                                     = -2058, /* Rejected by GN service */
    ERROR_GN_HDLR_IPC_SERVICE_UNAVAILABLE                            = -2059, /* GN service is unavailable, please make sure GN daemon is activated and APP should recreates service handler */
    ERROR_GN_HDLR_IPC_MEDIA_PROFILE_MISMATCH                         = -2060, /* Media-dependent profile is mismatched */

    ERROR_GN_HDLR_MGNT_IPC_ESTI_FAIL                                 = -2080, /* Can't estimate GN MGNT service connection */
    ERROR_GN_HDLR_MGNT_IPC_IDX_INVALID                               = -2081, /* Wrong GN MGNT service connection index */
    ERROR_GN_HDLR_MGNT_SECURITY_MIB_DISABLED                         = -2082, /* btp_config.security.type is BY_PROFILE, but "is_mib_its_gn_security_enabled" is false in gnd.json */
    ERROR_GN_HDLR_MGNT_SECURITY_TYPE_INVALID                         = -2083, /* Incorrect security type */
    ERROR_GN_HDLR_MGNT_SECURITY_TYPE_UNSECURED_OPERATION             = -2084, /* btp_config.security.type is UNSECURED, but "is_mib_its_gn_security_enabled" is true in gnd.json */
    ERROR_GN_HDLR_MGNT_SECURITY_AID_INVALID                          = -2085, /* This ITS-AID is invalid and should not be used */
    ERROR_GN_HDLR_MGNT_SECURITY_AID_CONFLICT                         = -2086, /* This ITS-AID is occupied by other APP */

    ERROR_GN_HDLR_TX_IPC_ESTI_FAIL                                   = -2112, /* Can't estimate GN TX service connection */
    ERROR_GN_HDLR_TX_IPC_IDX_INVALID                                 = -2113, /* Wrong GN TX service connection index */
    ERROR_GN_HDLR_TX_PAYLOAD_EMPTY                                   = -2114, /* TX payload is empty */
    ERROR_GN_HDLR_TX_PAYLOAD_TOO_LONG                                = -2115, /* TX payload size is too large */
    ERROR_GN_HDLR_TX_NETWORK_HDR_TYPE_UNSUPPORTED                    = -2116, /* Unsupported TX network header type */
    ERROR_GN_HDLR_TX_TRANSPORT_HDR_TYPE_UNSUPPORTED                  = -2117, /* Unsupported TX transport header type */
    ERROR_GN_HDLR_TX_SRC_PORT_NOT_BIND                               = -2118, /* TX source port is not binded */
    ERROR_GN_HDLR_TX_DEST_AREA_INVALID_TYPE                          = -2119, /* TX dest area type setting is invalid */
    ERROR_GN_HDLR_TX_DEST_AREA_DISTANCE_IS_ZERO                      = -2120, /* TX dest area distance setting is zero */
    ERROR_GN_HDLR_TX_DEST_AREA_INVALID_LATITUDE                      = -2121, /* TX dest area latitude setting is invalid */
    ERROR_GN_HDLR_TX_DEST_AREA_INVALID_LONGITUDE                     = -2122, /* TX dest area longitude setting is invalid */
    ERROR_GN_HDLR_TX_DEST_AREA_INVALID_ANGLE                         = -2123, /* TX dest area angle is invalid */
    ERROR_GN_HDLR_TX_SSP_LEN_TOO_LONG                                = -2124, /* The length of SSP is too large */
    ERROR_GN_HDLR_TX_TRAFFIC_CLASS_ID_INVALID                        = -2125, /* The inputted traffic class ID is invalid */
    ERROR_GN_HDLR_TX_ACCESS_LAYER_NOT_READY                          = -2126, /* The access layer is not ready to send packet (check time sync or GNSS status) */
    ERROR_GN_HDLR_TX_SECURITY_ANONYMOUS_MODE_DISABLED                = -2127, /* Not allow L2ID/AT change request due to is_mib_its_gn_security_enabled or is_mib_its_gn_anonymous_addr_enabled is false in gnd.json  */

    ERROR_GN_HDLR_RX_IPC_ESTI_FAIL                                   = -2144, /* Can't estimate GN RX service connection */
    ERROR_GN_HDLR_RX_IPC_IDX_INVALID                                 = -2145, /* Wrong GN RX IPC interface index */
    ERROR_GN_HDLR_RX_TRANSPORT_HDR_TYPE_UNSUPPORTTED                 = -2146, /* Unsupported RX transport header type */
    ERROR_GN_HDLR_RX_PKT_SIZE_INVALID                                = -2147, /* Incorrect RX packet size */
    ERROR_GN_HDLR_RX_BUF_TOO_SHORT                                   = -2148, /* RX packet is larger than inputted buffer */
    ERROR_GN_HDLR_RX_HND_DUPLICATE_BIND                              = -2149, /* A port is already bound to this handler */
    ERROR_GN_HDLR_RX_REACHED_MAX_BIND_RESOURCE_LIMIT                 = -2150, /* Reached maximum bind resource limitation */
    ERROR_GN_HDLR_RX_PORT_HAS_ALREADY_BEEN_BOUND_BY_ANOTHER_APP      = -2151, /* The specified port has already been bound by another APP */

    /* dot3 */
    ERROR_DOT3_PARAMS_INVALID                                        = -3072, /* Input parameters are invalid */
    ERROR_DOT3_RADIO_ID_INVALID                                      = -3073, /* Radio id is invalid */
    ERROR_DOT3_PAYLOAD_SIZE_INVALID                                  = -3074, /* The tx payload size send from upper layer to dot3d is invalid */
    ERROR_DOT3_PAYLOAD_TRUNCATED                                     = -3075, /* The payload which send from dot3d to upper layer is truncated */
    ERROR_DOT3_PACKET_SIZE_TOO_LONG                                  = -3076, /* The packet size include wsm header send from dot3d to lower layer is too long */
    ERROR_DOT3_ENTRY_NOT_FOUND                                       = -3077, /* Requesting entry is not found */
    ERROR_DOT3_CHANNEL_NOT_FOUND                                     = -3078, /* Requesting channel is not found */
    ERROR_DOT3_PSID_CONFLIT                                          = -3079, /* Requesting PSID has been registered */
    ERROR_DOT3_PSID_INVALID                                          = -3080, /* The PSID value is invalid */
    ERROR_DOT3_DATA_RATE_INVALID                                     = -3081, /* The data rate is invalid */
    ERROR_DOT3_OUT_OF_RESOURCE                                       = -3082, /* System resourece is full */
    ERROR_DOT3_CHANNEL_SWITCH_DISABLED                               = -3083, /* Channel switch is disabled */
    ERROR_DOT3_NOT_SUPPORTED                                         = -3084, /* Request is not supported */
    ERROR_DOT3_TIME_UNSYNC                                           = -3085, /* System time is not synchronized */
    ERROR_DOT3_UNSPEC                                                = -3086, /* Unspecified error */
    ERROR_DOT3_SYS_REINIT                                            = -3087, /* System has been initialized */
    ERROR_DOT3_SYS_NOT_INITED                                        = -3088, /* System has not been initialized */
    ERROR_DOT3_SYS_HANDLE_INVALID                                    = -3089, /* Input handle is invalid */
    ERROR_DOT3_SYS_ERR_INTERNAL                                      = -3090, /* System internal error */
    ERROR_DOT3_SYS_LOSS_OF_IPC                                       = -3091, /* IPC has been closed */
    ERROR_DOT3_SYS_TIMEOUT                                           = -3092, /* Request is timeout */
    ERROR_DOT3_SYS_OUT_OF_MEM                                        = -3093, /* System is out of memory */

    /* its_security */
    ERROR_ETSI_SEC_OPEN_UPDATE_DIR_ERROR                             = -4096, /* Open Update Dir fail */
    ERROR_ETSI_SEC_OPEN_UPDATE_CA_DIR_ERROR                          = -4097, /* Open Update CA Dir fail */
    ERROR_ETSI_SEC_OPEN_UPDATE_EE_DIR_ERROR                          = -4098, /* Open Update EE Dir fail */
    ERROR_ISC_DELETE_UPDATE_FOLDER_ERROR                             = -4099, /* Delete update folder fail */
    ERROR_ISC_MAKE_UPDATE_FOLDER_ERROR                               = -4100, /* Make update folder fail */
    ERROR_ISC_MAKE_UPDATE_CA_FOLDER_ERROR                            = -4101, /* Make update CA folder fail */
    ERROR_ISC_MAKE_UPDATE_EE_FOLDER_ERROR                            = -4102, /* Make update EE folder fail */
    ERROR_ETSI_SEC_CERT_FILE_ERROR                                   = -4103, /* Can't access this certificate file or it doesn't exist */
    ERROR_ETSI_SEC_STORE_CA_CERT_ERROR                               = -4104, /* Store CA certificate fail */
    ERROR_ETSI_SEC_STORE_AT_CERT_ERROR                               = -4105, /* Store AT certificate fail */
    ERROR_ETSI_SEC_PRI_KEY_FILE_ERROR                                = -4106, /* Private key file access fail */
    ERROR_ETSI_SEC_BUF_SIZE_NOT_ENOUGH                               = -4107, /* Buf size isn't enough */
    ERROR_ETSI_SEC_TBL_NON_EXIST                                     = -4108, /* This table doesn't exist */
    ERROR_ETSI_SEC_CMH_EXAHSTED                                      = -4109, /* Dot2 CMH exausted */
    ERROR_ETSI_SEC_SET_REPETITIVE_AID_PROFILE_MAPPING                = -4110, /* This AID has been mapped to a security profile */
    ERROR_ETSI_SEC_PROFILE_MAPPING_NON_EXIST                         = -4111, /* This AID associates with profile doesn't exist in mapping table */
    ERROR_ETSI_SEC_PROFILE_NON_EXIST                                 = -4112, /* This security profile doesn't exist */
    ERROR_ETSI_SEC_PROFILE_NOT_SUPPORT_VERIFY_SIGNED_MSG             = -4113, /* This security profile doesn't support to verify signed message */
    ERROR_ETSI_SEC_CERT_NON_EXIST                                    = -4114, /* The corresponding certificate doesn't exist, can't sign/encrypt message */
    ERROR_ETSI_SEC_DEL_CERT_NUM_INCONSISTENT                         = -4115, /* Number of deleted certs are not the same as number of whole cert */
    ERROR_ETSI_SEC_CMNG_INIT_FAIL                                    = -4116, /* ISC Certificate manager init fail */
    ERROR_ETSI_SEC_ENCAP_UNSECURE_ERROR                              = -4117, /* Encap UnsecuredData fail */
    ERROR_ETSI_SEC_SIGN_DATA_ERROR                                   = -4118, /* Sign data fail */
    ERROR_ETSI_SEC_VERIFY_DATA_ERROR                                 = -4119, /* Verify data fail */
    ERROR_ETSI_SEC_INVALID_AID                                       = -4120, /* This AID value is invalid */
    ERROR_ETSI_SEC_NO_CERT_INFO                                      = -4121, /* Can't find certificate information */
    ERROR_ETSI_SEC_CERT_EXPIRETIME_EXPIRED                           = -4122, /* Certificate expired */
    ERROR_ETSI_SEC_CERT_NO_PERMISSION                                = -4123, /* This certificate don't have enough Service Specific permission(SSP) */
    ERROR_ETSI_SEC_INVALID_PROFILE_NAME                              = -4124, /* Invalid profile name */
    ERROR_ETSI_SEC_DECAP_INVALID_FMT                                 = -4125, /* Invalid EtsiTs103097 format */
    ERROR_ETSI_SEC_DECAP_RAW_BUF_SIZE_NOT_ENOUGH                     = -4126, /* Plaintext buffer size isn't enough */
    ERROR_ETSI_SEC_DECAP_TOBESIGN_BUF_SIZE_NOT_ENOUGH                = -4127, /* Internal ToBeSign buffer size isn't enough */
    ERROR_ETSI_SEC_DECAP_NO_CERT                                     = -4128, /* SignerID: certificate, Can't be find in SPDU */
    ERROR_ETSI_SEC_DECAP_CERT_CHAIN_EXCEED_SUPPORT_LEN               = -4129, /* Certificate chain exceed length of support */
    ERROR_ETSI_SEC_DECAP_PREPROCESS_FAIL                             = -4130, /* Preprocess message fail */
    ERROR_ETSI_SEC_NO_GPS                                            = -4131, /* The GPS location is not available */
    ERROR_ETSI_SEC_PKT_VER_ERR                                       = -4132, /* The packet version is wrong */
    ERROR_ETSI_SEC_PKT_CONTENT_ERR                                   = -4133, /* The packet content is wrong */
    ERROR_ETSI_SEC_GET_MATERIAL_CATALOG_ERROR                        = -4134, /* Get material catalog from libdot2 fail */
    ERROR_ETSI_SEC_DOT2_INIT_FAIL                                    = -4135, /* (dot2)Fail to init the dot2 */
    ERROR_ETSI_SEC_DOT2_EXIT_FAIL                                    = -4136, /* (dot2)Fail to exit the dot2 */
    ERROR_ETSI_SEC_DOT2_GEN_KEY_ERROR                                = -4137, /* (dot2)Fail to generate the key-pair */
    ERROR_ETSI_SEC_DOT2_GET_CERT_HASH_ERROR                          = -4138, /* (dot2)Fail to get the hashID of cert */
    ERROR_ETSI_SEC_DOT2_GET_CMH_ERROR                                = -4139, /* (dot2)Fail to get the cmh */
    ERROR_ETSI_SEC_ASN1_MEM_ERROR                                    = -4140, /* Fail to get the mem by asn1_parser */
    ERROR_ETSI_SEC_DELETE_STORED_CERT_FAIL                           = -4141, /* Delete those certificates and keys storing in libdot2 fail */
    ERROR_ETSI_SEC_ASN1_ENCODE_ERROR                                 = -4142, /* ETSI_SEC asn1 encode fail */
    ERROR_ETSI_SEC_ASN1_DECODE_ERROR                                 = -4143, /* ETSI_SEC asn1 decode fail */
    ERROR_ETSI_SEC_IMPORT_EE_CERT_AND_KEY_ERROR                      = -4144, /* Import EE certificate and keys error */
    ERROR_ETSI_SEC_SAVE_EE_CERT_AND_KEY_ERROR                        = -4145, /* Save EE certificate and keys error */
    ERROR_ETSI_SEC_DELETE_UPDATE_FOLDER_ERROR                        = -4146, /* Delete folder for updating certificates fail */
    ERROR_ETSI_SEC_MAKE_UPDATE_FOLDER_ERROR                          = -4147, /* Make Update folder fail */
    ERROR_ETSI_SEC_MAKE_UPDATE_CA_FOLDER_ERROR                       = -4148, /* Make Update CA folder fail */
    ERROR_ETSI_SEC_MAKE_UPDATE_EE_FOLDER_ERROR                       = -4149, /* Make Update EE folder fail */

    /* dsrc_security */
    ERROR_V2XSEC_INVALID_PSID                                        = -5120, /* Invalid PSID */
    ERROR_V2XSEC_DELETE_STORED_CERT_FAIL                             = -5121, /* Delete those certificates and keys storing in libdot2 fail */
    ERROR_V2XSEC_LOAD_SIGNING_PRI_KEY_FAIL                           = -5122, /* Load ECDSA signging private key fail */
    ERROR_V2XSEC_LOAD_ENCRYPT_PRI_KEY_FAIL                           = -5123, /* Load ECIES encrypt private key fail */
    ERROR_V2XSEC_CMH_EXAHSTED                                        = -5124, /* dot2 CMH has exahsted, Can't acquire cmh more */
    ERROR_V2XSEC_IMPORT_CA_CERT_ERROR                                = -5125, /* Import CA certificate error */
    ERROR_V2XSEC_SAVE_CA_CERT_ERROR                                  = -5126, /* Save CA certificate error */
    ERROR_V2XSEC_IMPORT_EE_CERT_AND_KEY_ERROR                        = -5127, /* Import EE certificate and keys error */
    ERROR_V2XSEC_SAVE_EE_CERT_AND_KEY_ERROR                          = -5128, /* Save EE certificate and keys error */
    ERROR_V2XSEC_OPEN_UPDATE_CA_DIR_ERROR                            = -5129, /* Open update CA folder fail */
    ERROR_V2XSEC_OPEN_UPDATE_EE_DIR_ERROR                            = -5130, /* Open update EE folder fail */
    ERROR_V2XSEC_SET_REPETITIVE_PSID_PROFILE_MAPPING                 = -5131, /* This PSID has been set to map other security profile */
    ERROR_V2XSEC_SEC_PROFILE_TABLE_SIZE_NOT_ENOUGH                   = -5132, /* The size of security profile table isn't enough */
    ERROR_V2XSEC_FOLDER_PATH_BUF_SIZE_NOT_ENOUGH                     = -5133, /* The size of folder path buffer isn't enough */
    ERROR_V2XSEC_UPDATE_DIR_NOT_EXIST                                = -5134, /* Update folder dosen't exist */
    ERROR_V2XSEC_CA_CERT_NOT_EXIST                                   = -5135, /* CA certificates don't exist */
    ERROR_V2XSEC_EE_CERT_NOT_EXIST                                   = -5136, /* EE certificates or keys don't exist */
    ERROR_V2XSEC_NONE_VALID_CERT                                     = -5137, /* None valid certificate */
    ERROR_V2XSEC_DELETE_CMD_BUF_SIZE_NOT_ENOUGH                      = -5138, /* The buffer size of deleted command isn't enough */
    ERROR_V2XSEC_DELETE_UPDATE_FOLDER_ERROR                          = -5139, /* Delete folder for updating certificates fail */
    ERROR_V2XSEC_MAKE_UPDATE_FOLDER_ERROR                            = -5140, /* Make Update folder fail */
    ERROR_V2XSEC_MAKE_UPDATE_CA_FOLDER_ERROR                         = -5141, /* Make Update CA folder fail */
    ERROR_V2XSEC_MAKE_UPDATE_EE_FOLDER_ERROR                         = -5142, /* Make Update EE folder fail */
    ERROR_V2XSEC_OPEN_CERT_FILE_ERROR                                = -5143, /* Open certificate file fail */
    ERROR_V2XSEC_CERT_MAPPING_TBL_SIZE_NOT_ENOUGH                    = -5144, /* The size of certificate mapping table isn't enough */
    ERROR_V2XSEC_OPEN_SECURITY_CONFIG_FILE_ERROR                     = -5145, /* Open security config file fail */
    ERROR_V2XSEC_PARSE_SECURITY_CONFIG_FILE_ERROR                    = -5146, /* Parse security config file fail */
    ERROR_V2XSEC_GET_MATERIAL_CATALOG_ERROR                          = -5147, /* Get material catalog from libdot2 fail */
    ERROR_V2XSEC_SECURITY_CONFIG_FILE_PROFILE_TYPE_ERROR             = -5148, /* The profile type of security config file is incorrect */
    ERROR_V2XSEC_SECURITY_SYS_PROFILE_NON_EXIST                      = -5149, /* This security system build-in profile doesn't exist */
    ERROR_V2XSEC_SECURITY_USR_PROFILE_NON_EXIST                      = -5150, /* This security user customzied profile doesn't exist */
    ERROR_V2XSEC_SECURITY_PROFILE_MAPPING_NON_EXIST                  = -5151, /* This security profile mapping doesn't exist */
    ERROR_V2XSEC_SECURITY_PROFILE_NOT_SUPPORT_VERIFY_SIGNED_MSG      = -5152, /* This security profile dosen't support to verify signed message */
    ERROR_V2XSEC_SECURITY_UNKNOWN_PROFILE_TYPE                       = -5153, /* This security profile type is unsuppoted */
    ERROR_V2XSEC_CONFIG_UNKNOWN_PROFILE_TYPE                         = -5154, /* This is a unknown config profile type */
    ERROR_V2XSEC_ENCAP_UNSECURE_MSG_ERROR                            = -5155, /* Encap unsecured msg fail */
    ERROR_V2XSEC_ENCAP_SIGN_MSG_ERROR                                = -5156, /* Encap signed msg fail */
    ERROR_V2XSEC_CERT_EXPIRE                                         = -5157, /* Expiry time of certificate is invalid */
    ERROR_V2XSEC_DECAP_INVALID_FMT                                   = -5158, /* Invalid ieee1609.2 format */
    ERROR_V2XSEC_DECAP_RAW_BUF_SIZE_NOT_ENOUGH                       = -5159, /* Plaintext buffer size isn't enough */
    ERROR_V2XSEC_DECAP_TOBESIGN_BUF_SIZE_NOT_ENOUGH                  = -5160, /* Internal ToBeSign buffer size isn't enough */
    ERROR_V2XSEC_DECAP_NO_CERT_OF_SIGNED_PKT                         = -5161, /* SignerID: certificate, It can't be found for this Signed pkt that is received */
    ERROR_V2XSEC_DECAP_CERT_CHAIN_EXCEED_SUPPORT_LEN                 = -5162, /* SignerID certificate chain exceed length of support */
    ERROR_V2XSEC_DECAP_MSG_PREPROCESS_FAIL                           = -5163, /* Preprocess message fail */
    ERROR_V2XSEC_DECAP_VERIFY_DATA_ERROR                             = -5164, /* Verify message fail */
    ERROR_V2XSEC_CERT_MAPPING_TBL_NON_CERT_ITEM                      = -5165, /* None certificate items of assigned psid in Certificate mapping table */
    WRONG_V2XSEC_UNSECURED_PKT                                       = -5166, /* This pkt format is an unsecured dot2 pkt */
    ERROR_V2XSEC_ENCAP_OUTPUT_BUF_SIZE_NOT_ENOUGH                    = -5167, /* The output msg buffer is not enough for encapsulated SPDU */
    ERROR_V2XSEC_LOAD_EE_MATERIAL_ERROR                              = -5168, /* Load EE cert and keys into dot2 CMH error */
    ERROR_V2XSEC_CERT_APP_PERMISSION_NOT_SUPPORT                     = -5169, /* EE cert doesn't support this specific APP permission */
    ERROR_V2XSEC_DECAP_UNEXPECTED_ERROR                              = -5170, /* Decap msg unexpected error */
    ERROR_V2XSEC_ENCAP_CERT_CHANGE_FAIL                              = -5171, /* Change EE certificate fail */
    ERROR_V2XSEC_SEC_CFG_GET                                         = -5172, /* Get sec configuration data fail */
    ERROR_V2XSEC_UNEXPECT_CLASS                                      = -5173, /* This kind of psids in certificate is not listed in cfg file */

    /* v2xcast */

    ERROR_V2XCAST_UNKNOWN                                            = -6145, /* Unknown error */
    ERROR_V2XCAST_CASTER_CREATE_HAS_BEEN_INIT                        = -6146, /* Caster has been initialized */
    ERROR_V2XCAST_CASTER_MONITOR_THRD_CREATE_FAIL                    = -6147, /* Caster monitor thread creation failed */
    ERROR_V2XCAST_CASTER_CREATE_CONTEXT_FAIL                         = -6148, /* Caster context creation failed */
    ERROR_V2XCAST_CASTER_CREATE_HAS_BEEN_DEINIT                      = -6149, /* Caster has been deinitialized */
    ERROR_V2XCAST_CASTER_TERMINATE_CONTEXT_FAIL                      = -6150, /* Caster context termination failed */
    ERROR_V2XCAST_CASTER_SECURITY_KEY_GEN_FAIL                       = -6151, /* Caster security key generation failed */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_COMMON_CONFIG_INVALID           = -6152, /* Caster create fail due to invalid common config */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_IP_CONFIG_INVALID               = -6153, /* Caster create fail due to invalid IP config */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_CASTER_NUMBER_OVER_LIMIT        = -6154, /* Caster create fail due to caster number over limit */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_SETUP_SIGNAL_FAIL               = -6155, /* Caster create fail due to setup signal fail */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_V2XCAST_SERVICE_NOT_AVAILABLE   = -6156, /* Caster create fail due to V2Xcast service is not available */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_TX_SESSION_CREATE_FAIL          = -6157, /* Caster create fail due to TX session create fail */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_RX_SESSION_CREATE_FAIL          = -6158, /* Caster create fail due to RX session create fail */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_SPLMNT_SESSION_CREATE_FAIL      = -6159, /* Caster create fail due to SPLMNT session create fail */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_POTI_DATA_SESSION_CREATE_FAIL   = -6160, /* Caster create fail due to POTI DATA session create fail */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_POTI_INFO_SESSION_CREATE_FAIL   = -6161, /* Caster create fail due to POTI INFO session create fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_CASTER_NOT_EXIST                    = -6162, /* Caster TX fail due to caster not exist */
    ERROR_V2XCAST_CASTER_TX_FAIL_THREAD_ID_MISMTACH                  = -6163, /* Caster TX fail due to thread id mismatch between caster create caller and caster tx caller */
    ERROR_V2XCAST_CASTER_TX_FAIL_COMMUNICATION_MODE_MISMTACH         = -6164, /* Caster TX fail due to communication mode mismatch between requested caster and configured caster */
    ERROR_V2XCAST_CASTER_TX_FAIL_SESSION_CREATE_FAIL                 = -6165, /* Caster TX fail due to session create fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_TX_REQ_CARRIER_ALLOC_FAIL           = -6166, /* Caster TX fail due to TX REQ carrier allocate fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_TX_REQ_CARRIER_ENCODE_FAIL          = -6167, /* Caster TX fail due to TX REQ carrier encode fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_TX_REQ_SEND_FAIL                    = -6168, /* Caster TX fail due to TX REQ send fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_TX_RSP_RECEIVE_FAIL                 = -6169, /* Caster TX fail due to TX RSP receive fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_TX_RSP_CARRIER_DECODE_FAIL          = -6170, /* Caster TX fail due to TX RSP carrier decode fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_PACKET_OVERLOAD                     = -6171, /* Caster TX fail due to packet overload, please allocate smaller packet (<= 1500) */
    ERROR_V2XCAST_CASTER_RX_FAIL                                     = -6172, /* Caster RX fail */
    ERROR_V2XCAST_CASTER_RX_TIMEOUT                                  = -6173, /* Caster RX timeout */
    ERROR_V2XCAST_CASTER_RX_FAIL_CASTER_NOT_EXIST                    = -6174, /* Caster RX fail due to caster not exist */
    ERROR_V2XCAST_CASTER_RX_FAIL_THREAD_ID_MISMTACH                  = -6175, /* Caster RX fail due to thread id mismatch between caster create caller and caster rx caller */
    ERROR_V2XCAST_CASTER_RX_FAIL_COMMUNICATION_MODE_MISMTACH         = -6176, /* Caster RX fail due to communication mode mismatch between requested caster and configured caster */
    ERROR_V2XCAST_CASTER_RX_FAIL_RX_SUB_RECV_FAIL                    = -6177, /* Caster RX fail due to RX SUB receive fail */
    ERROR_V2XCAST_CASTER_RX_FAIL_RX_SUB_CARRIER_DECODE_FAIL          = -6178, /* Caster RX fail due to RX SUB decode fail */
    ERROR_V2XCAST_CASTER_RX_FAIL_INSUFFICIENT_BUFFER                 = -6179, /* Caster RX fail due to insufficient buffer, please allocate larger buffer (>= 1500) */
    ERROR_V2XCAST_CASTER_RX_SUBSCRIBLE_FAIL_INVALID_ENDPOINT_ID_TYPE = -6180, /* Caster RX subscrible fail due to invalid endpoint ID type */
    ERROR_V2XCAST_CASTER_RX_SUBSCRIBLE_FAIL_UNREACHABLE_ENDPOINT     = -6181, /* Caster RX subscrible fail due to unreachable endpoint */
    ERROR_V2XCAST_CASTER_RX_UNSUBSCRIBLE_FAIL_INVALID_ENDPOINT_ID_TYPE = -6182, /* Caster RX unsubscrible fail due to invalid endpoint ID type */
    ERROR_V2XCAST_CASTER_RX_UNSUBSCRIBLE_FAIL_UNREACHABLE_ENDPOINT   = -6183, /* Caster RX unsubscrible fail due to unreachable endpoint */
    ERROR_V2XCAST_CASTER_SPLMNT_FAIL_CASTER_NOT_EXIST                = -6184, /* Caster SPLMNT fail due to caster not exist */
    ERROR_V2XCAST_CASTER_SPLMNT_FAIL_COMMUNICATION_MODE_MISMTACH     = -6185, /* Caster SPLMNT fail due to communication mode mismatch between requested caster and configured caster */
    ERROR_V2XCAST_CASTER_SPLMNT_FAIL_THREAD_ID_MISMTACH              = -6186, /* Caster SPLMNT fail due to thread id mismatch between caster create caller and caster splmnt caller */
    ERROR_V2XCAST_CASTER_SPLMNT_FAIL_SPLMNT_REQ_CARRIER_ALLOC_FAIL   = -6187, /* Caster SPLMNT fail due to SPLMNT REQ carrier allocate fail */
    ERROR_V2XCAST_CASTER_SPLMNT_FAIL_SPLMNT_REQ_CARRIER_ENCODE_FAIL  = -6188, /* Caster SPLMNT fail due to SPLMNT REQ carrier encode fail */
    ERROR_V2XCAST_CASTER_SPLMNT_REQ_SEND_FAIL                        = -6189, /* Caster SPLMNT fail due to SPLMNT REQ send fail */
    ERROR_V2XCAST_CASTER_SPLMNT_RSP_RECEIVE_FAIL                     = -6190, /* Caster SPLMNT fail due to SPLMNT RSP receive fail */
    ERROR_V2XCAST_CASTER_SPLMNT_FAIL_SPLMNT_RSP_CARRIER_DECODE_FAIL  = -6191, /* Caster SPLMNT fail due to SPLMNT RSP carrier decode fail */
    ERROR_V2XCAST_CASTER_POTI_DATA_FAIL_CASTER_NOT_EXIST             = -6192, /* Caster POTI_DATA fail due to caster not exist */
    ERROR_V2XCAST_CASTER_POTI_DATA_FAIL_COMMUNICATION_MODE_MISMTACH  = -6193, /* Caster POTI_DATA fail due to communication mode mismatch between requested caster and configured caster */
    ERROR_V2XCAST_CASTER_POTI_DATA_FAIL_THREAD_ID_MISMTACH           = -6194, /* Caster POTI_DATA fail due to thread id mismatch between caster create caller and caster rx caller */
    ERROR_V2XCAST_CASTER_POTI_DATA_FAIL_POTI_DATA_SUB_RECV_FAIL      = -6195, /* Caster POTI_DATA fail due to POTI_DATA SUB receive fail */
    ERROR_V2XCAST_CASTER_POTI_DATA_FAIL_POTI_DATA_SUB_CARRIER_DECODE_FAIL = -6196, /* Caster POTI_DATA fail due to POTI_DATA SUB decode fail */
    ERROR_V2XCAST_CASTER_POTI_INFO_FAIL_CASTER_NOT_EXIST             = -6197, /* Caster POTI_INFO fail due to caster not exist */
    ERROR_V2XCAST_CASTER_POTI_INFO_FAIL_COMMUNICATION_MODE_MISMTACH  = -6198, /* Caster POTI_INFO fail due to communication mode mismatch between requested caster and configured caster */
    ERROR_V2XCAST_CASTER_POTI_INFO_FAIL_THREAD_ID_MISMTACH           = -6199, /* Caster POTI_INFO fail due to thread id mismatch between caster create caller and caster splmnt caller */
    ERROR_V2XCAST_CASTER_POTI_INFO_FAIL_POTI_INFO_REQ_CARRIER_ALLOC_FAIL = -6200, /* Caster POTI_INFO fail due to POTI_INFO REQ carrier allocate fail */
    ERROR_V2XCAST_CASTER_POTI_INFO_FAIL_POTI_INFO_REQ_CARRIER_ENCODE_FAIL = -6201, /* Caster POTI_INFO fail due to POTI_INFO REQ carrier encode fail */
    ERROR_V2XCAST_CASTER_POTI_INFO_REQ_SEND_FAIL                     = -6202, /* Caster POTI_INFO fail due to POTI_INFO REQ send fail */
    ERROR_V2XCAST_CASTER_POTI_INFO_RSP_RECEIVE_FAIL                  = -6203, /* Caster POTI_INFO fail due to POTI_INFO RSP receive fail */
    ERROR_V2XCAST_CASTER_POTI_INFO_FAIL_POTI_INFO_RSP_CARRIER_DECODE_FAIL = -6204, /* Caster POTI_INFO fail due to POTI_INFO RSP carrier decode fail */
    ERROR_V2XCAST_CASTER_RELEASE_FAIL_CASTER_NOT_EXIST               = -6205, /* Caster release fail due to caster not exist */
    ERROR_V2XCAST_CASTER_RELEASE_FAIL_THREAD_ID_MISMTACH             = -6206, /* Caster release fail due to thread id mismatch between caster create caller and caster release caller */
    ERROR_V2XCAST_SERVICE_BTP_INIT_FAIL_BTP_TYPE_INVALID             = -6207, /* Service BTP create fail due to invalid BTP type */
    ERROR_V2XCAST_SERVICE_SECURITY_KEY_INIT_FAIL                     = -6208, /* Service security key init failed */
    ERROR_V2XCAST_SERVICE_SECURITY_KEY_INVALID                       = -6209, /* Service security key invalid */
    ERROR_V2XCAST_SERVICE_SECURITY_KEY_INSTALL_FAIL                  = -6210, /* Service security key install failed */
    ERROR_V2XCAST_SERVICE_TX_THREAD_CREATE_FAIL                      = -6211, /* Service TX thread create fail */
    ERROR_V2XCAST_SERVICE_TX_SESSION_CREATE_FAIL                     = -6212, /* Service TX session create fail */
    ERROR_V2XCAST_SERVICE_TX_REQ_RECEIVE_FAIL                        = -6213, /* Service TX REQ receive fail */
    ERROR_V2XCAST_SERVICE_TX_REQ_NOT_CARRIER_MODE                    = -6214, /* Service TX REQ is not carrier mode */
    ERROR_V2XCAST_SERVICE_TX_REQ_CARRIER_DECODE_FAIL                 = -6215, /* Service TX REQ carrier decode fail */
    ERROR_V2XCAST_SERVICE_TX_RSP_CARRIER_ALLOC_FAIL                  = -6216, /* Service TX RSP carrier allocate fail */
    ERROR_V2XCAST_SERVICE_TX_RSP_CARRIER_ENCODE_FAIL                 = -6217, /* Service TX RSP carrier encode fail */
    ERROR_V2XCAST_SERVICE_TX_RSP_SEND_FAIL                           = -6218, /* Service TX RSP send fail */
    ERROR_V2XCAST_SERVICE_RX_THREAD_CREATE_FAIL                      = -6219, /* Service RX thread create fail */
    ERROR_V2XCAST_SERVICE_RX_SESSION_CREATE_FAIL                     = -6220, /* Service RX session create fail */
    ERROR_V2XCAST_SERVICE_RX_PUB_CARRIER_ALLOC_FAIL                  = -6221, /* Service RX PUB carrier allocate fail */
    ERROR_V2XCAST_SERVICE_RX_PUB_CARRIER_ENCODE_FAIL                 = -6222, /* Service RX PUB carrier encode fail */
    ERROR_V2XCAST_SERVICE_RX_PUB_SEND_FAIL                           = -6223, /* Service RX PUB send fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_THREAD_CREATE_FAIL                  = -6224, /* Service SPLMNT thread create fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_SESSION_CREATE_FAIL                 = -6225, /* Service SPLMNT session create fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_REQ_RECEIVE_FAIL                    = -6226, /* Service SPLMNT REQ receive fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_REQ_CARRIER_DECODE_FAIL             = -6227, /* Service SPLMNT REQ carrier decode fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_RSP_CARRIER_ALLOC_FAIL              = -6228, /* Service SPLMNT RSP carrier allocate fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_RSP_CARRIER_ENCODE_FAIL             = -6229, /* Service SPLMNT RSP carrier encode fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_RSP_SEND_FAIL                       = -6230, /* Service SPLMNT RSP send fail */
    ERROR_V2XCAST_SERVICE_POTI_DATA_THREAD_CREATE_FAIL               = -6231, /* Service POTI_DATA thread create fail */
    ERROR_V2XCAST_SERVICE_POTI_DATA_SESSION_CREATE_FAIL              = -6232, /* Service POTI_DATA session create fail */
    ERROR_V2XCAST_SERVICE_POTI_DATA_PUB_CARRIER_ALLOC_FAIL           = -6233, /* Service POTI_DATA PUB carrier allocate fail */
    ERROR_V2XCAST_SERVICE_POTI_DATA_PUB_CARRIER_ENCODE_FAIL          = -6234, /* Service POTI_DATA PUB carrier encode fail */
    ERROR_V2XCAST_SERVICE_POTI_DATA_PUB_SEND_FAIL                    = -6235, /* Service POTI_DATA PUB send fail */
    ERROR_V2XCAST_SERVICE_POTI_INFO_THREAD_CREATE_FAIL               = -6236, /* Service POTI_INFO thread create fail */
    ERROR_V2XCAST_SERVICE_POTI_INFO_SESSION_CREATE_FAIL              = -6237, /* Service POTI_INFO session create fail */
    ERROR_V2XCAST_SERVICE_POTI_INFO_REQ_RECEIVE_FAIL                 = -6238, /* Service POTI_INFO REQ receive fail */
    ERROR_V2XCAST_SERVICE_POTI_INFO_REQ_CARRIER_DECODE_FAIL          = -6239, /* Service POTI_INFO REQ carrier decode fail */
    ERROR_V2XCAST_SERVICE_POTI_INFO_RSP_CARRIER_ALLOC_FAIL           = -6240, /* Service POTI_INFO RSP carrier allocate fail */
    ERROR_V2XCAST_SERVICE_POTI_INFO_RSP_CARRIER_ENCODE_FAIL          = -6241, /* Service POTI_INFO RSP carrier encode fail */
    ERROR_V2XCAST_SERVICE_POTI_INFO_RSP_SEND_FAIL                    = -6242, /* Service POTI_INFO RSP send fail */

    /* dot2 */
    ERROR_DOT2_FOLDER_CREATE_ERROR                                   = -7168, /* Create dot2 internal folder fail */
    ERROR_DOT2_CATALOG_DB_ACCESS_ERROR                               = -7169, /* Access dot2 database error */
    ERROR_DOT2_PARSE_SDEE_FAIL                                       = -7170, /* Parse SDEE fail (None exist in sec config) */
    ERROR_DOT2_EXPORT_FAIL                                           = -7171, /* Export DB to human-readable table failed */
    ERROR_DOT2_DB_API_OPERATE_ERROR                                  = -7172, /* Operate apis of database error (None exist db of the sdee name) */
    ERROR_DOT2_OPEN_SECURE_MATERIAL_ERROR                            = -7173, /* Open secure material error */
    ERROR_DOT2_DELETE_SECURE_MATERIAL_ERROR                          = -7174, /* Delete secure material error */
    ERROR_DOT2_WRITE_SECURE_MATERIAL_ERROR                           = -7175, /* WRITE secure material error */
    ERROR_DOT2_READ_SECURE_MATERIAL_ERROR                            = -7176, /* READ secure material error */
    ERROR_DOT2_NON_EXIST_SECURE_MATERIAL                             = -7177, /* None secure material */
    ERROR_DOT2_HSM_MATERIAL_WRITE_ERROR                              = -7178, /* Write HSM material error */
    ERROR_DOT2_HSM_MATERIAL_READ_ERROR                               = -7179, /* Read HSM material error */
    ERROR_DOT2_HSM_MATERIAL_DELETE_ERROR                             = -7180, /* Delete HSM material error */
    ERROR_DOT2_MATERIAL_IS_EXISTED_IN_DB                             = -7181, /* This material has been existed in database */
    ERROR_DOT2_DB_NAME_OF_UNIQUE_KEY_GET_ERROR                       = -7182, /* Get name of unique key of database error */
    ERROR_DOT2_PARSE_CERT_FAIL                                       = -7183, /* Parse certificate failed */
    ERROR_DOT2_RECONSTRUCT_PUBLIC_KEY_ERROR                          = -7184, /* Reconstrct public key error */
    ERROR_DOT2_RECONSTRUCT_PRIVATE_KEY_ERROR                         = -7185, /* Reconstrct private key error */
    ERROR_DOT2_KEYPAIR_NOT_MATCH                                     = -7186, /* The private key and corresponding public key , they don't match */
    ERROR_DOT2_GET_MATCHABLE_PUBKEY_FAIL                             = -7187, /* Get the corresponding matchable public key fail */
    ERROR_DOT2_SIGNER_CERT_CHAIN_OVER_SUPPORTED_LENGTH               = -7188, /* Length of signer certificate chain over supported lengh */
    ERROR_DOT2_ASN1_ENCODE_ERROR                                     = -7189, /* DOT2 asn1 encode fail */
    ERROR_DOT2_ASN1_DECODE_ERROR                                     = -7190, /* DOT2 asn1 decode fail */
    ERROR_DOT2_TOBESIGN_DATA_EXCEED_BUF_SIZE                         = -7191, /* The length of tobesign data exceeds buffer size */
    ERROR_DOT2_CERT_LENGTH_EXCEED_BUF_SIZE                           = -7192, /* The length of certificate exceeds buffer size */
    ERROR_DOT2_UNSECURED_DATA_EXCEED_BUF_SIZE                        = -7193, /* The length of unsecured data exceeds buffer size */
    ERROR_DOT2_SIGNED_DATA_EXCEED_BUF_SIZE                           = -7194, /* The length of signed data exceeds buffer size */
    ERROR_DOT2_ENCRYPTED_DATA_EXCEED_BUF_SIZE                        = -7195, /* The length of encrypted data exceeds buffer size */
    ERROR_DOT2_DECRYPTED_DATA_EXCEED_BUF_SIZE                        = -7196, /* The length of decrypted data exceeds buffer size */
    ERROR_DOT2_UNSUPPORT_RECIPIENTINFO_TYPE                          = -7197, /* Currently, unsupport this recipientinfo type */
    ERROR_DOT2_GET_CERT_RECIPIENTINFO_FAIL                           = -7198, /* Get the certificate recipientinfo fail, it didn't be loaded into CMH */
    ERROR_DOT2_SPDU_SIGNER_CERT_NUM_EXCEED_LIMIT                     = -7199, /* Number of signer ceritifcate of SPDU exceeds limited number */
    ERROR_DOT2_RECONSTRUCT_PRIVKEY_FAIL                              = -7200, /* Reconstruct privkey fail */
    ERROR_DOT2_RECONSTRUCT_PUBKEY_FAIL                               = -7201, /* Reconstruct pubkey fail */
    ERROR_DOT2_NO_RECIPIENT_INFO                                     = -7202, /* No corresponding recipient info */
    ERROR_DOT2_NO_CERT_OF_SIGNED_PKT                                 = -7203, /* No corresponding certificate for this signed packet */
    ERROR_DOT2_GET_CERT_SSP_FAIL                                     = -7204, /* Get SSP of certificate fail */
    ERROR_DOT2_GET_CERT_APP_PERMISSION_FAIL                          = -7205, /* Get app permission of certificate fail */
    ERROR_DOT2_GET_CERT_ISSUE_PERMISSION_FAIL                        = -7206, /* Get issue permission of certificate fail */
    ERROR_DOT2_HSM_INIT_FAIL                                         = -7207, /* Initialize HSM fail */
    ERROR_DOT2_GPS_INIT_FAIL                                         = -7208, /* Initialize GPS fail */
    ERROR_DOT2_VERIFY_MSG_FAIL                                       = -7209, /* Verify message fail */
    ERROR_DOT2_HASH_MSG_FAIL                                         = -7210, /* Hash message fail */
    ERROR_DOT2_SIGN_MSG_FAIL                                         = -7211, /* Sign message fail */
    ERROR_DOT2_ENCRYPT_MSG_FAIL                                      = -7212, /* Encrypt message fail */
    ERROR_DOT2_DECRYPT_MSG_FAIL                                      = -7213, /* Decrypt message fail */
    ERROR_DOT2_GEN_ENCRYPTED_ENCRYPTION_KEY_FAIL                     = -7214, /* Generate encrypted encryption key fail */
    ERROR_DOT2_ECC_COMPRESS_FAIL                                     = -7215, /* ECC compress fail */
    ERROR_DOT2_ECC_DECOMPRESS_FAIL                                   = -7216, /* ECC decompress fail */
    ERROR_DOT2_CREATE_ECC_PRIVKEY_FAIL                               = -7217, /* Create ECC private key fail */
    ERROR_DOT2_IMPORT_HSM_ECC_PRIVKEY_FAIL                           = -7218, /* Import HSM ECC private key fail */
    ERROR_DOT2_DELETE_HSM_ECC_PRIVKEY_FAIL                           = -7219, /* Delete HSM ECC private key fail */
    ERROR_DOT2_GET_HSM_ECC_PUBKEY_FAIL                               = -7220, /* Get HSM ECC public key fail */
    ERROR_DOT2_GEN_RAND_DATA_FAIL                                    = -7221, /* Generate random data fail */
    ERROR_DOT2_DECRYPT_ENCRYPTION_KEY_FAIL                           = -7222, /* Decrypt encrypted encryption key fail */
    ERROR_DOT2_PUB_CMH_NO_SIGNER_CERT                                = -7223, /* No signer cert in public CMH hdl */
    ERROR_DOT2_SAVE_PUBLIC_CERT_FAIL                                 = -7224, /* Import cert in public CMH hdl fail */
    ERROR_DOT2_KICK_OFF_PUBLIC_CERT                                  = -7225, /* Kick off cert in CMH hdl */
    ERROR_DOT2_CMH_NOT_IN_CORRECT_STATUS                             = -7226, /* CMH handler isn't in correct status */
    ERROR_DOT2_CMH_NO_PRIVATE_SEED                                   = -7227, /* Can't find private seed that can be used to reconstruct private key in CMH Handler */
    ERROR_DOT2_REQUEST_CMH_HANDLER_FAIL                              = -7228, /* Request a avaliable CMH hdl fail */
    ERROR_DOT2_RELEASE_CMH_HANDLER_FAIL                              = -7229, /* Release a avaliable CMH hdl error */
    ERROR_DOT2_GET_CMH_PRIVKEY_IDX_FAIL                              = -7230, /* Get privkey idx in CMH hdl fail */
    ERROR_DOT2_GET_CMH_CERT_HASH_FAIL                                = -7231, /* Get hash of cert in CMH hdl fail */
    ERROR_DOT2_GET_CMH_CERT_DATA_FAIL                                = -7232, /* Get data of cert in CMH hdl fail */
    ERROR_DOT2_GET_CMH_ECC_CURVE_FAIL                                = -7233, /* Get ecc curve in CMH hdl fail */
    ERROR_DOT2_GET_CMH_SIGNER_CERT_FAIL                              = -7234, /* Get signer cert in CMH hdl fail */
    ERROR_DOT2_SKH_NOT_IN_CORRECT_STATUS                             = -7235, /* symmetric key handler isn't in correct status */
    ERROR_DOT2_REQUEST_SKH_HANDLER_FAIL                              = -7236, /* Request a avaliable symmetric key handler fail */
    ERROR_DOT2_RELEASE_SKH_HANDLER_FAIL                              = -7237, /* Release a avaliable symmetric key handler error */
    ERROR_DOT2_REPLAYED_MSG                                          = -7238, /* That is a replayed message */
    ERROR_DOT2_GET_GPS_DATA_FAIL                                     = -7239, /* Get GPS data fail */
    ERROR_DOT2_CALC_DISTANCE_FAIL                                    = -7240, /* Calculate Distance fail */
    ERROR_DOT2_INVALID_DISTANCE                                      = -7241, /* The distance of location is invalid  */
    ERROR_DOT2_MSG_PSID_INCONSISTENT_WITH_CERT                       = -7242, /* PSIDs of SPDU are inconsistent with PSIDs of certificate */
    ERROR_DOT2_CERT_ISSUE_PERMISSION_INCONSISTENT_WITH_SIGNER_CERT   = -7243, /* Issue permission of certificate is inconsistent with signer certificate */
    ERROR_DOT2_CERT_IN_INVALID_REGION                                = -7244, /* The ceritificate is invalid in current region */
    ERROR_DOT2_MSG_EXPIRE_TIME_LATER_THAN_CERT                       = -7245, /* The expire data of message is later than certificate */
    ERROR_DOT2_MSG_EXPIRE_TIME_EARLIER_THAN_CERT                     = -7246, /* The expire data of message is earlier than certificate */
    ERROR_DOT2_CERT_IS_EXPIRED_COMPARE_TO_THE_MSG                    = -7247, /* Comparing to signed message, the certificate is expired */
    ERROR_DOT2_MSG_IS_EXPIRED_COMPARE_TO_THE_CERT                    = -7248, /* Comparing to certificate, the message is expired */
    ERROR_DOT2_MSG_IS_EXPIRED_COMPARE_TO_CURR_TIME                   = -7249, /* Comparing to current time, the signed message is expired */
    ERROR_DOT2_MSG_NO_AVALIABLE_LOC_DATA                             = -7250, /* The location of message is invalid */
    ERROR_DOT2_INVALID_MSG_GEN_TIME                                  = -7251, /* The generation time of message is invalid */
    ERROR_DOT2_INVALID_MSG_EXPIRE_TIME                               = -7252, /* The expire time of message is invalid */
    ERROR_DOT2_INCOMPLETE_CERT_CHAIN                                 = -7253, /* Incomplete certificate chain for verification */
    ERROR_DOT2_CERT_EXPIRE_TIME_LATER_THAN_SIGNER_CERT               = -7254, /* The expire time of certificate is later than signer cerificate */
    ERROR_DOT2_CERT_EXPIRE_TIME_EARLIER_THAN_SIGNER_CERT             = -7255, /* The expire time of certificate is earlier than signer cerificate */
    ERROR_DOT2_SIGNED_CERT_REQ_DATA_EXCEED_BUF_SIZE                  = -7256, /* The length of signedCertificateRequest data exceeds buffer size */
    ERROR_DOT2_MATERIAL_HAS_BEEN_LOADED_INTO_HANDLER                 = -7257, /* This material has been loaded into handler */
    ERROR_DOT2_GET_PSK_RECIPIENTINFO_FAIL                            = -7258, /* Get the preShareKey recipientinfo fail, it didn't be loaded into SCMH */
    ERROR_DOT2_CERT_IS_EXPIRED                                       = -7259, /* the certificate is expired */
    ERROR_DOT2_SSP_PERMISSION_DENIED                                 = -7260, /* Service Specific Permission denied */
    ERROR_DOT2_TEST_FAIL                                             = -7261, /* Test failed */
    ERROR_DOT2_DUPLICATE_ECC_PRIVKEY_FAIL                            = -7262, /* Duplicate ECC private key failed */
    ERROR_DOT2_HMAC_MSG_FAIL                                         = -7263, /* HMAC failed */
    ERROR_DOT2_EXPANSION_COMPUTE_FAIL                                = -7264, /* Compute butterfly expansion failed */
    ERROR_DOT2_COMPUTE_COCOON_PRIVKEY_FAIL                           = -7265, /* Compute cocoon private key failed */
    ERROR_DOT2_GET_REK_RECIPIENTINFO_FAIL                            = -7266, /* Get the response enc key recipientinfo fail, it didn't be loaded into CMH */
    ERROR_DOT2_VERIFY_PUB_EE_SIG_FAIL                                = -7267, /* Verify public ee signature fail */
    ERROR_DOT2_COMPUTE_BUTTERFLY_PRIVKEY_FAIL                        = -7268, /* Compute butterfly private key failed */
    ERROR_DOT2_NO_TRUST_ANCHOR                                       = -7269, /* No trust anchor */
    ERROR_DOT2_CHAIN_TOO_LONG_FOR_IMPLEMENTATION                     = -7270, /* Certifcate chain too long for implementation */
    ERROR_DOT2_NOT_CRYPTOGRAPHICALLY_VALID                           = -7271, /* Not cryptographically valid */
    ERROR_DOT2_UNKNOWN_CRYPTOGRAPHICALLY_VALID                       = -7272, /* Unknown cryptographically valid */

    ERROR_DOT2_INCONSISTENT_PERMISSIONS_IN_CHAIN                     = -7274, /* Inconsistent permission in chain */
    ERROR_DOT2_REVOKED                                               = -7275, /* Certificate revoked */
    ERROR_DOT2_DUBIOUS                                               = -7276, /* certificate dubious */
    ERROR_DOT2_UNSUPPORTED_CRITICAL_INFORMATION_FIELDS               = -7277, /* Unsupported critical information fields */
    ERROR_DOT2_INVALID_ENCODING                                      = -7278, /* Invalid encoding */
    ERROR_DOT2_INVALID_INPUT                                         = -7279, /* Invalid input */
    ERROR_DOT2_CERTIFICATE_DID_NOT_VERIFY                            = -7280, /* Certificate did not verify */
    ERROR_DOT2_UNRECOGNIZED_IDENTIFIER                               = -7281, /* Unrecognized identifier */
    ERROR_DOT2_EXPIRED                                               = -7282, /* Certificate expired */
    ERROR_DOT2_NOT_ISSUED_YET                                        = -7283, /* Not issued yet */
    ERROR_DOT2_MISSING                                               = -7284, /* Missing */
    ERROR_DOT2_REPLAY                                                = -7285, /* Message replay */

    /* v2xcastd */
    ERROR_V2XCASTD_NULL_PARAM                                        = -8192, /* Parameter is NULL */
    ERROR_V2XCASTD_TOO_MUCH_PARAM                                    = -8193, /* Too much parameters in URI */
    ERROR_V2XCASTD_TOO_LONG_QUERY_STR_INVALID                        = -8194, /* Too long query string of sdee name */
    ERROR_V2XCASTD_MISS_SDEE_STR                                     = -8195, /* Miss SDEE string */
    ERROR_V2XCASTD_FILE_OPEN_FAIL                                    = -8196, /* Resource file open fail */
    ERROR_V2XCASTD_START_END_UPLD_QUERY_STR_INVALID                  = -8197, /* Invalid query string of start/end upload */
    ERROR_V2XCASTD_READ_UPLD_STATUS_FAIL                             = -8198, /* Read uploading status fail */
    ERROR_V2XCASTD_WRITE_UPLD_STATUS_FAIL                            = -8199, /* Write uploading status fail */
    WRONG_V2XCASTD_UPLD_STATUS_INSTALL_MATERIAL                      = -8200, /* Upload status: Not installing status, please upload again */
    WRONG_V2XCASTD_UPLD_STATUS_NOT_UPLOADING                         = -8201, /* Upload status: Not uploading status, please upload again */
    ERROR_V2XCASTD_WRITE_MATERIAL_FAIL                               = -8202, /* Write material fail */
    ERROR_V2XCASTD_GET_UPLD_FOLDER_PATH_FAIL                         = -8203, /* Get folder path of uploaded material fail */
    ERROR_V2XCASTD_INIT_UPLD_STATUS_FAIL                             = -8204, /* Init status of uploading fail */
    ERROR_V2XCASTD_INIT_UPLD_FOLDER_FAIL                             = -8205, /* Init folder of uploading fail */
    ERROR_V2XCASTD_SECURITY_DISABLE                                  = -8206, /* V2Xcast security is disable */
    ERROR_V2XCASTD_EMPTY_CONTENT                                     = -8207, /* Upload content have to contain data */
    ERROR_V2XCASTD_REBOOT_DEVICE_FAIL                                = -8208, /* Device reboot fail (need to reboot) */
    ERROR_V2XCASTD_COAP_API_ERROR                                    = -8209, /* V2Xcast Daemon internal api operation fail */
    ERROR_V2XCASTD_SYSTEM_COMMAND_FAIL                               = -8210, /* System command operation fail */
    ERROR_V2XCASTD_INTERNAL_OPERATION_FAIL                           = -8211, /* V2Xcast Daemon internal operation fail */
    ERROR_V2XCASTD_SEC_KEY_LENGTH                                    = -8212, /* Caster security key length fail */
    ERROR_V2XCASTD_SEC_KEY_FORMAT_FAIL                               = -8213, /* Caster security key format fail */
    ERROR_V2XCASTD_SEC_KEY_DAMAGED_FAIL                              = -8214, /* Caster security key had damaged, please upload new key or delete the key */
    ERROR_V2XCASTD_SECURITY_KEY_GENERATION_FAIL                      = -8215, /* Caster security key generation fail */

    /* scms_client */
    ERROR_SCMS_ASN_ENCODE_FAIL                                       = -9216, /* SCMS ans.1 msg encode fail */
    ERROR_SCMS_ASN_DECODE_FAIL                                       = -9217, /* SCMS ans.1 msg decode fail */
    ERROR_SCMS_MSG_BUF_NOT_ENOUGH                                    = -9218, /* Buffer size of cert request msg isn't enough */
    ERROR_SCMS_HTTP_POST_FAIL                                        = -9219, /* HTTP POST fail */
    ERROR_SCMS_HTTP_GET_FAIL                                         = -9220, /* HTTP GET fail */
    WRONG_SCMS_HTTP_GET_FILE_NOT_MODIFIED                            = -9221, /* This file isn't modified */
    ERROR_SCMS_CFG_OPEN_FAIL                                         = -9222, /* Open scms config fail */
    ERROR_SCMS_CFG_PARSE_FAIL                                        = -9223, /* Parse scms client json config fail */
    ERROR_SCMS_CFG_FORMAT_ERROR                                      = -9224, /* Format of scms config error */
    ERROR_SCMS_OPEN_SECURE_MATERIAL_ERROR                            = -9225, /* Open material error */
    WRONG_SCMS_CLIENT_IS_NOT_ENABLED                                 = -9226, /* SCMS client isn't enabled */
    ERROR_SCMS_NO_CERT                                               = -9227, /* NO certificate exist */

    /* CCMS */
    ERROR_CCMS_ASN1_ENCODE_ERROR                                     = -10240, /* CCMS ASN.1 msg encode fail */
    ERROR_CCMS_ASN1_DECODE_ERROR                                     = -10241, /* CCMS ASN.1 msg decode fail */
    WRONG_CCMS_AT_REQUEST_DISABLE                                    = -10242, /* CCMS AT Request disable */

    /* UCRYPT */
    UCRYPT_GEN_KEY_ERROR                                             = -11264, /* Generate ecc keypair failed */
    UCRYPT_IMPORT_KEY_ERROR                                          = -11265, /* Import ecc private key failed */
    UCRYPT_MULTIPLY_AND_ADD_IN_RING_ERROR                            = -11266, /* Perform the multiply and add in ring failed */
    UCRYPT_MULTIPLY_AND_ADD_IN_ELLIPTIC_GROUP_ERROR                  = -11267, /* Perform the multiply and add in the group of points of elliptic curve failed */
    UCRYPT_HASH_COMP_ERROR                                           = -11268, /* Perform hash computation falied */
    UCRYPT_HMAC_MSG_ERROR                                            = -11269, /* Perform hmac sha256 computation falied */
    UCRYPT_RNG_ERROR                                                 = -11270, /* Random number generator generate number failed */
    UCRYPT_ECDSA_SIGN_ERROR                                          = -11271, /* Generate ECDSA signature failed */
    UCRYPT_ECDSA_VERIFY_ERROR                                        = -11272, /* Verify ECDSA signature failed */
    UCRYPT_ECIES_KEY_GEN_ERRPR                                       = -11273, /* ECIES key generation failed */
    UCRYPT_ECIES_ENCRYPT_ERRPR                                       = -11274, /* ECIES encrypt failed */
    UCRYPT_ECIES_KEY_DRIVE_ERROR                                     = -11275, /* ECIES key derive failed */
    UCRYPT_ECIES_DECRYPT_ERRPR                                       = -11276, /* ECIES decrypt failed */
    UCRYPT_AES_ENCRYPT_ERROR                                         = -11277, /* AES encrypt failed */
    UCRYPT_AES_DECRYPT_ERROR                                         = -11278, /* AES decrypt failed */
    UCRYPT_LIB_INIT_ERROR                                            = -11279, /* Crypto lib init failed */
    UCRYPT_DERIVE_PUB_KEY_ERROR                                      = -11280, /* Crypto derive public key failed */

} error_code_e;

#endif // __ERROR_CODE_ENUM_H__

