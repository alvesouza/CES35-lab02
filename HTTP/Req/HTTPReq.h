#ifndef CES35_LAB02_HTTPREQ_H
#define CES35_LAB02_HTTPREQ_H
#include <string>
#include <vector>
#include "../../functions/Inc/ip_functions.h"

class HTTPReq {
private:
    const char* host;
    uint16_t port;
    const char* method;
    const char* contentType;
    const char* file;
    std::vector<uint8_t> bytecode;

public:
    HTTPReq(const char* host, uint16_t port, const char* method, const char* contentType, const char* file){
        this->host = host;
        this->port = port;
        this->method = method;
        this->contentType = contentType;
        this->file = file;
    };
    
    const char* getHost();

    uint16_t getPort();

    const char* getMethod();

    const char* getContentType();

    const char* getFile();

    const char* getBytecode();

    /**
     * Faz o encode do objeto instanciado para bytes
     */
    std::vector<uint8_t> encode();

    ~HTTPReq();
};


#endif //CES35_LAB02_HTTPREQ_H
