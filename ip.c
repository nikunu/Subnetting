#include "ip.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_MASK_LEN    (32U)


int get_mask_val_in_integer(char mask_val){
    int mask_in_int = 0XFFFFFFFF;
    mask_in_int = mask_in_int<<(32-mask_val);
    return mask_in_int;
}

unsigned int convert_ip_to_integer(char* ip_addr){
    unsigned int converted_ip = 0;
    int count = 0;
    while(count <= 3){
        unsigned char octet = 0;
        while((*ip_addr != '.') && (*ip_addr != '\0')){
           // printf("\nCurrent character is: %u",*ip_addr);
            octet = octet*10 + (*ip_addr - '0');
            ip_addr++;
      //      printf("\nOctet is : %u",octet);
        }
        count++;
//        printf("\nOctet is : %u",octet);
        converted_ip = converted_ip*256 + octet;
    //    printf("\nCurrent ip is: %u",converted_ip);
        ip_addr++;
    }
    return converted_ip;
}

void convert_ip_to_string(unsigned int ip_addr, char *output_buffer){
    unsigned char octet[4];
    int i = 0;
    for(; i < 4;i++){
        octet[4-i-1] = ip_addr % 256;
        ip_addr = ip_addr / 256;
    }
    for(i = 0;i < 4; i++){
        unsigned char digit[3];
        int j = 0;
        while(octet[i] != 0){
            digit[j] = octet[i] % 10;
            j++;
            octet[i] = octet[i] / 10;
        }
        while(j > 0){
            *output_buffer = digit[j-1] + '0';
         //   printf("\n%c",*output_buffer);
            j--;
            output_buffer++;
        }
        if(i < 3){
            *output_buffer = '.';
            output_buffer++;
        }else{
            *output_buffer = '\0';
            output_buffer++;
        }
    }
}

             



void get_broadcast_addr(char* ip_addr,char mask,char* output_buffer){
    char net_id_buffer[20],buffer[20];
    char i = 0;
    char no_of_control_bits = MAX_MASK_LEN - mask;
    unsigned int control_bits = 0xFFFFFFFF;
    control_bits = control_bits >> mask;
    get_network_id(ip_addr,mask,net_id_buffer);
    unsigned int network_id_in_int = convert_ip_to_integer(net_id_buffer); 
    unsigned int broadcast_addr_int = network_id_in_int | control_bits;
   // printf("Ip address in integer is : %u\n",broadcast_addr_int);
    convert_ip_to_string(broadcast_addr_int,output_buffer);
    convert_ip_to_string(broadcast_addr_int,buffer);
    while(buffer[i] != '\0'){
        printf("%c",buffer[i]);
        i++;
    }
};


void get_network_id(char* ip_addr,char mask,char* output_buffer){
    int mask_in_int = get_mask_val_in_integer(mask);
    unsigned int ip_addr_in_int = convert_ip_to_integer(ip_addr);
    unsigned int network_id = ip_addr_in_int & mask_in_int;
    convert_ip_to_string(network_id,output_buffer);
}

unsigned int get_subnet_cardinality(char mask_val){
    unsigned int hosts = pow(2,MAX_MASK_LEN - mask_val) -2;
    return hosts;
}

int check_ip_subnet_membership(char* network_id,char mask,char* check_ip_addr){
    char network_id_buffer[20];
    get_network_id(check_ip_addr,mask,network_id_buffer);
    unsigned int check_ip__network_id = convert_ip_to_integer(network_id_buffer); 
    unsigned int network_id_int = convert_ip_to_integer(network_id);
    if(check_ip__network_id == network_id_int){
        printf("\nIP is present in this network");
        return 0;
    }else{
        printf("\nIP not present in this network");    
        return -1;
    }
}
