#include "ip.h"
#include <stdio.h>

void main(){

    char ip_input[] = {"192.153.242.3"};
    char check_ip[] = {"192.168.1.2"};
    char network_id [] = {"192.168.1.0"};
    char op_buffer[20];
 //   int mask = get_mask_val_in_integer(22);
   // printf("Mask in integer =  %u",mask);

    get_broadcast_addr(ip_input,22,op_buffer);
    unsigned int no_of_hosts =  get_subnet_cardinality(24);
    printf("\nHosts = %u",no_of_hosts);
    check_ip_subnet_membership(network_id,24,check_ip);
    check_ip_subnet_membership(network_id,24,ip_input);
}
