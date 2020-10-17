//
// Created by pedro on 04/10/2020.
//

#ifndef CES35_LAB02_HTTPREQ_H
#define CES35_LAB02_HTTPREQ_H
#include <string>
#include <vector>
#include "../../functions/Inc/ip_functions.h"

class HTTPReq {
    HTTPReq();
    ~HTTPReq();
    std::string url;
    const char* host;
    uint16_t port;
    std::basic_string<char> obj;
    int sockfd;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    char resp[20] = {0};

public:
    // Coloca o url passada como argumento no obj da classe
    // Coloca o obj na classe e retorna as strings do host e da porta, como par
    std::pair<const char*, uint16_t> setURL(const char* url_to_be);
    // Não precisa estar implementado aqui, pois o método é sempre GET
    // void setMethod(std::string url);
    int connectToReq();
    const char* enconde();
    int makeRequest();
};


#endif //CES35_LAB02_HTTPREQ_H
