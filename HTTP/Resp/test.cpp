#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdint>

#include "./HTTPResp.cpp"

int main(){
    HTTPResp resp("GET:localhost:4000:index:html");

    resp.deserializeReq();
    std::vector<std::string> attributes = resp.getAttributes();
    for (auto & at : attributes)
        std::cout << at << std::endl;
    resp.setPayload();
    std::cout << resp.getPayload() << std::endl;
    resp.saveFile();
    std::cout << resp.serialize() << std::endl;
    resp.deserializeResp();

    return 0;
}