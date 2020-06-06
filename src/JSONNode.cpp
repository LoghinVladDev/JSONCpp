//
// Created by vladl on 06/06/2020.
//

#include "../include/JSONNode.h"
#include <cstring>

JSONNode::JSONNode() {
    this->next = nullptr;
    this->data = nullptr;
    this->dataType = dataTypes::UNDEFINED;
}

void JSONNode::putInt(const int value) noexcept(true){
    this->data = (void*) new int(value);
    this->dataType = dataTypes::INTEGER;
}

void JSONNode::putFloat(const float value) noexcept(true){
    this->data = (void*) new float(value);
    this->dataType = dataTypes::FLOAT;
}

void JSONNode::putDouble(const double value) noexcept(true){
    this->data = (void*) new double(value);
    this->dataType = dataTypes::DOUBLE;
}

void JSONNode::putString(const std::string& value) noexcept(true){
    this->data = (void*) new std::string(value);
    this->dataType = dataTypes::STRING;
}

void JSONNode::putString(const char* value) noexcept(true){
    this->data = (void*) new std::string(value);
    this->dataType = dataTypes::STRING;
}

void JSONNode::putLong(const long long value) noexcept(true){
    this->data = (void*) new long long(value);
    this->dataType = dataTypes::LONG;
}

void JSONNode::putChar(const char value) noexcept(true){
    this->data = (void*) new char(value);
    this->dataType = dataTypes::CHAR;
}

void JSONNode::putBoolean(const bool value) noexcept(true){
    this->data = (void*) new bool(value);
    this->dataType = dataTypes::BOOLEAN;
}

void JSONNode::putJSONObject(const JSON& value) noexcept(true){
    this->data = (void*) new JSON(value);
    this->dataType = dataTypes::JSON_OBJECT;
}

void JSONNode::putJSONArray(const JSONArray& value) noexcept(true){
    this->data = (void*) new JSONArray(value);
    this->dataType = dataTypes::JSON_ARRAY;
}

int JSONNode::getInt() noexcept(false) {
    if(this->dataType != dataTypes::INTEGER)
        throw JSONDataException();
    return (*((int*)this->data));
}

float JSONNode::getFloat() noexcept(false) {
    if(this->dataType != dataTypes::FLOAT)
        throw JSONDataException();
    return (*((float*)this->data));
}

double JSONNode::getDouble() noexcept(false) {
    if(this->dataType != dataTypes::DOUBLE)
        throw JSONDataException();
    return (*((double*)this->data));
}

std::string JSONNode::getString() noexcept(false) {
    if(this->dataType != dataTypes::STRING)
        throw JSONDataException();
    return (*((std::string*)this->data));
}

long long JSONNode::getLong() noexcept(false) {
    if(this->dataType != dataTypes::LONG)
        throw JSONDataException();
    return (*((long long*)this->data));
}

char JSONNode::getChar() noexcept(false) {
    if(this->dataType != dataTypes::CHAR)
        throw JSONDataException();
    return (*((char*)this->data));
}

bool JSONNode::getBoolean() noexcept(false) {
    if(this->dataType != dataTypes::BOOLEAN)
        throw JSONDataException();
    return (*((bool*)this->data));
}

JSON JSONNode::getJSONObject() noexcept(false) {
    if(this->dataType != dataTypes::JSON_OBJECT)
        throw JSONDataException();
    return (*((JSON*)this->data));
}

JSONArray JSONNode::getJSONArray() noexcept(false) {
    if(this->dataType != dataTypes::JSON_ARRAY)
        throw JSONDataException();
    return (*((JSONArray*)this->data));
}

std::string JSONNode::toString() noexcept(false) {
    std::string result = "{ \"" + this->label + "\" : ";

    std::string nodeData;
    switch (this->dataType) {
        case BOOLEAN    : nodeData = this->getBoolean() ? "true" : "false";         break;
        case INTEGER    : nodeData = std::to_string(this->getInt());            break;
        case FLOAT      : nodeData = std::to_string(this->getFloat());          break;
        case STRING     : nodeData = "\"" + this->getString() + "\"";               break;
        case LONG       : nodeData = std::to_string(this->getLong());           break;
        case CHAR       : nodeData = "\"" + std::string() + this->getChar() + "\""; break;
        case DOUBLE     : nodeData = std::to_string(this->getDouble());         break;
        case JSON_ARRAY : nodeData = this->getJSONArray().toString();               break;
        case JSON_OBJECT: nodeData = this->getJSONObject().toString();              break;
        case UNDEFINED  : throw JSONDataException();
    }

    return result + nodeData + " }";
}
