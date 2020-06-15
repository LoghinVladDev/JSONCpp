//
// Created by vladl on 06/06/2020.
//
#include <iostream>
#include "../include/JSON.h"

JSON::JSON() noexcept (true){
    this->nodes = new std::list<JSONNode>;
}

JSON::JSON(const JSON &other) noexcept (true){
    this->nodes = new std::list<JSONNode> ( *other.nodes );
}

JSON::~JSON() noexcept (true){
    delete this->nodes;
}

std::string JSON::toString() noexcept (false){
    std::string res;

    for ( auto & it : *this->nodes ) {
        res += it.toString() + ", ";
    }

    if(res.length() == 0)
        return "{}";

    return "{" + res.replace(res.length() - 2, 2, "") + "}";
}

JSON *JSON::put(const std::string & label, int data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putInt(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, float data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putFloat(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, double data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putDouble(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, bool data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putBoolean(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, char data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putChar(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, long long data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putLong(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, const JSON & data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putJSONObject(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, const JSONArray & data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putJSONArray(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, const std::string & data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putString(data);

    this->nodes->push_back(nodeData);

    return this;
}

JSON *JSON::put(const std::string & label, const char * data) noexcept (true){
    JSONNode nodeData;
    nodeData.setLabel(label);
    nodeData.putString(data);

    this->nodes->push_back(nodeData);

    return this;
}

int JSON::getInt(const std::string & label) noexcept (false){
    for (auto &it : *this->nodes)
        if (it.getLabel() == label)
            return it.getInt();

    throw JSONNoDataException();
}

bool JSON::getBoolean(const std::string & label) noexcept (false){
    for (auto &it : *this->nodes)
        if (it.getLabel() == label)
            return it.getBoolean();


    throw JSONNoDataException();
}

char JSON::getChar(const std::string & label) noexcept (false){
    for (auto &it : *this->nodes)
        if (it.getLabel() == label)
            return it.getChar();

    throw JSONNoDataException();
}

float JSON::getFloat(const std::string & label) noexcept (false){
    for( auto & it : *this->nodes )
        if( it.getLabel() == label )
            return it.getFloat();

    throw JSONNoDataException();
}

double JSON::getDouble(const std::string & label) noexcept (false){
    for( auto & it : *this->nodes )
        if( it.getLabel() == label )
            return it.getDouble();

    throw JSONNoDataException();
}

long long JSON::getLong(const std::string & label) noexcept (false){
    for( auto & it : *this->nodes )
        if( it.getLabel() == label )
            return it.getLong();

    throw JSONNoDataException();
}

std::string JSON::getString(const std::string & label) noexcept (false){
    for( auto & it : *this->nodes )
        if( it.getLabel() == label )
            return it.getString();

    throw JSONNoDataException();
}

JSON JSON::getJSON(const std::string & label) noexcept (false){
    for( auto & it : *this->nodes )
        if( it.getLabel() == label )
            return it.getJSONObject();

    throw JSONNoDataException();
}

JSONArray JSON::getJSONArray(const std::string & label) noexcept (false){
    for( auto & it : *this->nodes )
        if( it.getLabel() == label )
            return it.getJSONArray();

    throw JSONNoDataException();
}

JSON JSON::parse(const std::string & jsonString) noexcept (true){
    JSON result;

    std::string copy = jsonString;

    copy.replace(0, copy.find('{') + 1, "");
    copy.replace(copy.rfind('}'), copy.length(), "" );

    while(!copy.empty()) {
        std::string label = copy
                .substr(0, copy.find(':'));

        label = label
                .replace(0, label.find('\"') + 1, "")
                .replace(label.rfind('\"'), label.length(), "");

        std::string data, fullData = copy.substr(copy.find(':') + 1, copy.length());
        int arrayBracketCount = 0, objectBracketCount = 0, segmentLength = 0;

        while(fullData[0] == ' ')
            fullData.replace(0, 1, "");

        for (char i : fullData) {
            if (arrayBracketCount == 0 && objectBracketCount == 0 && i == ',') {
                break;
            } else {
                if (i == '{')
                    objectBracketCount++;
                else if (i == '}')
                    objectBracketCount--;
                else if (i == '[')
                    arrayBracketCount++;
                else if (i == ']')
                    arrayBracketCount--;

                data += i;
                segmentLength++;
            }
        }

        fullData.replace(0, segmentLength + 1, "");

        result.putMysteryData(label, data);

        copy = fullData;
    }

//    std::cout << result.toString();

    return result;
}

JSON *JSON::putMysteryData(const std::string & label, const std::string& data) noexcept (true) {
//    std::cout << label << ' ' << data << '\n';

    if( data[0] == '{' )
        this->put(label, JSON::parse(data));
    else if( data[0] == '[' )
        this->put(label, JSONArray::parse(data));
    else if(data.find('\"') != std::string::npos)
        this->put(
            label,
            std::string(data)
                .replace(std::string(data).rfind('\"'), std::string(data).length(), "")
                .replace(0, std::string(data).find('\"') + 1, "")
        );
    else if(data.find('.') != std::string::npos)
        this->put(label,std::strtod(data.c_str(), nullptr));
    else if(data.find("true") != std::string::npos || data.find("false") != std::string::npos)
        this->put(label, data == "true");
    else
        this->put(label, (int)std::strtol(data.c_str(), nullptr, 10));

    return this;
}

