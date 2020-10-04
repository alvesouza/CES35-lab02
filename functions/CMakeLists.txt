add_library(
        IP
        ip/ip_functions.h
        ip/ip_functions.cpp
)

target_include_directories(IP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})