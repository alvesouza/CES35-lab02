#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "thread"
#include <iostream>
#include <sstream>

#include "ip_functions.h"
#include "web-server.h"
#include "fstream"
#include "HTTPResp.h"
#include "HTTPReq.h"
#include "constants.h"

webServer::webServer(const char* host, const char* port, const char* dir){
    this->host = get_ip_from_hostname(host);
    this->port = (unsigned short)strtol(port, NULL, 10);

    this->dir = dir;
}

int webServer::init_listener() {
    // cria um socket para IPv4 e usando protocolo de transporte TCP
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // Opções de configuração do SOCKETs
    // No sistema Unix um socket local TCP fica preso e indisponível
    // por algum tempo após close, a não ser que configurado SO_REUSEADDR
    int yes = 1;
    if (setsockopt(this->sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // struct sockaddr_in {
    //  short            sin_family;   // e.g. AF_INET, AF_INET6
    //  unsigned short   sin_port;     // e.g. htons(3490)
    //  struct in_addr   sin_addr;     // see struct in_addr, below
    //  char             sin_zero[8];  // zero this if you want to
    // };

    (this->addr).sin_family = AF_INET;
    (this->addr).sin_port = htons(this->port);     // porta tem 16 bits, logo short, network byte order
    (this->addr).sin_addr.s_addr = inet_addr((this->host).c_str());
    memset((this->addr).sin_zero, '\0', sizeof((this->addr).sin_zero));

    // realizar o bind (registrar a porta para uso com o SO) para o socket
    if (bind(this->sockfd, (struct sockaddr*)&(this->addr), sizeof((this->addr))) == -1) {
        perror("bind");
        return 2;
    }

    // colocar o socket em modo de escuta, ouvindo a porta
    if (listen(this->sockfd, 1) == -1) {
        perror("listen");
        return 3;
    }

    return 0;
}

void webServer::connect() {
    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSockfd = accept(this->sockfd, (struct sockaddr*)&clientAddr, &clientAddrSize);
    std::thread(&webServer::connect, this).detach();
    if (clientSockfd == -1) {
        perror("accept");
        std::cout << "4\n";
        close(clientSockfd);
        return;
    }
    char buf[buffer_max_size] = {0};

    bool isEnd = false;
    if (recv(clientSockfd, buf, buffer_max_size, 0) == -1) {
        perror("recv");
    }
    HTTPResp resp(buf);
    resp.deserializeReq();


    resp.setPayload(dir);

    std::cout << "Sending response...\n";
    resp.serialize();
    if (send(clientSockfd, resp.serialize().c_str(), resp.getBytecode().size(), 0) == -1) {
        perror("send");
    }

    // fecha o socket
    close(clientSockfd);
    std::cout << "Socket closed\n";
    return;
}

int webServer::run() {
    this->init_listener();
    std::thread(&webServer::connect, this).detach();

    getchar();
    return 0;
}


int main(int argc, char** argv){
    if(argc > 1){
        webServer server = webServer(argv[1], argv[2], argv[3]);
        printf("%d\n", server.run());

    }
    return 0;
}
