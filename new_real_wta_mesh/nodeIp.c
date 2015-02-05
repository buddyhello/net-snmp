/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "nodeIp.h"
#include "common.h"

/** Initializes the nodeIp module */
void
init_nodeIp(void)
{
    const oid nodeIp_oid[] = { 1,3,6,1,4,1,8072,2,4,1,1,2 };

  DEBUGMSGTL(("nodeIp", "Initializing\n"));

    netsnmp_register_scalar(
        netsnmp_create_handler_registration("nodeIp", handle_nodeIp,
                               nodeIp_oid, OID_LENGTH(nodeIp_oid),
                               HANDLER_CAN_RONLY
        ));
}

int
handle_nodeIp(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{ 
    char node_ip[100];
    char buf[30];

    memset(buf, 0, sizeof(buf)); 
    strcpy(buf, "IP");
    memset(node_ip, 0, sizeof(node_ip)); 

    switch(reqinfo->mode) {

        case MODE_GET:
           
            get_info(node_ip,buf);
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     node_ip,
                                     strlen(node_ip));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_nodeIp\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
