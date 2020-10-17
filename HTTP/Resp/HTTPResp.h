//
// Created by pedro on 04/10/2020.
//

#ifndef CES35_LAB02_HTTPRESP_H
#define CES35_LAB02_HTTPRESP_H
#include <vector>
#include <string>
class HTTPResp {

public:
    void setStatusCode(int status);
    void parse(std::vector<uint8_t> bytecode);
};


#endif //CES35_LAB02_HTTPRESP_H
