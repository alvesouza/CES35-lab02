#ifndef CES35_LAB02_HTTPREQ_H
#define CES35_LAB02_HTTPREQ_H
#include <string>
#include <vector>
#include "ip_functions.h"

class HTTPReq {
private:
    std::string host;
    std::string port;
    std::string method;
    std::string contentType;
    std::string fileName;
    std::string bytecode;

public:
    HTTPReq(std::string url);
    
    std::string getHost();

    std::string getPort();

    std::string getMethod();

    std::string getContentType();

    std::string getFileName();

    std::string getBytecode();

    /**
     * Faz o encode do objeto instanciado para bytes
     */
    std::string serialize();

    ~HTTPReq();
};


#endif //CES35_LAB02_HTTPREQ_H
