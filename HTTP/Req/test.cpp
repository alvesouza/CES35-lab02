#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdint>

#include "./HTTPReq.cpp"

int main(){
    HTTPReq req("http://localhost:4000/index.html");

    std::cout << req.getHost() << std::endl;
    std::cout << req.getPort() << std::endl;
    std::cout << req.getMethod() << std::endl;
    std::cout << req.getFileName() << std::endl;
    std::cout << req.getContentType() << std::endl;

    std::cout << req.serialize() << std::endl;
    std::cout << req.getBytecode() << std::endl;

    return 0;
}