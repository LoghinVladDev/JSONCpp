//
// Created by vladl on 07/06/2020.
//

#include "../include/JSONNode.h"

#include <iostream>

int main(){
    try {
        auto *test = new JSONNode();

        test->setLabel("test1");
        test->putBoolean(true);
        test->putDouble(3.4);
        test->putFloat(3.5f);
        test->putChar('z');
        test->putString("test");
        test->putInt(3);
        test->putLong(5000000000000L);

        std::cout << test->toString();
    } catch (std::exception &e) {
        std::cout << e.what();
    }
}