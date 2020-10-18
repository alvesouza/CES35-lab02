#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdint>

std::string pathFileToStringFile(std::string path){
    std::string str;
    //open file
    std::ifstream infile(path);

    //get length of file
    infile.seekg(0, std::ios::end);
    size_t length = infile.tellg();
    infile.seekg(0, std::ios::beg);

    str.resize(length);

    //read file
    infile.read(&str[0], length);

    return str;
}

void stringToFile(std::string buffer, std::string path){
    std::ofstream out(path);
    out << buffer;
    out.close();
}

const char* stringToBufferToSend(std::string str){
    return str.c_str();
}

// int main(){
//     std::string stringFile = pathFileToStringFile("teste.html");
//     stringToFile(stringFile, "output.html");
//     const char* buf = stringToBufferToSend(stringFile);
//     return 0;
// }

