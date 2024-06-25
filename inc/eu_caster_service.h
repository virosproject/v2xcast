#ifndef __EU_CASTER_SERVICE_H__
#define __EU_CASTER_SERVICE_H__

/**
*   @defgroup eu_caster_service
*   @{
*   This section introduces the eu caster service APIs including terms and acronyms, eu caster service functions.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>
#include "common_caster_service.h"

#define EU_CASTER_MAX_SSP (32U)
#define EU_CASTER_MAC_ADDR_SIZE 6
#define EU_CASTER_PKT_SIZE_MAX (1500U)

/**
 * @brief This enum defines caster mgnt type
 */
typedef enum {
    EU_CASTER_MGNT_COEXISTENCE_MODE_SET_REQ = 0, /**< COEXISTENCE MODE SET REQ */
    EU_CASTER_MGNT_COEXISTENCE_MODE_SET_RSP, /**< COEXISTENCE MODE SET RSP */
    EU_CASTER_MGNT_COEXISTENCE_MODE_GET_REQ, /**< COEXISTENCE MODE GET REQ */
    EU_CASTER_MGNT_COEXISTENCE_MODE_GET_RSP, /**< COEXISTENCE MODE GET RSP */
    EU_CASTER_MGNT_MSG_TYPE_MAX /**< Numbers of mgnt message types */
} eu_caster_mgnt_msg_type_e;

/**
 * @brief This enum defines EU caster security encapsulation type
 */
typedef enum {
    EU_SEC_ENCAP_UNSECURE = 0, /**< Unsecure encapsulation type */
    EU_SEC_ENCAP_SIGN, /** Signed encapsulation type */
} eu_security_encap_type_e;

/**
 * @brief This enum defines EU caster security decapsulation result
 */
typedef enum {
    EU_SEC_DECAP_NONE = 0, /**< Non-execution security decapulation */
    EU_SEC_DECAP_INVALID_FMT, /**< Invalid EtsiTs103097 format */
    EU_SEC_DECAP_VERIFIED_PKT, /**< Valid EtsiTs103097 SignedData (verification success) */
    EU_SEC_DECAP_UNVERIFIABLE_PKT, /**< Valid EtsiTs103097 UnsecuredData (unable to verify) OR SignedData (verification failure) */
} eu_security_decap_status_e;

/**
 * @brief This enum defines EU caster area type
 */
typedef enum {
    CASTER_AREA_TYPE_CIRCLE = 0, /**< Circle area type */
    CASTER_AREA_TYPE_RECT, /**< Rectangular area type */
    CASTER_AREA_TYPE_ELIP, /**< Ellipse area type */
    CASTER_AREA_TYPE_NUM, /**< Number of area types */
} caster_area_type_e;

/**
 * @brief This structure defines EU caster position information
 */
typedef struct caster_position_info {
    int32_t latitude; /**< WGS84, 1/10 micros degrees. */
    int32_t longitude; /**< WGS84, 1/10 micros degrees. */
} caster_position_info_t;

/**
 * @brief This structure defines EU caster area type information
 */
typedef struct caster_area_type_info {
    caster_area_type_e type; /**< GN_AREA_TYPE_CIRCLE, GN_AREA_TYPE_RECT, GN_AREA_TYPE_ELIP. */
    uint16_t distance_a; /**< Distance a of the geometric shape, meters. */
    uint16_t distance_b; /**< Distance b of the geometric shape, meters. */
    uint16_t angle; /**< Angle of the geometric shape, degrees from North. */
} caster_area_type_info_t;

/**
 * @brief This structure defines EU caster TX security information
 */
typedef struct eu_caster_tx_security {
    eu_security_encap_type_e type; /**< Encapsulation type */
    uint32_t its_aid; /**< ITS Application Object Identifier (AID) */
    uint8_t ssp_len; /**< Number of Service Specific Permission (SSP) */
    uint8_t ssp[EU_CASTER_MAX_SSP]; /**< Service Specific Permission (SSP) */
} eu_caster_tx_security_t;

/**
 * @brief This structure defines EU caster RX security information
 */
