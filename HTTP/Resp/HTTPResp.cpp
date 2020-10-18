#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdint>

#include "HTTPResp.h"

HTTPResp::HTTPResp(const char* bytecode){
    std::string str(bytecode);
    this->bytecode = str;
}

std::string HTTPResp::getBytecode(){
    return this->bytecode;
}

std::string HTTPResp::getPayload(){
    return this->payload;
}

std::string HTTPResp::getStatus(){
    return this->status;
}

void HTTPResp::setPayload(){
    try {
        //open file
        std::ifstream infile("../../tmp/" + this->fileName + "." + this->contentType);
        
        //get length of file
        infile.seekg(0, std::ios::end);
        size_t length = infile.tellg();
        infile.seekg(0, std::ios::beg);

        this->payload.resize(length);

        //read file
        infile.read(&this->payload[0], length);
        this->status = "200 - OK";
    } catch (std::ifstream::failure e) {
        std::cerr << "Exception opening/reading/closing file\n";
        this->status = "404 - Not Found";
    }
}

std::string HTTPResp::serialize(){
    return this->bytecode = this->status + ":" + this->payload;
}

std::vector<std::string> HTTPResp::getAttributes(){
    std::string attribute;
    std::vector<std::string> attributes;
    for (char & c : this->bytecode){
        if (c != ':'){
            attribute += c;
        }
        else {
            attributes.push_back(attribute);
            attribute = "";
        }
    }
    attributes.push_back(attribute);

    return attributes;
}

void HTTPResp::deserializeReq(){
    std::vector<std::string> attributes = getAttributes();

    this->method = attributes[0];
    this->host = attributes[1];
    this->port = attributes[2];
    this->fileName = attributes[3];
    this->contentType = attributes[4];
}

void HTTPResp::deserializeResp(){
    std::vector<std::string> attributes = getAttributes();

    this->status = attributes[0];
    this->payload = attributes[1];
}

void HTTPResp::saveFile(){
    std::ofstream out(this->fileName + "." + this->contentType);
    out << this->payload;
    out.close();
}

HTTPResp::~HTTPResp(){};