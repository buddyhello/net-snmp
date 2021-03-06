/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "myTime.h"


/** Initializes the myTime module */
void
init_myTime(void)
{
    const oid myTime_oid[] = { 1,3,6,1,4,1,8072,2,4,1,1,3 };

  DEBUGMSGTL(("myTime", "Initializing\n"));

    netsnmp_register_scalar(
        netsnmp_create_handler_registration("myTime", handle_myTime,
                               myTime_oid, OID_LENGTH(myTime_oid),
                               HANDLER_CAN_RONLY
        ));
}

int
handle_myTime(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    time_t t;
    switch(reqinfo->mode) {

        case MODE_GET:
            time(&t);
            char sztime[100];
            snprintf(sztime,100,"%s",ctime(&t));
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     /* XXX: a pointer to the scalar's data */
                                     sztime,
                                     /* XXX: the length of the data in bytes */
                                     strlen(sztime));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_myTime\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
