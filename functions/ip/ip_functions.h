//
// Created by pedro on 04/10/2020.
//

#ifndef CES35_LAB02_IP_FUNCTIONS_H
#define CES35_LAB02_IP_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#include <string>
#include <iostream>

std::string get_ip_from_hostname(const char *hostname);


#endif //CES35_LAB02_IP_FUNCTIONS_H
