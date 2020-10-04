//
// Created by pedro on 04/10/2020.
//

#ifndef CES35_LAB02_HTTPREQ_H
#define CES35_LAB02_HTTPREQ_H
#include <string>
#include <vector>
class HTTPReq {
    std::string url;
    HTTPReq();

public:
    void setURL(std::string url_to_be);
    std::vector<uint8_t> enconde();
};


#endif //CES35_LAB02_HTTPREQ_H
