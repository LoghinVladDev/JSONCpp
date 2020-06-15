//
// Created by vladl on 07/06/2020.
//

#include "../include/JSON.h"
#include <iostream>

int main(){
    auto* array = new JSONArray();

    array->put(2, 1);
    array->put(3, 20.5f);
    array->put(0, "plm");

    std::cout << array->toString() << '\n';

    auto* node = new JSONNode();
    node->putJSONArray(*array);
    node->setLabel("someArray");

    std::cout << node->toString();

    delete node;
    delete array;
}