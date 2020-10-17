//
// Created by pedro on 04/10/2020.
//

#ifndef CES35_LAB02_HTTPREQ_H
#define CES35_LAB02_HTTPREQ_H
#include <string>
#include <vector>
class HTTPReq {
    std::string url;
    HTTPReq();

public:
    // Coloca o url passada como argumento no obj da classe
    void setURL(std::string url_to_be);
    // Não precisa estar implementado aqui, pois o método é sempre GET
    // void setMethod(std::string url);
    const char* enconde();
};


#endif //CES35_LAB02_HTTPREQ_H
