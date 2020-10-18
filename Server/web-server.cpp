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

struct teste_request{
    int a, b, c;
};

struct teste_response{
    int volume;
    bool end;
    size_t tamanho;
    unsigned char *content;
};

webServer::webServer(const char* host, const char* port, const char* dir){
//    this->i = 0;
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
const size_t chunck_size = 2000;
void webServer::connect() {
//    sleep(10);
    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSockfd = accept(this->sockfd, (struct sockaddr*)&clientAddr, &clientAddrSize);
    std::thread(&webServer::connect, this).detach();
//    int i = this->i;
    if (clientSockfd == -1) {
        perror("accept");
        std::cout << "4\n";
        close(clientSockfd);
        return;
    }
//    this->i++;
//    sleep(rand()%10);
//    printf("i = %d\n", i);

    unsigned char buf[chunck_size+100] = {0};
    unsigned char bufreq[40] = {0};
    struct teste_request req;
    struct teste_response resp;
    resp.end = false;
    resp.content = (unsigned char *)malloc(sizeof(chunck_size));

    bool isEnd = false;
    // recebe ate 20 bytes do cliente remoto
    if (recv(clientSockfd, bufreq, sizeof(req), 0) == -1) {
        perror("recv");
        std::cout << "5"<< std::endl;
    }

    // Imprime o valor recebido no servidor antes de reenviar
    // para o cliente de volta
    memcpy(&req, bufreq, sizeof(req));
    resp.volume = req.a*req.b*req.c;
//    std::basic_ifstream<unsigned char>inFile;
//    inFile.open("oi.txt", std::ios::in | std::ios::binary);
    std::basic_ifstream<unsigned char>inFile;
    inFile.open("oi.txt", std::ios::in | std::ios::binary);
//    inFile.open("oi.txt");
    inFile.seekg(0, std::ios_base::end);
    size_t length = inFile.tellg();
    inFile.seekg(0, std::ios_base::beg);
    size_t pos = 0;
    std::cout << "tamanho = " << length << std::endl;
    sleep(5);
    printf("resp.content = %p\n", resp.content);
    while (pos < length) {
        // zera a memoria do buffer
        memset(buf, '\0', sizeof(buf));

        if(length - pos > chunck_size){
            inFile.read(resp.content, chunck_size);
            pos += chunck_size;
            resp.tamanho = chunck_size;
        }else{
            inFile.read(resp.content, length - pos);
            resp.tamanho = length - pos;
            pos = length;

        }
        for (size_t i = 0; i < resp.tamanho; i++){
            printf("%hhu", resp.content[i]);
        }
        printf("\n");
        if(pos >= length){
            resp.end = true;
        }
        printf("\n\n");
        std::cout << "tamanho = " << resp.tamanho << std::endl;
        std::cout << "sizeof(resp) = " << sizeof(resp) << std::endl;
        memcpy(buf, &resp, sizeof(resp));
        printf("%#010x\n", buf);
        for (size_t i = 0, n = sizeof(resp); i < n; i++){
            printf("%hhu", buf[i]);
        }
        printf("\n\n");
        memcpy(buf + sizeof(resp), resp.content, resp.tamanho);
        // envia de volta o buffer recebido como um echo
        if (send(clientSockfd, buf, sizeof(resp) + resp.tamanho, 0) == -1) {
            perror("send");
            std::cout << "6" << std::endl;
        }

        // o conteudo do buffer convertido para string pode
        // ser comparado com palavras-chave

        // zera a string para receber a proxima
        usleep(50000);

    }
    printf("resp.content = %p\n", resp.content);

    // fecha o socket
    std::cout << "fecha socket\n";
    close(clientSockfd);
    std::cout << "fecha socket\n";
    inFile.close();
    std::cout << "fecha socket\n";
    free(resp.content);
    std::cout << "fecha socket\n";
    return;
}

int webServer::run() {
    int j = this->init_listener();
    printf("init_listener = %d\n", j);
    std::thread(&webServer::connect, this).detach();

    getchar();
    return 0;
}


int main(int argc, char** argv){
    if(argc > 1){
        webServer server = webServer(argv[1], argv[2], argv[3]);
//        server.i = 1;
//        uint8_t* my_s_bytes = reinterpret_cast<uint8_t*>(&server);
//        server.i = 10;
//        &server = reinterpret_cast<webServer*>(my_s_bytes);
//        memcpy(&server, my_s_bytes, sizeof(server));
//        for (int i = 0, n = sizeof(my_s_bytes); i < n; ++i) {
//            printf("%hhu", my_s_bytes[i]);
//        }
//        printf("\n");
//        printf("server.i = %d\n", server.i);
        printf("%d\n", server.run());

    }
    return 0;
}

// int main() {
//   // cria um socket para IPv4 e usando protocolo de transporte TCP
//   int sockfd = socket(AF_INET, SOCK_STREAM, 0);

//   // Opções de configuração do SOCKETs
//   // No sistema Unix um socket local TCP fica preso e indisponível 
//   // por algum tempo após close, a não ser que configurado SO_REUSEADDR
//   int yes = 1;
//   if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
//     perror("setsockopt");
//     return 1;
//   }

//   // struct sockaddr_in {
//   //  short            sin_family;   // e.g. AF_INET, AF_INET6
//   //  unsigned short   sin_port;     // e.g. htons(3490)
//   //  struct in_addr   sin_addr;     // see struct in_addr, below
//   //  char             sin_zero[8];  // zero this if you want to
//   // };

//   struct sockaddr_in addr;
//   addr.sin_family = AF_INET;
//   addr.sin_port = htons(40000);     // porta tem 16 bits, logo short, network byte order
// //    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//     addr.sin_addr.s_addr = inet_addr("127.0.2.3");
//   memset(addr.sin_zero, '\0', sizeof(addr.sin_zero));

//   // realizar o bind (registrar a porta para uso com o SO) para o socket
//   if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
//     perror("bind");
//     return 2;
//   }

//   // colocar o socket em modo de escuta, ouvindo a porta 
//   if (listen(sockfd, 1) == -1) {
//     perror("listen");
//     return 3;
//   }

//   // aceitar a conexao TCP
//   // verificar que sockfd e clientSockfd sao sockets diferentes
//   // sockfd eh a "socket de boas vindas"
//   // clientSockfd eh a "socket diretamente com o cliente"
//   struct sockaddr_in clientAddr;
//   socklen_t clientAddrSize = sizeof(clientAddr);
//   int clientSockfd = accept(sockfd, (struct sockaddr*)&clientAddr, &clientAddrSize);

//   if (clientSockfd == -1) {
//     perror("accept");
//     return 4;
//   }

//   // usa um vetor de caracteres para preencher o endereço IP do cliente
//   char ipstr[INET_ADDRSTRLEN] = {'\0'};
//   inet_ntop(clientAddr.sin_family, &clientAddr.sin_addr, ipstr, sizeof(ipstr));
//   std::cout << "Accept a connection from: " << ipstr << ":" <<
//     ntohs(clientAddr.sin_port) << std::endl;

//   // faz leitura e escrita dos dados da conexao 
//   // utiliza um buffer de 20 bytes (char)
//   bool isEnd = false;
//   char buf[20] = {0};
//   std::stringstream ss;

//   while (!isEnd) {
//     // zera a memoria do buffer
//     memset(buf, '\0', sizeof(buf));

//     // recebe ate 20 bytes do cliente remoto
//     if (recv(clientSockfd, buf, 20, 0) == -1) {
//       perror("recv");
//       return 5;
//     }

//     // Imprime o valor recebido no servidor antes de reenviar
//     // para o cliente de volta
//     ss << buf << std::endl;
//     std::cout << buf << std::endl;

//     // envia de volta o buffer recebido como um echo
//     if (send(clientSockfd, buf, 20, 0) == -1) {
//       perror("send");
//       return 6;
//     }

//     // o conteudo do buffer convertido para string pode 
//     // ser comparado com palavras-chave
//     if (ss.str() == "close\n")
//       break;

//     // zera a string para receber a proxima
//     ss.str("");
//   }

//   // fecha o socket
//   close(clientSockfd);

//   return 0;
// }
