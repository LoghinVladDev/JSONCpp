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
        nodeTest configurations/NodeTest.cpp
        include/JSON.h
        src/JSON.cpp
        include/JSONNode.h
        src/JSONNode.cpp
        include/JSONArray.h
        src/JSONArray.cpp
)

add_executable(
        arrayTest configurations/arrayTest.cpp
        include/JSON.h
        src/JSON.cpp
        include/JSONNode.h
        src/JSONNode.cpp
        include/JSONArray.h
        src/JSONArray.cpp
)

add_executable(
        objectTest configurations/objTest.cpp
        include/JSON.h
        src/JSON.cpp
        include/JSONNode.h
        src/JSONNode.cpp
        include/JSONArray.h
        src/JSONArray.cpp
)

add_executable(
        parseTest configurations/parseTest.cpp
        include/JSON.h
        src/JSON.cpp
        include/JSONNode.h
        src/JSONNode.cpp
        include/JSONArray.h
        src/JSONArray.cpp
)

add_executable( sub3 probleme/bacNumere.cpp )