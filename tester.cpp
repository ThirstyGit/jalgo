/**
 * @author James Hedayet Zaman
 * */

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>

class tester {
    public:
    bool strToBool(std::string str) {
        return str == "true";
    }

    void funcTester(const std::vector<std::function<bool(std::string)>>& funcs, std::string fineName) {
        std::ifstream file(fineName);
        std::string str;
        funcs.at(0)("asd");
        while(getline(file, str)) {
            int index = str.find(' ', 2);
            if(funcs[std::stoi(str.substr(0,1)) - 1](str.substr(2, index - 2)) == strToBool(str.substr(index + 1, str.size() - index - 1))) {
                std::cout << "Working!\n";
            }
            else {
                std::cout << "Error\n";
            }
        }
    }
};