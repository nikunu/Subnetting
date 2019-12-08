#ifndef _IP_H
#define _IP_H

int get_mask_val_in_integer(char);
void get_broadcast_addr(char*,char,char*);
unsigned int convert_ip_to_integer(char*);
void convert_ip_to_string(unsigned int, char*);
void get_network_id(char*,char,char*);
unsigned int get_subnet_cardinality(char);
int check_ip_subnet_membership(char*,char,char*);


#endif
