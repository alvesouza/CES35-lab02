#ifndef CES35_LAB02_HTTPRESP_H
#define CES35_LAB02_HTTPRESP_H
#include <vector>
#include <string>

class HTTPResp {
private:
    std::string url;
    uint16_t port;
    std::string method;
    std::string status;
    std::string contentType;
    std::vector<uint8_t> bytecode;
    std::vector<uint8_t> obj;

public:
    HTTPResp(std::vector<uint8_t> bytecode){
        parse(bytecode);
    }

    void setUrl(std::vector<uint8_t>& bytecode);

    void setPort(std::vector<uint8_t>& bytecode);

    void setMethod(std::vector<uint8_t>& bytecode);

    void setContentType(std::vector<uint8_t>& bytecode);

    void setObj(std::vector<uint8_t>& bytecode);

    std::string getUrl();

    uint16_t getPort();

    std::string getMethod();

    std::string getContentType();

    std::vector<uint8_t> getObj();

    /**
     * Seta o status do código como:
     *  404: not found
     *  200: ok
     */
    void setStatusCode(int status);

    /**
     * Salva o arquivo requisitado no atributo obj
     */
    void setObj(std::string name);

    /**
     *  Faz o parse de cada atributo, quando recebido um bytecode
     */
    void parse(std::vector<uint8_t> bytecode);

    ~HTTPResp();
};


#endif //CES35_LAB02_HTTPRESP_H
