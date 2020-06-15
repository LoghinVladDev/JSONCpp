//
// Created by vladl on 06/06/2020.
//
#pragma once
#include <string>
#include <exception>

class JSONArray;

#include "JSON.h"
#include "JSONArray.h"

#ifndef UNTITLED_JSONNODE_H
#define UNTITLED_JSONNODE_H

class JSONDataException : public std::exception{
    const char* what () const noexcept override {
        return "Invalid JSON Data";
    }
};

class JSONLabelException : public std::exception {
    const char* what () const noexcept override {
        return "JSON node must have label";
    }
};

class JSONNode{
private:
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
    std::string label;
    void* data;

public :
    JSONNode()                  noexcept(true);
    JSONNode(const JSONNode&)   noexcept(true);

    ~JSONNode()                 noexcept(true);

    inline dataTypes getDataType() noexcept(true) { return this->dataType; }

    void putInt         (int)               noexcept(true);
    void putFloat       (float)             noexcept(true);
    void putDouble      (double)            noexcept(true);
    void putString      (const std::string&)noexcept(true);
    void putString      (const char*)       noexcept(true);
    void putLong        (long long)         noexcept(true);
    void putChar        (char)              noexcept(true);
    void putBoolean     (bool)              noexcept(true);
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

    int         getInt          ()  const   noexcept(false);
    float       getFloat        ()  const   noexcept(false);
    double      getDouble       ()  const   noexcept(false);
    std::string getString       ()  const   noexcept(false);
    long long   getLong         ()  const   noexcept(false);
    char        getChar         ()  const   noexcept(false);
    bool        getBoolean      ()  const   noexcept(false);
    JSON        getJSONObject   ()  const   noexcept(false);
    JSONArray   getJSONArray    ()  const   noexcept(false);

    std::string getDataString() noexcept(false);

    void* getData() const noexcept(false);

    inline void         setLabel(const std::string& objectLabel) noexcept(true) { this->label = objectLabel; }
    inline void         setLabel(const char* labelCStr)          noexcept(true) { this->label = std::string(labelCStr); }
    inline std::string  getLabel()                               noexcept(true) { return this->label; }

    std::string toString() noexcept(false);
};

#endif //UNTITLED_JSONNODE_H
