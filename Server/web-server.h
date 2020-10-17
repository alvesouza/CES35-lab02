#ifndef CES35_LAB02_SERVER_H
#define CES35_LAB02_SERVER_H
#include <string>
#include <vector>

#include "../HTTP/Req/HTTPReq.h"
#include "../HTTP/Resp/HTTPResp.h"

class webServer {
    std::string host;
    int port;
    const char* dir;

public:
    webServer(const char* host, int port, std::string dir);

private:
    int connect();
};


#endif //CES35_LAB02_SERVER_H
