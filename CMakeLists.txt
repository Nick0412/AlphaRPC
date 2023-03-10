cmake_minimum_required(VERSION 3.20)

project(AlphaRPC)


add_library(
    Networking STATIC
    src/Networking/Endpoint.cpp
    src/Networking/ClientSocket.cpp
    src/Networking/DataSocket.cpp
    src/Networking/ServerSocket.cpp
)
target_include_directories(
    Networking
    PUBLIC include
)


add_executable(
    Client
    src/client.cpp
)
target_link_libraries(
    Client
    PUBLIC Networking
)


add_executable(
    Server
    src/server.cpp
)
target_link_libraries(
    Server
    PUBLIC Networking
)