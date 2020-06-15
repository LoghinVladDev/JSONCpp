//
// Created by vladl on 06/06/2020.
//

#include "../include/JSONNode.h"

JSONNode::JSONNode() {
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

int JSONNode::getInt() const noexcept(false) {
    if(this->dataType != dataTypes::INTEGER)
        throw JSONDataException();
    return (*((int*)this->data));
}

float JSONNode::getFloat() const noexcept(false) {
    if(this->dataType != dataTypes::FLOAT)
        throw JSONDataException();
    return (*((float*)this->data));
}

double JSONNode::getDouble() const noexcept(false) {
    if(this->dataType != dataTypes::DOUBLE)
        throw JSONDataException();
    return (*((double*)this->data));
}

std::string JSONNode::getString() const noexcept(false) {
    if(this->dataType != dataTypes::STRING)
        throw JSONDataException();
    return (*((std::string*)this->data));
}

long long JSONNode::getLong() const noexcept(false) {
    if(this->dataType != dataTypes::LONG)
        throw JSONDataException();
    return (*((long long*)this->data));
}

char JSONNode::getChar() const noexcept(false) {
    if(this->dataType != dataTypes::CHAR)
        throw JSONDataException();
    return (*((char*)this->data));
}

bool JSONNode::getBoolean() const noexcept(false) {
    if(this->dataType != dataTypes::BOOLEAN)
        throw JSONDataException();
    return (*((bool*)this->data));
}

JSON JSONNode::getJSONObject() const noexcept(false) {
    if(this->dataType != dataTypes::JSON_OBJECT)
        throw JSONDataException();
    return (*((JSON*)this->data));
}

JSONArray JSONNode::getJSONArray() const noexcept(false) {
    if(this->dataType != dataTypes::JSON_ARRAY)
        throw JSONDataException();
    return (*((JSONArray*)this->data));
}

std::string JSONNode::toString() noexcept(false) {
    if(this->label.empty())
        throw JSONLabelException();
    return "\"" + this->label + "\" : " + this->getDataString();
}

JSONNode::JSONNode(const JSONNode & otherNode) {
    this->data      = otherNode.getData();
    this->dataType  = otherNode.dataType;
    this->label     = otherNode.label;
}

void *JSONNode::getData() const noexcept(false){
    switch( this->dataType ){
        case JSON_ARRAY     : return (void*) new JSONArray(this->getJSONArray());
        case JSON_OBJECT    : return (void*) new JSON(this->getJSONObject());
        case DOUBLE         : return (void*) new double(this->getDouble());
        case FLOAT          : return (void*) new float(this->getFloat());
        case CHAR           : return (void*) new char(this->getChar());
        case LONG           : return (void*) new long long(this->getLong());
        case STRING         : return (void*) new std::string(this->getString());
        case INTEGER        : return (void*) new int(this->getInt());
        case BOOLEAN        : return (void*) new bool(this->getBoolean());
        default             : throw JSONDataException();
    }
}

JSONNode::~JSONNode() {
    free(this->data);
}

std::string JSONNode::getDataString() noexcept(false) {
    switch (this->dataType) {
        case BOOLEAN    : return this->getBoolean() ? "true" : "false";
        case INTEGER    : return std::to_string(this->getInt());
        case FLOAT      : return std::to_string(this->getFloat());
        case STRING     : return "\"" + this->getString() + "\"";
        case LONG       : return std::to_string(this->getLong());
        case CHAR       : return "\"" + std::string() + this->getChar() + "\"";
        case DOUBLE     : return std::to_string(this->getDouble());
        case JSON_ARRAY : return this->getJSONArray().toString();
        case JSON_OBJECT: return this->getJSONObject().toString();
        default         : throw JSONDataException();
    }
}
