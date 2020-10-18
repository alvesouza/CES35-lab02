#ifndef CES35_LAB02_SERVER_H
#define CES35_LAB02_SERVER_H
#include <string>
#include <vector>

#include "HTTPReq.h"
#include "HTTPResp.h"

class webServer {

public:
    webServer(const char* host, const char* port, const char* dir);
    int run();
//    std::vector<sockaddr_in> clientsAddr;
    int i;
private:
    std::string host;
    u_short port;
    const char* dir;
    int sockfd;
    struct sockaddr_in addr;
    int init_listener();
    void connect();
    void printa();
};


#endif //CES35_LAB02_SERVER_H
