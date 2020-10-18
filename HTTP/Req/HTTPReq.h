#ifndef CES35_LAB02_HTTPREQ_H
#define CES35_LAB02_HTTPREQ_H
#include <string>
#include <vector>
#include "../../functions/Inc/ip_functions.h"

class HTTPReq {
private:
    std::string host;
    std::string port;
    std::string method;
    std::string contentType;
    std::string fileName;
    const char* bytecode;

public:
    HTTPReq(std::string host, std::string port, std::string method, std::string contentType, std::string fileName){
        this->host = host;
        this->port = port;
        this->method = method;
        this->contentType = contentType;
        this->fileName = fileName;
    };
    
    std::string getHost();

    std::string getPort();

    std::string getMethod();

    std::string getContentType();

    std::string getFileName();

    const char* getBytecode();

    /**
     * Faz o encode do objeto instanciado para bytes
     */
    const char* encode();

    ~HTTPReq();
};


#endif //CES35_LAB02_HTTPREQ_H
