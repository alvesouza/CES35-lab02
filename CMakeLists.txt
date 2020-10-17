cmake_minimum_required(VERSION 3.0)
project(CES35_lab02)

set(CMAKE_CXX_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
#diretorios à criar os arquivos
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")#arquivo binarios
#add_library(
#        ip_functions
#        functions/ip/ip_functions.h
#        functions/ip/ip_functions.cpp
#)
ADD_SUBDIRECTORY(functions)#adciona diretório na compilação
ADD_SUBDIRECTORY(HTTP)
ADD_SUBDIRECTORY(Server)
ADD_SUBDIRECTORY(Client)
#add_executable(multi-thread.cpp echo-client.cpp echo-server.cpp HTTPReq.cpp HTTPReq.h HTTPResp.cpp HTTPResp.h web-server.cpp ip_functions.cpp )