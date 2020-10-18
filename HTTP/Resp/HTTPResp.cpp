#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdint>

#include "HTTPResp.h"

HTTPResp::HTTPResp(const char* bytecode){
    this->bytecode = bytecode;
}

const char* HTTPResp::getBytecode(){
    return this->bytecode;
}

std::string HTTPResp::getPayload(){
    return this->payload;
}

std::string HTTPResp::getStatus(){
    return this->status;
}

void HTTPResp::setPayload(std::string fileName, std::string contentType){
    try {
        //open file
        std::ifstream infile("../../tmp" + fileName + contentType);

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

const char* HTTPResp::encode(){
    std::string str = this->status + ":" + this->payload;
    return this->bytecode = str.c_str();
}

std::vector<std::string> HTTPResp::getAttributes(){
    std::string str(this->bytecode);
    std::string attribute;
    std::vector<std::string> attributes;
    for (char & c : str){
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

void HTTPResp::decodeReq(){
    std::vector<std::string> attributes = getAttributes();

    this->host = attributes[0];
    this->port = attributes[1];
    this->method = attributes[2];
    this->contentType = attributes[3];
    this->fileName = attributes[4];
}

void HTTPResp::decodeResp(){
    std::vector<std::string> attributes = getAttributes();

    this->status = attributes[0];
    this->payload = attributes[1];
}

void HTTPResp::saveFile(){
    std::ofstream out(this->fileName + this->contentType);
    out << this->payload;
    out.close();
}
