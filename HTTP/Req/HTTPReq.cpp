//
// Created by pedro on 04/10/2020.
//

#include "HTTPReq.h"
#include "string.h"
#include "stdlib.h"


HTTPReq::HTTPReq() {
}

std::pair<std::basic_string<char>, std::basic_string<char>> HTTPReq::setURL(const char* url_to_be) {
    this->url = url_to_be;

    // "Decoding" url
    // http://
    // 0123456
    if (!this->url.compare(0, 6,"http://")) {
        return std::make_pair("-1", "-1");
    }
    int len = this->url.length();
    int j = 7;
    int i = j;
    while (this->url.at(i) != ':' && i < len){
        i++;
    }
    this->host =  this->url.substr(j, i-1);
    j = i;
    while (this->url.at(i) != '/' && i < len){
        i++;
    }
    this->port = this->url.substr(j, i-1);
    this->obj = this->url.substr(i, len);

    return std::make_pair(host, port);
}

const char* HTTPReq::enconde() {
    this->url.c_str();

    return
}

int HTTPReq::makeRequest() {

    return 0;
}
