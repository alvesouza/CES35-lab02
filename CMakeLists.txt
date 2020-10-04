cmake_minimum_required(VERSION 3.17)
project(CES35_lab02)

set(CMAKE_CXX_STANDARD 11)
add_library(
        ip_functions
        functions/ip/ip_functions.h
        functions/ip/ip_functions.cpp
)
ADD_SUBDIRECTORY(functions)
ADD_SUBDIRECTORY(HTTP)
ADD_SUBDIRECTORY(web-server)
#add_executable(multi-thread.cpp echo-client.cpp echo-server.cpp HTTPReq.cpp HTTPReq.h HTTPResp.cpp HTTPResp.h web-server.cpp ip_functions.cpp )