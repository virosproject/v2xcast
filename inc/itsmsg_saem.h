/* ITS-G5 SAEM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_SAEM_H__
#define __ITSMSG_SAEM_H__


#include "itsmsg_cdd.h"
#include "itsmsg_iso17419.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef OctetString MACaddress;
typedef OctetString IPv6Address;

typedef VarLengthNumber ProtocolType;

typedef struct TwoDLocation TwoDLocation;
typedef struct ThreeDLocation ThreeDLocation;
typedef struct ExtendedChannelInfos ExtendedChannelInfos;
typedef struct MandAppCtx MandAppCtx;
typedef struct ProviderServiceContext ProviderServiceContext;
typedef struct EdcaParameterSet EdcaParameterSet;

typedef enum { /* Pre-defined values of ChannelAccess80211 */
               ChannelAccess80211_continuous = 0,
               ChannelAccess80211_alternatingSCH = 1,
               ChannelAccess80211_alternatingCCH = 2,
} ChannelAccess80211_e;


typedef enum {
    RsvAdvPrtVersion_c_rsvAdvPrtVersion2016 = 3,
} RsvAdvPrtVersion_e;

typedef struct SrvAdvChangeCount {
    int32_t saID; /* SrvAdvID (0..15) */
    int32_t contentCount; /* SrvAdvContentCount (0..15) */
} SrvAdvChangeCount;

typedef enum {
    RefExt_c_Reserved = 0,
    RefExt_c_TxPowerUsed80211 = 4,  // -- LM-N-Header, SAM Header
    RefExt_c_2Dlocation = 5,  // -- SAM Header
    RefExt_c_3Dlocation = 6,  // -- SAM Header
    RefExt_c_advertiserID = 7,  // -- SAM Header
    RefExt_c_ProviderServContext = 8,  // -- SAM Service Info
    RefExt_c_IPv6Address = 9,  // -- SAM Service Info
    RefExt_c_servicePort = 10,  // -- SAM Service Info
    RefExt_c_ProviderMACaddress = 11,  // -- SAM Service Info
    RefExt_c_EDCAparameterSet = 12,  // -- SAM Channel Info
    RefExt_c_SecondaryDNS = 13,  // -- SAM Routing Advertisement
    RefExt_c_GatewayMACaddress = 14,  // -- SAM Routing Advertisement
    RefExt_c_ChannelNumber80211 = 15,  // -- LM-N-Header
    RefExt_c_DataRate80211 = 16,  // -- LM-N-Header
    RefExt_c_RepeatRate = 17,  // -- SAM Header
    RefExt_c_CountryString = 18,  // -- SAM Header
    RefExt_c_RCPIthreshold = 19,  // -- SAM Service Info
    RefExt_c_WSAcountThreshold = 20,  // -- SAM Service Info
    RefExt_c_ChannelAccess = 21,  // -- SAM Channel Info
    RefExt_c_WSAcountThresInt = 22,  // -- SAM Service Info
    RefExt_c_ChannelLoad = 23,  // -- SAE / CAMP / 1609 are working on this
    RefExt_c_ProtocolType = 24,  // -- protocol type
    RefExt_c_LMtxCip = 80,  // -- LM-N-Header
    RefExt_c_LMrxCip = 81,  // -- LM-N-Header
    RefExt_c_LMchannelBusyRatio = 82,  // -- LM-N-Header
    RefExt_c_LMpacketID = 83,  // -- LM-T-Header
    RefExt_c_ExtendedChannelInfos = 84,  // -- SAM Header
    RefExt_c_SAMapplicationData = 85,  // -- SAM Service Info
} RefExt_e;

typedef struct SrvAdvMsgHeaderExt {
    RefExt_e extensionId; /* RefExt (0..255) */
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        int32_t *RepeatRate;
        TwoDLocation *TwoDLocation;
        ThreeDLocation *ThreeDLocation;
        OctetString *AdvertiserIdentifier;
        ExtendedChannelInfos *ExtendedChannelInfos;
        void *data;
        OctetString unknown;
    } u;
} SrvAdvMsgHeaderExt;

#define SrvAdvMsgHeaderExts_MAX_SIZE 0
typedef struct SrvAdvMsgHeaderExts {
    SrvAdvMsgHeaderExt *tab;
    int32_t count;
} SrvAdvMsgHeaderExts;

typedef VarLengthNumber ITSaid;

typedef enum { /* Pre-defined values of ChannelIndex */
               ChannelIndex_notUsed = 0,
               ChannelIndex_firstEntry = 1,
} ChannelIndex_e;

typedef enum {
    ctx_c_ctxRefNull = 0,  // -- can be used with all values of ITS-AID
    ctx_c_ctxRefMandApp = 1,  // -- can be used with ITS-AID = 0
} CtxRef_e;

