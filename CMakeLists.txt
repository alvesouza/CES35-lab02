cmake_minimum_required(VERSION 3.17)
project(CES35_lab02)

set(CMAKE_CXX_STANDARD 11)

add_executable(CES35_lab02 main.cpp multi-thread.cpp echo-client.cpp echo-server.cpp showip.cpp)