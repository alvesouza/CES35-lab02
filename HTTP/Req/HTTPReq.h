#ifndef CES35_LAB02_HTTPREQ_H
#define CES35_LAB02_HTTPREQ_H
#include <string>
#include <vector>
#include "../../functions/Inc/ip_functions.h"

class HTTPReq {
private:
    std::string url;
    uint16_t port;
    std::string method;
    std::string contentType;

public:
    HTTPReq(std::string url, uint16_t port, std::string method, std::string contentType){
        this->url = url;
        this->port = port;
        this->method = method;
        this->contentType = contentType;
    };
    
    std::string getUrl();

    uint16_t getPort();

    std::string getMethod();

    std::string getContentType();

    std::vector<uint8_t> getObj();

    /**
     * Faz o encode do objeto instanciado para bytes
     */
    std::vector<uint8_t> encode();

    ~HTTPReq();
};


#endif //CES35_LAB02_HTTPREQ_H
