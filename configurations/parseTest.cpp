//
// Created by vladl on 15/06/2020.
//

#include "../include/JSON.h"
#include <iostream>

int main(){
    std::string str = R"({"ex1" : 1, "ex2" : 1.500000, "ex3" : 1.400000, "ex4" : true, "ex5" : "test2", "ex6" : ["test", 1, 20.500000], "ex7" : {"sub1" : ["test", 1, 20.500000], "sub2" : "pana mea"}})";

    JSON parsed = JSON::parse(str);

    std::cout << parsed.toString() << '\n';
    std::cout << parsed.getString("ex5") << '\n';
    std::cout << parsed.getJSONArray("ex6").getInt(1) << '\n';
    std::cout << parsed.getJSON("ex7").getString("sub2") << '\n';
    std::cout << parsed.getJSON("ex7").getJSONArray("sub1").getString(0) << '\n';
}

