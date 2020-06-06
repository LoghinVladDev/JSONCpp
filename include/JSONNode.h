//
// Created by vladl on 06/06/2020.
//
#pragma once
#include <string>
#include <exception>
#include "JSON.h"
#include "JSONArray.h"

#ifndef UNTITLED_JSONNODE_H
#define UNTITLED_JSONNODE_H

class JSONDataException : public std::exception{
    const char* what () const throw() {
        return "Invalid JSON Data";
    }
};

class JSONNode{
private:
    JSONNode* next;
    std::string label;

    enum dataTypes{
        STRING,
        INTEGER,
        FLOAT,
        DOUBLE,
        LONG,
        CHAR,
        BOOLEAN,
        JSON_OBJECT,
        JSON_ARRAY,
        UNDEFINED
    };

    dataTypes dataType;

    void* data;

public :
    JSONNode();

    void putInt         (const int)         noexcept(true);
    void putFloat       (const float)       noexcept(true);
    void putDouble      (const double)      noexcept(true);
    void putString      (const std::string&)noexcept(true);
    void putString      (const char*)       noexcept(true);
    void putLong        (const long long)   noexcept(true);
    void putChar        (const char)        noexcept(true);
    void putBoolean     (const bool)        noexcept(true);
    void putJSONObject  (const JSON&)       noexcept(true);
    void putJSONArray   (const JSONArray&)  noexcept(true);

    int         getInt          ()  noexcept(false);
    float       getFloat        ()  noexcept(false);
    double      getDouble       ()  noexcept(false);
    std::string getString       ()  noexcept(false);
    long long   getLong         ()  noexcept(false);
    char        getChar         ()  noexcept(false);
    bool        getBoolean      ()  noexcept(false);
    JSON        getJSONObject   ()  noexcept(false);
    JSONArray   getJSONArray    ()  noexcept(false);

    inline JSONNode*    getNext()               noexcept(true) { return this->next; }
    inline void         setNext(JSONNode* node) noexcept(true) { this->next = node; }

    inline void         setLabel(const std::string& objectLabel) noexcept(true) { this->label = objectLabel; }
    inline void         setLabel(const char* labelCStr)          noexcept(true) { this->label = std::string(labelCStr); }
    inline std::string  getLabel()                               noexcept(true) { return this->label; }

    std::string toString() noexcept(false);
};

#endif //UNTITLED_JSONNODE_H
