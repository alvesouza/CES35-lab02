add_library(
        HTTPReq
        Req/HTTPReq.h
        Req/HTTPReq.cpp
        ../functionals/Inc/constants.h)

add_library(
        HTTPResp
        Resp/HTTPResp.h
        Resp/HTTPResp.cpp
        ../functionals/Inc/constants.h)

target_link_libraries(HTTPResp PRIVATE IP)
target_link_libraries(HTTPReq PRIVATE IP)
target_include_directories(HTTPResp PUBLIC ./Resp)
target_include_directories(HTTPReq PUBLIC ./Req)