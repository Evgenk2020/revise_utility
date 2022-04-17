cmake_minimum_required(VERSION 3.5)

project(revise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_libraries(-lcurl)

add_executable(revise main.cpp
    read_url.h read_url.cpp
    analizer.h analizer.cpp
    help.h help.cpp
    url_version.h)