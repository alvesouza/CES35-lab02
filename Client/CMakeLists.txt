add_executable(web-client web-client.cpp ../functionals/Inc/constants.h)
target_link_libraries(web-client PRIVATE IP)
target_link_libraries(web-client PRIVATE HTTPResp)
target_link_libraries(web-client PRIVATE HTTPReq)
target_link_libraries(web-client PRIVATE Threads::Threads)