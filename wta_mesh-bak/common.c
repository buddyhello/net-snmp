#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "common.h"

/*open the file and seach the information*/
void
get_info(char snmp_str[], char buf[])
{
    FILE *fp;
    char temp[100];
    char filename[128];
    char *s;
    char *t;

    memset(filename, 0, sizeof(filename));
    strcpy(filename, "/home/buddy/work/snmp/topoinfo/node.txt");

    if ((fp = fopen(filename, "r")) != NULL)
            {
                while(fgets(temp, sizeof(temp), fp) != NULL)
                {
                    /*Check if temp has buf*/
                    s = strstr(temp, buf);
                    if ( s != NULL)
                    {
                         break;
                    }
                }
                /*Check if temp has buf*/
                if (s != NULL)
                {
                    /*return substring of temp*/
                    t = strtok(temp, "\t");
                    while(t)
                    {
                        // sprintf(snmp_str,"%s", t);
                        strcpy(snmp_str, t);
                        t = strtok(NULL, "\t");
                    } 
                    
                    /*The fgets return '\n',so just remove it*/
                    if (snmp_str[strlen(snmp_str) - 1] == '\n')
                    {
                        snmp_str[strlen(snmp_str) - 1] = '\0';
                    }  
                    printf("%s\n", snmp_str);  
                }          
                fclose(fp);                     
            }
            else
            {
                perror("Can't open file");
            }
}