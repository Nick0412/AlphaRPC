cmake_minimum_required(VERSION 3.20)

project(AlphaRPC)

add_library(
    Networking STATIC
    src/Networking/Endpoint.cpp
)
target_include_directories(
    Networking
    PUBLIC include
)