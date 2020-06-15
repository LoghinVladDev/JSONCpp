//
// Created by vladl on 06/06/2020.
//
#pragma once
#include <string>
#include <list>
#include "JSONNode.h"
class JSONNode;
#ifndef UNTITLED_JSONARRAY_H
#define UNTITLED_JSONARRAY_H

class JSONArrayOutOfBounds : public std::exception {
    const char* what() const noexcept override {
        return "Data out of array bounds";
    }
};

class JSONArray{
private:
    std::list<JSONNode> *arrayList = nullptr;

public:
    JSONArray()                 noexcept (true);
    JSONArray(const JSONArray&) noexcept (true);
    ~JSONArray()                noexcept (true);

    JSONArray* putMysteryData(const std::string&) noexcept (true);

    JSONArray* put(int index, JSONNode&)          noexcept (true);
    JSONArray* put(int index, int)                noexcept (true);
    JSONArray* put(int index, bool)               noexcept (true);
    JSONArray* put(int index, char)               noexcept (true);
    JSONArray* put(int index, float)              noexcept (true);
    JSONArray* put(int index, double)             noexcept (true);
    JSONArray* put(int index, long long)          noexcept (true);
    JSONArray* put(int index, const char*)        noexcept (true);
    JSONArray* put(int index, const std::string&) noexcept (true);
    JSONArray* put(int index, const JSONArray&)   noexcept (true);
    JSONArray* put(int index, const JSON&)        noexcept (true);

    inline int length() noexcept (true) { return this->arrayList->size(); }

    JSONNode    get(int)            noexcept (false);
    int         getInt(int)         noexcept (false);
    bool        getBoolean(int)     noexcept (false);
    char        getChar(int)        noexcept (false);
    float       getFloat(int)       noexcept (false);
    double      getDouble(int)      noexcept (false);
    long long   getLong(int)        noexcept (false);
    std::string getString(int)      noexcept (false);
    JSON        getJSON(int)        noexcept (false);
    JSONArray   getJSONArray(int)   noexcept (false);

    std::string toString() noexcept (false);

    static JSONArray parse(const std::string&) noexcept (true);
};

#endif //UNTITLED_JSONARRAY_H