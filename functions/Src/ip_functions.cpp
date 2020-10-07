//
// Created by pedro on 04/10/2020.
//

#include "ip_functions.h"

std::string get_ip_from_hostname(const char *hostname){
    struct addrinfo hints;
    struct addrinfo* res;

    // hints - modo de configurar o socket para o tipo  de transporte
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    // funcao de obtencao do endereco via DNS - getaddrinfo
    // funcao preenche o buffer "res" e obtem o codigo de resposta "status"
    int status = 0;
    if ((status = getaddrinfo(hostname, "80", &hints, &res)) != 0) {
        std::cout << "getaddrinfo: " << gai_strerror(status) << std::endl;
        std::cerr << "getaddrinfo: " << gai_strerror(status) << std::endl;
        return "error";
    }

    std::cout << "IP addresses for " << hostname << ": " << std::endl;
    char ipstr[INET_ADDRSTRLEN] = {'\0'};
    for(struct addrinfo* p = res; p != 0; p = p->ai_next) {
        // a estrutura de dados eh generica e portanto precisa de type cast
        struct sockaddr_in* ipv4 = (struct sockaddr_in*)p->ai_addr;

        // e depois eh preciso realizar a conversao do endereco IP para string

        inet_ntop(p->ai_family, &(ipv4->sin_addr), ipstr, sizeof(ipstr));

//        std::cout << "  " << ipstr << std::endl;
    }

    freeaddrinfo(res); // libera a memoria alocada dinamicamente para "res"
    return ipstr;
}