/*
 * yunba_common.h
 *
 *  Created on: Nov 16, 2015
 *      Author: yunba
 */

#ifndef YUNBA_COMMON_H_
#define YUNBA_COMMON_H_

#if defined(WIN32) || defined(WIN64)
  #define DLLImport __declspec(dllimport)
  #define DLLExport __declspec(dllexport)
#else
  #define DLLImport extern
  #define DLLExport __attribute__ ((visibility ("default")))
#endif


typedef enum {
	GET_ALIAS =1,
	GET_ALIAS_ACK,
	GET_TOPIC,
	GET_TOPIC_ACK,
	GET_ALIAS_LIST,
	GET_ALIAS_LIST_ACK,
	PUBLISH2,
	PUBLISH2_ACK,
	GET_STATUS = 9,
	GET_STATUS_ACK,
	GET_TOPIC_LIST2 = 13,
	GET_TOPIC_LIST2_ACK,
	GET_ALIASLIST2,
	GET_ALIASLIST2_ACK,
	GET_STATUS2 = 19,
	GET_STATUS2_ACK = 20
} EXTED_CMD;

enum {
	PUBLISH2_TLV_TOPIC,
	PUBLISH2_TLV_PAYLOAD,
	PUBLISH2_TLV_PLAT,
	PUBLISH2_TLV_TTL,
	PUBLISH2_TLV_TIME_DELAY,
	PUBLISH2_TLV_LOCATION,
	PUBLISH2_TLV_QOS,
	PUBLISH2_TLV_APN_JSON,
	PUBLISH2_TLV_MAX_NUM
};

typedef struct {
	/* in MQTT v3.1,If the Client ID contains more than 23 characters, the server responds to
	 * the CONNECT message with a CONNACK return code 2: Identifier Rejected.
	 * */
	char client_id[200];
	/* in MQTT v3.1, it is recommended that passwords are kept to 12 characters or fewer, but
	 * it is not required. */
	char username[200];
	/*in MQTT v3.1, It is recommended that passwords are kept to 12 characters or fewer, but
	 * it is not required. */
	char password[200];
	/* user define it, and change size of device id. */
	char device_id[200];
} REG_info;

DLLExport int MQTTClient_setup_with_appkey(char* appkey, REG_info *info);

DLLExport int MQTTClient_setup_with_appkey_v2(char* appkey, REG_info *info);

DLLExport int MQTTClient_setup_with_appkey_and_deviceid(char* appkey, char *deviceid, REG_info *info);

DLLExport int MQTTClient_setup_with_appkey_and_deviceid_v2(char* appkey, char *deviceid, REG_info *info);

DLLExport int MQTTClient_get_host(char *appkey, char* url);
DLLExport int MQTTClient_get_host_v2(char *appkey, char* url);


#endif /* YUNBA_COMMON_H_ */
