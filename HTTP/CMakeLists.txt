add_library(
        HTTPReq
        Req/HTTPReq.h
        Req/HTTPReq.cpp
)

add_library(
        HTTPResp
        Resp/HTTPResp.h
        Resp/HTTPResp.cpp
)

target_include_directories(HTTPResp PUBLIC ./Resp)
target_include_directories(HTTPReq PUBLIC ./Req)