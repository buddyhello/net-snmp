/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "wlanSSID.h"
#include "common.h"

/** Initializes the wlanSSID module */
void
init_wlanSSID(void)
{
    const oid wlanSSID_oid[] = { 1,3,6,1,4,1,8072,2,4,1,1,7 };

  DEBUGMSGTL(("wlanSSID", "Initializing\n"));

    netsnmp_register_scalar(
        netsnmp_create_handler_registration("wlanSSID", handle_wlanSSID,
                               wlanSSID_oid, OID_LENGTH(wlanSSID_oid),
                               HANDLER_CAN_RONLY
        ));
}

int
handle_wlanSSID(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    char wlan_ssid[100];
    char buf[30];
 
    memset(buf, 0, sizeof(buf)); 
    strcpy(buf, "SSID");
    memset(wlan_ssid, 0, sizeof(wlan_ssid));

    switch(reqinfo->mode) {

        case MODE_GET:
            get_info(wlan_ssid, buf);
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     wlan_ssid,
                                     strlen(wlan_ssid));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_wlanSSID\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
