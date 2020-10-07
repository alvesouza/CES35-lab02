cmake_minimum_required(VERSION 3.17)
project(CES35_lab02)

set(CMAKE_CXX_STANDARD 11)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "-Og -fsanitize=address")
    message(GCC flags: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG})
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -static-libgcc -static-libstdc++")
    message(GCC flags: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE})
elseif (CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3")
    message(GCC flags: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
else () # DEFAULT build type
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -static-libgcc -static-libstdc++")
    message(GCC flags: ${CMAKE_CXX_FLAGS})
endif ()
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")
add_library(
        ip_functions
        functions/ip/ip_functions.h
        functions/ip/ip_functions.cpp
)
ADD_SUBDIRECTORY(functions)
ADD_SUBDIRECTORY(HTTP)
ADD_SUBDIRECTORY(web-server)
#add_executable(multi-thread.cpp echo-client.cpp echo-server.cpp HTTPReq.cpp HTTPReq.h HTTPResp.cpp HTTPResp.h web-server.cpp ip_functions.cpp )