#include <iostream>
#include "functions/Inc/ip_functions.h"

int main(int argc, char *argv[]) {
    std::cout << "teste ip adress = "<< get_ip_from_hostname(argv[1]) << std::endl;
    return 0;
}
