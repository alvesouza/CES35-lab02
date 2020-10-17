#ifndef CES35_LAB02_SERVER_H
#define CES35_LAB02_SERVER_H
#include <string>
#include <vector>

#include "HTTPReq.h"
#include "HTTPResp.h"

class webServer {
    std::string host;
    int port;
    const char* dir;

public:
    webServer(const char* host, const char* port, const char* dir);

private:
    int connect();
};


#endif //CES35_LAB02_SERVER_H
