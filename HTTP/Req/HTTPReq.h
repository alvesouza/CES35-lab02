//
// Created by pedro on 04/10/2020.
//

#ifndef CES35_LAB02_HTTPREQ_H
#define CES35_LAB02_HTTPREQ_H
#include <string>
#include <vector>
#include "../../functions/Inc/ip_functions.h"

class HTTPReq {
    std::basic_string<char> host;
    std::basic_string<char> port;
    std::basic_string<char> obj;
    std::string url;
    HTTPReq();

public:
    // Coloca o url passada como argumento no obj da classe
    // Coloca o obj na classe e retorna as strings do host e da porta, como par
    std::pair<std::basic_string<char>, std::basic_string<char>> setURL(const char* enteredUrl);
    // Não precisa estar implementado aqui, pois o método é sempre GET
    // void setMethod(std::string url);
    const char* enconde();
    int makeRequest();
};


#endif //CES35_LAB02_HTTPREQ_H
