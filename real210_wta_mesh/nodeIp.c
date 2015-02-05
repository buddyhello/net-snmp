/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <stdlib.h>
#include <fcntl.h>
#include "nodeIp.h"

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
    FILE *fp;
    char node_ip[100];
    char temp[100];
    char filename[128];
    char buf[30];
    char *s;

    memset(filename, 0, sizeof(filename));
    strcpy(filename, "/tmp/node.txt");
    memset(buf, 0, sizeof(buf)); 
    strcpy(buf, "IP");
    memset(node_ip, 0, sizeof(node_ip)); 

    switch(reqinfo->mode) {

        case MODE_GET:
           
            if ((fp = fopen(filename, "r")) != NULL)
            {
                while(fgets(temp, sizeof(temp), fp) != NULL)
                {
                    s = strstr(temp, buf);
                    if ( s != NULL)
                    {
                         break;
                    }
                }
                /*Check if temp has buf*/
                if (s != NULL)
                {
                    /*The fgets return '\n',so just remove it*/
                    if (temp[strlen(temp) - 1] == '\n')
                    {
                        temp[strlen(temp) - 1] = '\0';
                    }  
                    strcpy(node_ip, temp);
                    printf("%s\n", node_ip);  
                }          
                fclose(fp);                     
            }
            else
            {
                perror("Can't open file");
            }

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
