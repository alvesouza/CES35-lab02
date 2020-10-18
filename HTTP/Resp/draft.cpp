#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
#include <vector>

int main(){

    std::vector<char> buffer;
    //open file
    std::ifstream infile("./teste.html");

    //get length of file
    infile.seekg(0, std::ios::end);
    size_t length = infile.tellg();
    infile.seekg(0, std::ios::beg);

    //read file
    buffer.resize(length);
    infile.read(&buffer[0], length);

    for (const char & c : buffer){
        std::cout << c;
    }
    std::cout << std::endl;

    std::ofstream out("output.html");
    out << &buffer[0];
    out.close();
    return 0;
}

