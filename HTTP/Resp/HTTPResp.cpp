#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdint>
#include <exception>

#include "HTTPResp.h"
#include "constants.h"
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

void HTTPResp::openFileInput() {
    infile.open("../../tmp/" + this->fileName + "." + this->contentType);
    //get length of file
    infile.seekg(0, std::ios::end);
    sizeInfile = infile.tellg();
    infile.seekg(0, std::ios::beg);
}

void HTTPResp::setPayload(){
    try {
        //open file
        if (!infile.is_open()){
            openFileInput();
        }

        sizePayLoad = payload_max_size;
        if (sizeInfile - sizePayLoad <= 0){
            sizePayLoad = sizeInfile;
            this->status = "200 - OK";
        }else{
            this->status = "206 - Partial Content";
        }
        this->payload.resize(sizePayLoad);

        //read file
        infile.read(&this->payload[0], sizePayLoad);
    } catch (std::exception& e) {
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

void HTTPResp::openFileOut() {
    out.open(this->fileName + "." + this->contentType);
}

void HTTPResp::saveFile(){
    if (!out.is_open())
        openFileOut();
    out << this->payload;
}

void HTTPResp::closeFileOut() {
    if (out.is_open())
        out.close();
}

HTTPResp::~HTTPResp(){};