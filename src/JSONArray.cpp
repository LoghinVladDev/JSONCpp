//
// Created by vladl on 06/06/2020.
//

#include <iostream>
#include "../include/JSONArray.h"

JSONArray::JSONArray() noexcept (true){
    this->arrayList = new std::list<JSONNode>;
}

std::string JSONArray::toString() noexcept (false){
    std::string res;

    for(auto & it : *this->arrayList){
        try {
            res += it.getDataString() + ", ";
        } catch (std::exception & e) {
            std::cout << e.what();
        }
    }

    if(res.length() == 0)
        return "[]";

    return "[" + res.replace(res.length() - 2, 2, "") + "]";
}

JSONArray::JSONArray(const JSONArray &other) noexcept (true) {
    this->arrayList = new std::list<JSONNode>( *other.arrayList );
}

JSONArray::~JSONArray()  noexcept (true){
    delete this->arrayList;
}

JSONArray* JSONArray::put(int index, JSONNode & node) noexcept (true){
    if(index > this->arrayList->size())
        index = this->arrayList->size();

    int listIndex = 0;

    auto *front = new std::list<JSONNode>;

    for(; listIndex < index; listIndex++) {
        front->push_back(this->arrayList->front());
        this->arrayList->pop_front();
    }

    front->push_back(node);

    while( ! this->arrayList->empty() ){
        front->push_back(this->arrayList->front());
        this->arrayList->pop_front();
    }

    delete this->arrayList;
    this->arrayList = front;
    return this;
}

JSONArray* JSONArray::put(int index, int value) noexcept (true) {
    JSONNode inserted;
    inserted.putInt(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, bool value) noexcept (true) {
    JSONNode inserted;
    inserted.putBoolean(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, float value) noexcept (true) {
    JSONNode inserted;
    inserted.putFloat(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, double value) noexcept (true) {
    JSONNode inserted;
    inserted.putDouble(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, long long value) noexcept (true) {
    JSONNode inserted;
    inserted.putLong(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, const char * value) noexcept (true) {
    JSONNode inserted;
    inserted.putString(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, const std::string & value) noexcept (true) {
    JSONNode inserted;
    inserted.putString(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, const JSONArray & value) noexcept (true) {
    JSONNode inserted;
    inserted.putJSONArray(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, const JSON & value) noexcept (true) {
    JSONNode inserted;
    inserted.putJSONObject(value);
    this->put(index, inserted);
    return this;
}

JSONArray* JSONArray::put(int index, char value) noexcept (true) {
    JSONNode inserted;
    inserted.putChar(value);
    this->put(index, inserted);
    return this;
}

JSONNode JSONArray::get(int index) noexcept (false) {
    if(index < 0 || index >= this->arrayList->size())
        throw JSONArrayOutOfBounds();

    int internalIterator = 0;
    for( auto & it : *this->arrayList ){
        if(index == (internalIterator++) )
            return it;
    }

    throw JSONArrayOutOfBounds();
}

int JSONArray::getInt(int index) noexcept (false) {
    return this->get(index).getInt();
}

bool JSONArray::getBoolean(int index) noexcept (false) {
    return this->get(index).getBoolean();
}

char JSONArray::getChar(int index) noexcept (false) {
    return this->get(index).getChar();
}

float JSONArray::getFloat(int index) noexcept (false) {
    return this->get(index).getFloat();
}

double JSONArray::getDouble(int index) noexcept (false) {
    return this->get(index).getDouble();
}

long long JSONArray::getLong(int index) noexcept (false) {
    return this->get(index).getLong();
}

std::string JSONArray::getString(int index) noexcept (false) {
    return this->get(index).getString();
}

JSON JSONArray::getJSON(int index) noexcept (false) {
    return this->get(index).getJSONObject();
}

JSONArray JSONArray::getJSONArray(int index) noexcept (false) {
    return this->get(index).getJSONArray();
}

JSONArray JSONArray::parse(const std::string& data) noexcept (true) {
    JSONArray result;
    std::string copy = data;
    copy.replace(0, copy.find('[') + 1, "").replace(copy.rfind(']'), copy.length(), "");
//    std::cout << "Data : " << copy << '\n';

    while( ! copy.empty() ){
        while(copy[0] == ' ')
            copy.replace(0, 1, "");

        int arrayBracketCount = 0, objectBracketCount = 0, segmentLength = 0;
        std::string element;

        for(char i : copy){
            if(arrayBracketCount == 0 && objectBracketCount == 0 && i == ','){
                break;
            } else {
                if(i == '{')
                    objectBracketCount++;
                else if (i == '}')
                    objectBracketCount--;
                else if(i == '[')
                    arrayBracketCount++;
                else if(i == ']')
                    arrayBracketCount--;

                element += i;
                segmentLength++;
            }
        }

        copy.replace(0, segmentLength + 1, "");

        result.putMysteryData(element);
    }

//    std::cout << result.toString() << '\n';

    return result;
}

JSONArray* JSONArray::putMysteryData(const std::string & data) noexcept (true) {
    if( data[0] == '{' )
        this->put(this->length(), JSON::parse(data));
    else if( data[0] == '[' )
        this->put(this->length(), JSONArray::parse(data));
    else if( data.find('\"') != std::string::npos )
        this->put(
            this->length(),
            std::string(data)
                .replace(std::string(data).rfind('\"'), std::string(data).length(), "")
                .replace(0, std::string(data).find('\"') + 1, "")
        );
    else if( data.find('.') != std::string::npos )
        this->put(this->length(), std::strtod(data.c_str(), nullptr));
    else if( data.find("true") != std::string::npos || data.find("false") != std::string::npos )
        this->put(this->length(), data == "true");
    else
        this->put( this->length(), (int)std::strtol(data.c_str(), nullptr, 10) );

    return this;
}