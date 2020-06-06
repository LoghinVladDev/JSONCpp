cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        defaultMain main.cpp
        include/JSON.h
        src/JSON.cpp
        include/JSONNode.h
        src/JSONNode.cpp
        include/JSONArray.h
        src/JSONArray.cpp
)

add_executable(
        nodeTest src/NodeTest.cpp
        include/JSON.h
        src/JSON.cpp
        include/JSONNode.h
        src/JSONNode.cpp
        include/JSONArray.h
        src/JSONArray.cpp
)