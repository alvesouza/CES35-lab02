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

std::string HTTPReq::getHost() {
    return this->host;
}

std::string HTTPReq::getPort() {
    return this->port;
}

std::string HTTPReq::getMethod() {
    return this->method;
}

std::string HTTPReq::getContentType() {
    return this->contentType;
}

const char* HTTPReq::encode() {
    std::string str = this->host + ":" + this->port + ":" + this->method + ":" + this->contentType + ":" + this->fileName;
    return this->bytecode = str.c_str();
}

std::string HTTPReq::getFileName() {
    return this->fileName;
}

const char* HTTPReq::getBytecode() {
    return this->bytecode;
}





