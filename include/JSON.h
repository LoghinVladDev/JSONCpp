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

    JSON* putMysteryData(const std::string&, const std::string&) noexcept (true);

public :
    JSON()              noexcept (true);
    JSON(const JSON&)   noexcept (true);
    ~JSON()             noexcept (true);

    JSON* put(const std::string&, int)                  noexcept (true);
    JSON* put(const std::string&, float)                noexcept (true);
    JSON* put(const std::string&, double)               noexcept (true);
    JSON* put(const std::string&, bool)                 noexcept (true);
    JSON* put(const std::string&, char)                 noexcept (true);
    JSON* put(const std::string&, long long)            noexcept (true);
    JSON* put(const std::string&, const JSON&)          noexcept (true);
    JSON* put(const std::string&, const JSONArray&)     noexcept (true);
    JSON* put(const std::string&, const std::string&)   noexcept (true);
    JSON* put(const std::string&, const char*)          noexcept (true);

    int         getInt      (const std::string&) noexcept (false);
    bool        getBoolean  (const std::string&) noexcept (false);
    char        getChar     (const std::string&) noexcept (false);
    float       getFloat    (const std::string&) noexcept (false);
    double      getDouble   (const std::string&) noexcept (false);
    long long   getLong     (const std::string&) noexcept (false);
    std::string getString   (const std::string&) noexcept (false);
    JSON        getJSON     (const std::string&) noexcept (false);
    JSONArray   getJSONArray(const std::string&) noexcept (false);

    std::string toString() noexcept (false);

    static JSON parse(const std::string&) noexcept (true);
};
#endif //UNTITLED_JSON_H
