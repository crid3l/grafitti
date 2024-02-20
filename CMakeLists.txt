cmake_minimum_required(VERSION 3.27)
project(kde-graffiti)

set(CMAKE_CXX_STANDARD 17)

set(APP_NAME "kde-graffiti")

configure_file(config.h.in config.h)

include_directories(${CMAKE_BINARY_DIR})

add_executable(kde-graffiti main.cpp
        config.h)
