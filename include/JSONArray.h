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
    JSONArray();
    JSONArray(const JSONArray&);
    ~JSONArray();

    void putMysteryData(const std::string&);

    void put(int index, JSONNode&);
    void put(int index, int);
    void put(int index, bool);
    void put(int index, char);
    void put(int index, float);
    void put(int index, double);
    void put(int index, long long);
    void put(int index, const char*);
    void put(int index, const std::string&);
    void put(int index, const JSONArray&);
    void put(int index, const JSON&);

    inline int length() { return this->arrayList->size(); }

    JSONNode get(int);
    int getInt(int);
    bool getBoolean(int);
    char getChar(int);
    float getFloat(int);
    double getDouble(int);
    long long getLong(int);
    std::string getString(int);
    JSON getJSON(int);
    JSONArray getJSONArray(int);

    std::string toString();

    static JSONArray parse(const std::string&);
};

#endif //UNTITLED_JSONARRAY_H