typedef struct eu_caster_rx_security {
    eu_security_decap_status_e status; /**< Decapsulation result */
    uint32_t its_aid; /**< ITS Application Object Identifier (AID) */
    uint8_t ssp_len; /**< Number of Service Specific Permission (SSP) */
    uint8_t ssp[EU_CASTER_MAX_SSP]; /**< Service Specific Permission (SSP) */
} eu_caster_rx_security_t;

/**
 * @brief This structure defines EU caster TX information
 */
typedef struct eu_caster_tx_info {
    uint16_t dest_port; /**< this field is used if dest_port_is_present is true */
    uint8_t data_rate; /**< this field is used if data_rate_is_present is true, unit in 500Kbps */
    int8_t tx_power; /**< this field is used if tx_power_is_present is true */
    uint8_t traffic_class_id; /**< this field is used if traffic_class_id_is_present is true */
    eu_caster_tx_security_t security; /**< this field is used if security_is_present is true */
    caster_position_info_t position_info; /**< this field is used if position_info_is_present is true */
    caster_area_type_info_t area_type_info; /**< this field is used if area_type_info_is_present is true */
    bool dest_port_is_present; /**< this field indicates if destination port is present or not */
    bool data_rate_is_present; /**< this field indicates if data rate is present or not */
    bool tx_power_is_present; /**< this field indicates if TX power is present or not */
    bool traffic_class_id_is_present; /**< this field indicates if traffic class ID is present or not */
    bool security_is_present; /**< this field indicates if security is present or not */
    bool position_info_is_present; /**< this field indicates if position info is present or not */
    bool area_type_info_is_present; /**< this field indicates if area type info is present or not */
} eu_caster_tx_info_t;

/**
 * @brief This structure defines EU caster RX information
 */
typedef struct eu_caster_rx_info {
    struct timeval timestamp; /**< The received time of the packet from lower layer */
    int16_t rssi; /**< The receiving RSSI of the packet */
    uint16_t data_rate; /**< 500kbit per sec */
    uint8_t traffic_class_id; /**< this field indicates traffic class ID */
    uint8_t remain_hop_limit; /**< this field indicates remaining hop limit */
    eu_caster_rx_security_t security; /**< this field indicates security info */
    caster_position_info_t position_info; /**< this field indicates position info */
    caster_area_type_info_t area_type_info; /**< this field indicates area type info */
    uint8_t source_mac_addr[EU_CASTER_MAC_ADDR_SIZE]; /**< this field indicates source MAC address */
} eu_caster_rx_info_t;


