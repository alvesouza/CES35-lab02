add_library(
        IP
        Inc/ip_functions.h
        Src/ip_functions.cpp
        Inc/constants.h)
#include_directories(Inc)
target_include_directories(IP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)
#target_include_directories(IP PUBLIC ../functionals)