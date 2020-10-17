//
// Created by pedro on 04/10/2020.
//

#include "HTTPReq.h"
#include "string.h"

HTTPReq::HTTPReq() {
    this->url = new std::string;

}

void HTTPReq::setURL(std::string url_to_be) {
    this->url = url_to_be;
}

const char* HTTPReq::enconde() {
    return this->url.c_str();

}