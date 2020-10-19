#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <thread>

#include <iostream>
#include <sstream>

#include "web-client.h"
#include "ip_functions.h"
#include "constants.h"

typedef u_short content_type;

#define APP_JSON 0
#define TEXT_HTML 1

webClient::webClient(const char* url){
    req = new HTTPReq(url);
}

webClient::~webClient(){
    // fecha o socket
    close(sockfd);
}

int webClient::run(){
    // cria o socket TCP IP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // atividade de preenchimento da estrutura de endereço IP
    // e porta de conexão, precisa ser zerado o restante da estrutura
    // struct sockaddr_in {
    //  short            sin_family;   // e.g. AF_INET, AF_INET6
    //  unsigned short   sin_port;     // e.g. htons(3490)
    //  struct in_addr   sin_addr;     // see struct in_addr, below
    //  char             sin_zero[8];  // zero this if you want to
    // };
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(stoi(req->getPort())); // short, network byte order
    serverAddr.sin_addr.s_addr = inet_addr(get_ip_from_hostname(req->getHost().c_str()).c_str());
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    
    return connection();
}

int webClient::connection(){
    // conecta com o servidor atraves do socket
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("connect");
        return 2;
    }

    // a partir do SO, eh possivel obter o endereço IP usando 
    // pelo cliente (nos mesmos) usando a funcao getsockname
    struct sockaddr_in clientAddr;
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

    return waitResponse();
}

int webClient::waitResponse(){
    // buffer eh o buffer de dados a ser recebido no socket com 1MB
    char buf[buffer_max_size] = {0};
    std::stringstream ss;
    std::string input;

        // zera o buffer
        memset(buf, '\0', sizeof(buf));

    std::cout << "Envia\n";
    std::cout << "Envia:"<< req->serialize().c_str() << "\n";
    // envia a request
    if (send(sockfd, req->serialize().c_str(), req->getBytecode().size(), 0) == -1) {
        perror("send");
        return 4;
    }
        // leitura do teclado
        std::cout << "Press enter to make a GET request";
        std::cin >> input;

        // envia a request
        if (send(sockfd, req->serialize().c_str(), req->getBytecode().size(), 0) == -1) {
            perror("send");
            return 4;
        }

        // recebe no buffer uma certa quantidade de bytes ate 1MB
        if (recv(sockfd, buf, buffer_max_size, 0) == -1) {
            perror("recv");
            return 5;
        }
        resp = new HTTPResp(buf);
        resp->deserializeResp();
        resp->saveFile();

        // coloca o conteudo do buffer na string
        // imprime o buffer na tela
        ss << buf << std::endl;
        std::cout << "echo: ";
        std::cout << buf << std::endl;

    std::cout << "Espera Resposta\n";



        // zera a string ss
        ss.str("");


    // recebe no buffer uma certa quantidade de bytes ate 1MB
    if (recv(sockfd, buf, buffer_max_size, 0) == -1) {
        perror("recv");
        return 5;
    }
    resp = new HTTPResp(buf);
    resp->deserializeResp();
    resp->saveFile();
    
    // coloca o conteudo do buffer na string
    // imprime o buffer na tela
    ss << buf << std::endl;
    std::cout << "echo: ";
    std::cout << buf << std::endl;

    return 0;
}

int main(int argc, const char** argv) {
    webClient* client = new webClient(argv[1]);
    return client->run();;
}