typedef struct ItsAidCtxRef {
    ITSaid itsaid;
    CtxRef_e ctx; /* CtxRef (0..255) */
} ItsAidCtxRef;

typedef struct SamContext {
    ItsAidCtxRef itsaidCtxRef;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        MandAppCtx *MandAppCtx;
        void *data;
        OctetString unknown;
    } u;
} SamContext;

typedef SamContext SystemServiceAndContext;

#define SystemService_MAX_SIZE 0
typedef struct SystemService {
    SystemServiceAndContext *tab;
    int32_t count;
} SystemService;

typedef struct ServiceInfoExt {
    RefExt_e extensionId; /* RefExt (0..255) */
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        ProviderServiceContext *ProviderServiceContext;
        OctetString *IPv6Address;
        int32_t *ServicePort;
        OctetString *ProviderMacAddress;
        int32_t *RcpiThreshold;
        int32_t *WsaCountThreshold;
        int32_t *WsaCountThresholdInterval;
        OctetString *SAMapplicationData;
        ProtocolType *ProtocolType;
        void *data;
        OctetString unknown;
    } u;
} ServiceInfoExt;

#define ServiceInfoExts_MAX_SIZE 0
typedef struct ServiceInfoExts {
    ServiceInfoExt *tab;
    int32_t count;
} ServiceInfoExts;

typedef struct ChannelOptions {
    BOOL systemService_option;
    SystemService systemService;
    BOOL serviceProviderPort_option;
    int32_t serviceProviderPort; /* ReplyAddress */
    BOOL extensions_option;
    ServiceInfoExts extensions;
} ChannelOptions;

typedef struct ServiceInfo {
    ITSaid serviceID;
    ChannelIndex_e channelIndex; /* ChannelIndex (0..31) */
    ChannelOptions chOptions;
} ServiceInfo;

#define ServiceInfos_MAX_SIZE 0
typedef struct ServiceInfos {
    ServiceInfo *tab;
    int32_t count;
} ServiceInfos;

typedef struct WsaChInfoDataRate {
    BitString adaptable;
    int32_t dataRate;
} WsaChInfoDataRate;

typedef struct ChannelInfoExt {
    RefExt_e extensionId; /* RefExt (0..255) */
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        EdcaParameterSet *EdcaParameterSet;
        ChannelAccess80211_e *ChannelAccess80211;
        void *data;
        OctetString unknown;
    } u;
} ChannelInfoExt;

#define ChannelInfoExts_MAX_SIZE 0
typedef struct ChannelInfoExts {
    ChannelInfoExt *tab;
    int32_t count;
} ChannelInfoExts;

typedef struct ChInfoOptions {
    BOOL option1_option; /* not used */
    BOOL option2_option; /* not used */
    BOOL option3_option; /* not used */
    BOOL option4_option; /* not used */
    BOOL option5_option; /* not used */
    BOOL option6_option; /* not used */
    BOOL option7_option; /* not used */
    BOOL extensions_option;
    ChannelInfoExts extensions;
} ChInfoOptions;

typedef struct ChannelInfo {
    int32_t operatingClass; /* OperatingClass80211 (0..255) */
    int32_t channelNumber; /* ChannelNumber80211 (0..255) */
    int32_t powerLevel; /* TXpower80211 (-128..127) */
    WsaChInfoDataRate dataRate;
    ChInfoOptions extensions;
} ChannelInfo;

#define ChannelInfos_MAX_SIZE 0
typedef struct ChannelInfos {
    ChannelInfo *tab;
    int32_t count;
} ChannelInfos;

typedef struct RoutAdvertExt {
    RefExt_e extensionId; /* RefExt (0..255) */
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        OctetString *SecondaryDns;
        OctetString *GatewayMacAddress;
        void *data;
        OctetString unknown;
    } u;
} RoutAdvertExt;

#define RoutAdvertExts_MAX_SIZE 0
typedef struct RoutAdvertExts {
    RoutAdvertExt *tab;
    int32_t count;
} RoutAdvertExts;

typedef struct RoutingAdvertisement {
    int32_t lifetime; /* RouterLifetime (0..65535) */
    OctetString ipPrefix; /* IpV6Prefix (16..16) */
    int32_t ipPrefixLength; /* IpV6PrefixLength (0..255) */
    OctetString defaultGateway; /* IPv6Address (16..16) */
    OctetString primaryDns; /* IPv6Address (16..16) */
    RoutAdvertExts extensions;
} RoutingAdvertisement;

typedef struct SamBody {
    SrvAdvChangeCount changeCount;
    BOOL extensions_option;
    SrvAdvMsgHeaderExts extensions;
    BOOL serviceInfos_option;
    ServiceInfos serviceInfos;
    BOOL channelInfos_option;
    ChannelInfos channelInfos;
    BOOL routingAdvertisement_option;
    RoutingAdvertisement routingAdvertisement;
} SamBody;

