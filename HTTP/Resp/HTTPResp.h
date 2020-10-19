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
    std::string bytecode;
    std::string status;
    std::string payload;
    bool emptyField;
    
public:
    HTTPResp(const char* bytecode);

    std::string getBytecode();

    std::string getStatus();

    std::string getPayload();

    /**
     * Salva o arquivo requisitado no atributo payload
     */
    void setPayload();

    void saveFile();

    /**
     * Faz o encode do objeto instanciado para bytes
     */
    std::string serialize();
    
    /**
     * Faz o parser dos atributos recebidos em bytecode
     */
    std::vector<std::string> getAttributes();

    /**
     *  Faz o parse de cada atributo HTTPReq,
     *  quando recebido um bytecode de requisição
     */
    void deserializeReq();

    /**
     *  Faz o parse de cada atributo HTTPResp,
     *  quando recebido um bytecode de resposta
     */
    void deserializeResp();

    ~HTTPResp();
};


#endif //CES35_LAB02_HTTPRESP_H
