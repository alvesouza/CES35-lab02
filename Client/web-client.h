#ifndef CES35_LAB02_CLIENT_H
#define CES35_LAB02_CLIENT_H
#include <string>
#include <vector>

#include "HTTP/Req/HTTPReq.h"
#include "HTTP/Resp/HTTPResp.h"

class client {
    std::string url;

public:
    // Coloca o url passada como argumento no obj da classe
    void setURL(std::string url_to_be);
    // Não precisa estar implementado aqui, pois o método é sempre GET
    // void setMethod(std::string url);
    const char* enconde();
};


#endif //CES35_LAB02_CLIENT_H
