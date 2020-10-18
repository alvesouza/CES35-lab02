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

const char *HTTPReq::getHost() {
    return this->host;
}

uint16_t HTTPReq::getPort() {
    return this->port;
}

const char *HTTPReq::getMethod() {
    return this->method;
}

const char *HTTPReq::getContentType() {
    return this->contentType;
}

std::vector<uint8_t> HTTPReq::encode() {

}

const char *HTTPReq::getFile() {
    return this->file;
}

std::vector<uint8_t> HTTPReq::getBytecode() {
    return this->bytecode;
}





