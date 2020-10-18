#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdint>

#include "HTTPReq.h"

HTTPReq::HTTPReq(std::string url){
    if (!url.compare(0, 6,"http://")) {
        throw "Invalid URL";
    }
    int len = url.length();
    int i = 7;
    int j = i;
    while (url.at(i++) != ':' && i < len);
    this->host =  url.substr(j, i-2-j+1);
    j = i;
    while (url.at(i++) != '/' && i < len);
    this->port = url.substr(j, i-2-j+1);
    j = i;
    while(url.at(i++) != '.' && i < len);
    this->fileName = url.substr(j, i-2-j+1);
    this->contentType = url.substr(i);
    this->method = "GET";
}

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

std::string HTTPReq::serialize() {
    return this->bytecode = this->method + ":" + this->host + ":" + this->port + ":" + this->fileName + ":" + this->contentType;
}

std::string HTTPReq::getFileName() {
    return this->fileName;
}

std::string HTTPReq::getBytecode() {
    return this->bytecode;
}

HTTPReq::~HTTPReq(){};




