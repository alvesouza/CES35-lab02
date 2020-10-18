#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
#project(web-server)

add_executable(web-server web-server.cpp ../functionals/Inc/constants.h)
target_link_libraries(web-server PRIVATE IP)
target_link_libraries(web-server PRIVATE HTTPResp)
target_link_libraries(web-server PRIVATE HTTPReq)
target_link_libraries(web-server PRIVATE Threads::Threads)