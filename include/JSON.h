//
// Created by vladl on 06/06/2020.
//
#pragma once
#include <string>

#ifndef UNTITLED_JSON_H
#define UNTITLED_JSON_H

class JSON;
class JSONNode;

class JSONNoDataException : public std::exception {
    const char* what() const noexcept override {
        return "No Data for input Label";
    }
};

class JSONInvalidString : public std::exception {
    const char* what() const noexcept override {
        return "Invalid parse string";
    }
};

#include "JSONNode.h"
#include "JSONArray.h"

class JSON{
private :
    std::list<JSONNode> *nodes;

    JSON* putMysteryData(const std::string&, const std::string&);

public :
    JSON();
    JSON(const JSON&);
    ~JSON();

    JSON* put(const std::string&, int);
    JSON* put(const std::string&, float);
    JSON* put(const std::string&, double);
    JSON* put(const std::string&, bool);
    JSON* put(const std::string&, char);
    JSON* put(const std::string&, long long);
    JSON* put(const std::string&, const JSON&);
    JSON* put(const std::string&, const JSONArray&);
    JSON* put(const std::string&, const std::string&);
    JSON* put(const std::string&, const char*);

    int getInt(const std::string&);
    bool getBoolean(const std::string&);
    char getChar(const std::string&);
    float getFloat(const std::string&);
    double getDouble(const std::string&);
    long long getLong(const std::string&);
    std::string getString(const std::string&);
    JSON getJSON(const std::string&);
    JSONArray getJSONArray(const std::string&);

    std::string toString();

    static JSON parse(const std::string&);
};
#endif //UNTITLED_JSON_H
