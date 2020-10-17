//
// Created by pedro on 04/10/2020.
//
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include "HTTPReq.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

HTTPReq::HTTPReq() {
    this->port = 0;
    // cria o socket TCP IP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
}

std::pair<const char*, uint16_t> HTTPReq::setURL(const char* url_to_be) {
    this->url = url_to_be;

    // "Decoding" url
    // http://
    // 0123456
    if (!this->url.compare(0, 6,"http://")) {
        return std::make_pair("-1", 1);
    }
    int len = this->url.length();
    int j = 7;
    int i = j;
    while (this->url.at(i) != ':' && i < len){
        i++;
    }
    this->host =  this->url.substr(j, i-1).c_str();
    j = i;
    while (this->url.at(i) != '/' && i < len){
        this->port += atoi(reinterpret_cast<const char *>(url.at(i)))*pow(10, (i-j));
        i++;
    }
    this->obj = this->url.substr(i, len);

    return std::make_pair(host, port);
}

const char* HTTPReq::enconde() {
    return this->obj.c_str();
}

int HTTPReq::connectToReq(){
    // atividade de preenchimento da estrutura de endereço IP
    // e porta de conexão, precisa ser zerado o restante da estrutura
    // struct sockaddr_in {
    //  short            sin_family;   // e.g. AF_INET, AF_INET6
    //  unsigned short   sin_port;     // e.g. htons(3490)
    //  struct in_addr   sin_addr;     // see struct in_addr, below
    //  char             sin_zero[8];  // zero this if you want to
    // };
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(this->port);     // short, network byte order
    serverAddr.sin_addr.s_addr = inet_addr(this->host);
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    // conecta com o servidor atraves do socket
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("connect");
        return 2;
    }

    // a partir do SO, eh possivel obter o endereço IP usando
    // pelo cliente (nos mesmos) usando a funcao getsockname
    socklen_t clientAddrLen = sizeof(clientAddr);
    if (getsockname(sockfd, (struct sockaddr *)&clientAddr, &clientAddrLen) == -1) {
        perror("getsockname");
        return 3;
    }

    // em caso de multiplos endereços, isso permite o melhor controle
    // a rotina abaixo, imprime o valor do endereço IP do cliente
    char ipstr[INET_ADDRSTRLEN] = {'\0'};
    inet_ntop(clientAddr.sin_family, &clientAddr.sin_addr, ipstr, sizeof(ipstr));
    std::cout << "Set up a connection from: " << ipstr << ":" <<
              ntohs(clientAddr.sin_port) << std::endl;

    return 0;
}

int HTTPReq::makeRequest() {
    bool isEnd = false;
    char resp[20] = {0};

    // zera o buffer
    memset(resp, '\0', sizeof(resp));

    // Envia o Request
    if (send(sockfd, obj.c_str(), obj.size(), 0) == -1) {
        perror("request: ");
        return 4;
    }

    // recebe no buffer uma certa quantidade de bytes ate 20
    // Resposta
    if (recv(sockfd, resp, 20, 0) == -1) {
        perror("response: ");
        return 5;
    }

    // coloca o conteudo do buffer na string
    // imprime o buffer na tela)
    std::cout << resp << std::endl;


    return 0;
}

HTTPReq::~HTTPReq() {
    close(sockfd);
}