/**
*   @brief Install public security key for caster
*
*   @param [in] sec_key indicates public sec_key.
*               sec_key generate by v2xcast_manager, key length follow define CASTER_SEC_KEY_LEN
*               In the end of sec_key is '\0'
*               Please install security key by following steps before eu_caster_init
*                   1. Install private sec_key by v2xcast_manager
*                   2. Install public sec_key by this API
*
*   @returns The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_sec_key_install(char *sec_key);

/**
*   @brief Uninstall public security key for caster
*
*   @details Please uninstall security key by following steps
*                1. Uninstall public sec_key by this API
*                2. Uninstall private sec_key by v2xcast_manager
*                3. Create a new caster by eu_caster_init
*
*   @returns The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_sec_key_uninstall(void);

/**
*   @brief Init context of a caster
*
*   @returns The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_init(void);

/**
*   @brief Create an instance of a caster and set up the resources needed for the caster
*
*   @param [in] config indicates the communication setting, including IP, caster id and caster communication mode.
*               IP format example: "127.0.0.1".
*               caster_id: ID in Caster Profile defined in the config file.
*               caster_comm_mode: TX or RX.
*   @param [out] caster_handler indicates the handler of a caster to be created
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_create(caster_handler_t *caster_handler, caster_comm_config_t *config);

/**
*   @brief Transmit an V2X message
*
*   @param [in] caster_handler indicates a created caster handler.
*   @param [in] *tx_info indicates to replace the default configurations with this tx_info.
*               if NULL, using TX setting from JSON config, otherwise using TX setting with this tx_info parameters.
*   @param [in] buf indicates the message to be sent.
*   @param [in] len indicates the number of bytes to be sent, maximum payload length is 1500 bytes.
*                   The transmission size may exceed 1500 bytes after low-layer processing. In this case, user should reduce the message size.
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_tx(caster_handler_t caster_handler, eu_caster_tx_info_t *tx_info, uint8_t *buf, size_t len);

/**
*   @brief Receive a V2X message. This API will block until received packet
*
*   @param [in] caster_handler indicates a created caster handler.
*   @param [out] *rx_info is used to receive the information of rx_info.
*   @param [out] buf is used to receive a message.
*   @param [out] len indicates the number of bytes received.
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_rx(caster_handler_t caster_handler, eu_caster_rx_info_t *rx_info, uint8_t *buf, size_t buf_size, size_t *len);

/**
*   @brief Receive an V2X message with timeout. This API will block until timeout
*
*   @param [in] caster_handler indicates a created caster handler.
*   @param [out] *rx_info is used to receive the information of rx_info.
*   @param [out] buf is used to receive a message.
*   @param [out] len indicates the number of bytes received.
*   @param [in] timeo indicates waiting time(ms) for receiving the message
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_rx_timeout(caster_handler_t caster_handler, eu_caster_rx_info_t *rx_info, uint8_t *buf, size_t buf_size, size_t *len, int timeo);

/**
*   @brief Subscribe an endpoint to the target caster handler
*
*   @param [in] caster_handler indicates a created caster handler for the endpoint to subscribe.
*   @param [in] *p_endpoint indicates the endpoint setting, including IP, endpoint type and caster id.
*               IP format example: "127.0.0.1".
*               caster_endpoint_id_type_e: endpoint id type, default using CASTER_ENDPOINT_ID_TYPE_CASTER_ID.
*               caster_id: ID in Caster Profile defined in the config file.
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_subscribe(caster_handler_t caster_handler, caster_endpoint_t *p_endpoint);

/**
*   @brief Unsubscribe an endpoint from the target caster handler
*
*   @param [in] caster_handler indicates a created caster handler for the endpoint to unsubscribe.
*   @param [in] *p_endpoint indicates the endpoint which need to unsubscribe.
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_unsubscribe(caster_handler_t caster_handler, caster_endpoint_t *p_endpoint);

/**
*   @brief EU caster SPLMNT
*   @param [in] caster_handler indicates a created caster handler.
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_splmnt(caster_handler_t caster_handler, caster_splmnt_req_info_t *p_splmnt_req_info, caster_splmnt_rsp_info_t *p_splmnt_rsp_info);

/**
*   @brief Set an EU caster MGNT coexistence mode set
*   @param [in] caster_handler indicates a created caster handler.
*   @param [in] is_enabled indicates if set EU caster MGNT coexistence mode is enabled or not
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_mgnt_coexistence_mode_set(caster_handler_t caster_handler, bool is_enabled);

/**
*   @brief Set an EU caster MGNT coexistence mode get
*   @param [in] caster_handler indicates a created caster handler.
*   @param [out] is_enabled indicates if get EU caster MGNT coexistence mode is enabled or not
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_mgnt_coexistence_mode_get(caster_handler_t caster_handler, bool *is_enabled);

/**
*   @brief Release a caster instance and clean up the resources needed for the caster instance
*
*   @param [in] caster_handler indicates the caster handler to be released.
*   @return The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_release(caster_handler_t caster_handler);

/**
*   @brief Get thread configuration for application usage
*
*   @param [out] caster_thread_info_t is use to set tx and rx message thread configuration in application.
*   @returns none
 */
void eu_caster_thread_info_get(caster_thread_info_t *thread_info);

/**
*   @brief Deinit context of a caster
*
*   @returns The status of the API invoked, Please refer to RETURN VALUES for details.
*/
int eu_caster_deinit(void);

/**
*   @brief Transform error code into string
*
*   @returns String of error information
*/
char *eu_caster_strerror(int err_code);
/**
 *  @}
 */

#endif