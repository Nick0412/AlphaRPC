cmake_minimum_required(VERSION 3.20)

project(AlphaRPC)

set(CMAKE_CXX_STANDARD 20)

add_library(
    LibA STATIC
    src/Server.cpp
    src/ServerBuilder.cpp
    src/DataChannel.cpp
    src/Common.cpp
    src/PosixWrapper.cpp
)
target_include_directories(
    LibA
    PUBLIC include
)

add_executable(
    ExeA
    src/MainServer.cpp
)
target_link_libraries(
    ExeA
    PUBLIC LibA
)