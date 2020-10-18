#ifndef CES35_LAB02_CLIENT_H
#define CES35_LAB02_CLIENT_H
#include <string>
#include <vector>

#include "../HTTP/Req/HTTPReq.h"
#include "../HTTP/Resp/HTTPResp.h"

class webClient {
private:
    HTTPReq* req;
    HTTPResp* resp;
    std::string url;
    int sockfd;
    struct sockaddr_in serverAddr;
public:
    webClient(const char* url);
    
    int run();

    int connection();

    int waitResponse();

    ~webClient();
};


#endif //CES35_LAB02_CLIENT_H
