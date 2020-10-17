add_executable(web-client web-client.cpp)
target_link_libraries(web-client PRIVATE IP)
target_link_libraries(web-client PRIVATE HTTPResp)
target_link_libraries(web-client PRIVATE HTTPReq)