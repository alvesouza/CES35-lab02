#ifndef CES35_LAB02_HTTPRESP_H
#define CES35_LAB02_HTTPRESP_H
#include <vector>
#include <string>

class HTTPResp {
private:
    // HTTPReq
    std::string host;
    std::string port;
    std::string method;
    std::string contentType;
    std::string fileName;

    // HTTPResp
    const char* bytecode;
    std::string status;
    std::string payload;
    
    /**
     * Salva o arquivo requisitado no atributo payload
     */
    void setPayload(std::string fileName, std::string contentType);

public:
    HTTPResp(const char* bytecode);

    const char* getBytecode();

    std::string getStatus();

    std::string getPayload();

    void saveFile();

    /**
     * Faz o encode do objeto instanciado para bytes
     */
    const char* encode();
    
    /**
     * Faz o parser dos atributos recebidos em bytecode
     */
    std::vector<std::string> getAttributes();

    /**
     *  Faz o parse de cada atributo HTTPReq,
     *  quando recebido um bytecode de requisição
     */
    void decodeReq();

    /**
     *  Faz o parse de cada atributo HTTPResp,
     *  quando recebido um bytecode de resposta
     */
    void decodeResp();

    ~HTTPResp();
};


#endif //CES35_LAB02_HTTPRESP_H
