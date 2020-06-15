//
// Created by vladl on 15/06/2020.
//

#include <iostream>
#include "../include/JSON.h"

int main(){

    auto *obj = new JSON;

    auto* array = new JSONArray();

    array->put(2, 1);
    array->put(3, 20.5f);
    array->put(0, "test");

    obj->put("ex1", 1);
    obj->put("ex2", 1.5);
    obj->put("ex3", 1.4f);
    obj->put("ex4", true);
    obj->put("ex5", "test2");
    obj->put("ex6", *array);

    auto *anotherObj = new JSON;

    anotherObj->put("sub1", *array);
    anotherObj->put("sub2", "pana mea");

    obj->put("ex7", *anotherObj);

    std::cout << obj->toString() << '\n';

    std::cout << obj->getJSON("ex7").toString() << '\n';
    std::cout << obj->getJSONArray("ex6").toString() << '\n';
    std::cout << obj->getString("ex5") << '\n';
    std::cout << obj->getFloat("ex3") << '\n';

    std::cout << obj->getJSONArray("ex6").getString(0);

    delete obj;
    delete anotherObj;
    delete array;

}