typedef struct Sam {
    RsvAdvPrtVersion_e version; /* RsvAdvPrtVersion (0..15) */
    SamBody body;
} Sam;

typedef struct SAEM {
    ItsPduHeader header;
    Sam sam;
} SAEM;

typedef enum { /* Pre-defined values of MedType */
               MedType_unknown = 0,
               MedType_any = 1,
               MedType_iso21212 = 2,
               MedType_iso21213 = 3,
               MedType_iso21214 = 4,
               MedType_iso21215 = 5,
               MedType_iso21216 = 6,
               MedType_iso25112 = 7,
               MedType_iso25113 = 8,
               MedType_iso29283 = 9,
               MedType_iso17515 = 10,
               MedType_iso19079 = 11,
               MedType_iso15628 = 128,
               MedType_can = 254,
               MedType_ethernet = 255,
} MedType_e;

typedef enum { /* Pre-defined values of LMchannelBusyRatio */
               LMchannelBusyRatio_zeroPercent = 0,
               LMchannelBusyRatio_halfPercent = 1,
               LMchannelBusyRatio_onePercent = 2,
               LMchannelBusyRatio_hundredPercent = 200,
               LMchannelBusyRatio_unknown = 201,
} LMchannelBusyRatio_e;

typedef struct TwoDLocation {
    int32_t latitude; /* Latitude (-900000000..900000001) */
    int32_t longitude; /* Longitude (-1800000000..1800000001) */
} TwoDLocation;

typedef struct ThreeDLocation {
    int32_t latitude; /* Latitude (-900000000..900000001) */
    int32_t longitude; /* Longitude (-1800000000..1800000001) */
    int32_t elevation; /* Elevation (-4096..61439) */
} ThreeDLocation;

typedef struct ExtendedChannelInfo {
    MedType_e medId; /* MedType (0..255) */
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        ChannelInfo *ChannelInfo;
        void *data;
        OctetString unknown;
    } u;
} ExtendedChannelInfo;

#define ExtendedChannelInfos_MAX_SIZE 0
typedef struct ExtendedChannelInfos {
    ExtendedChannelInfo *tab;
    int32_t count;
} ExtendedChannelInfos;

typedef struct ProviderServiceContext {
    BitString fillBit;
    OctetString psc;
} ProviderServiceContext;

typedef MACaddress ProviderMacAddress;

typedef struct EdcaParameterRecord {
    int32_t res;
    int32_t aci;
    int32_t acm;
    int32_t aifsn;
    int32_t ecwMax;
    int32_t ecwMin;
    int32_t txopLimit;
} EdcaParameterRecord;

typedef struct EdcaParameterSet {
    EdcaParameterRecord acbeRecord;
    EdcaParameterRecord acbkRecord;
    EdcaParameterRecord acviRecord;
    EdcaParameterRecord acvoRecord;
} EdcaParameterSet;

typedef IPv6Address SecondaryDns;

typedef MACaddress GatewayMacAddress;

typedef struct SRMextension {
    RefExt_e extensionId; /* RefExt (0..255) */
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} SRMextension;

#define SRMextensions_MAX_SIZE 0
typedef struct SRMextensions {
    SRMextension *tab;
    int32_t count;
} SRMextensions;

#define SrmPrvChAllocReq_MAX_SIZE 0
typedef struct SrmPrvChAllocReq {
    ITSaid *tab;
    int32_t count;
} SrmPrvChAllocReq;

typedef struct SrmPrivateChannelsRq {
    int32_t portDynSam; /* PortNumber (0..65535) */
    SrmPrvChAllocReq allocReqs;
} SrmPrivateChannelsRq;

typedef struct SrmContext {
    SamContext context;
    int32_t clientPort; /* PortNumber (0..65535) */
} SrmContext;

#define SrmContexts_MAX_SIZE 0
typedef struct SrmContexts {
    SrmContext *tab;
    int32_t count;
} SrmContexts;

#define SrmPrvChAllocConf_MAX_SIZE 0
typedef struct SrmPrvChAllocConf {
    ITSaid *tab;
    int32_t count;
} SrmPrvChAllocConf;

typedef struct SrmBody {
    BOOL extensions_option;
    SRMextensions extensions;
    BOOL prvChannelsRq_option;
    SrmPrivateChannelsRq prvChannelsRq;
    BOOL contexts_option;
    SrmContexts contexts;
    BOOL prvChannelsCf_option;
    SrmPrvChAllocConf prvChannelsCf;
} SrmBody;

typedef struct Srm {
    RsvAdvPrtVersion_e header; /* RsvAdvPrtVersion (0..15) */
    SrmBody body;
} Srm;

#define MandAppCtx_MAX_SIZE 0
typedef struct MandAppCtx {
    ItsAidCtxRef *tab;
    int32_t count;
} MandAppCtx;


#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_SAEM_H__ */
