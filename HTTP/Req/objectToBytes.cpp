#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
#include <vector>
#include <map>
#include <assert.h>

class Clock {
public:
    int hour;
    int minute;
    std::string tail;

    Clock (int h=0, int m=0, std::string s="0"){
        this->hour = h;
        this->minute = m;
        this->tail = s;
    }

    std::string toString(){
        std::string str = "";
        str += std::to_string(this->hour) + ":" + std::to_string(this->minute) + ":" + this->tail + ":";
        return str;
    }

    void toObject(std::string str){
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

        this->hour = stoi(attributes[0]);
        this->minute = stoi(attributes[1]);
        this->tail = attributes[2];
    }
};

int main(){
    Clock obj(5,4,"3sd");
    std::cout << obj.toString() << std::endl;
    std::cout << obj.toString().c_str() << std::endl;
    Clock obj2;
    obj2.toObject(obj.toString());

    std::cout << obj2.hour << ", " << obj2.minute << ", " << obj2.tail << std::endl;

    return 0;
}