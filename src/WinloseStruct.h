//
// Created by El Khalil Bellakrid on 12/06/2018.
//

#ifndef WINLOSE_WINLOSESTRUCT_H
#define WINLOSE_WINLOSESTRUCT_H



#include <string>
struct WinloseStruct {
    std::string name;

    WinloseStruct(const std::string &_name):name(_name)
    {}
    WinloseStruct(const WinloseStruct& cpy) {
        this->name = cpy.name;
    }
    WinloseStruct &operator=(const WinloseStruct&cpy) {
        this->name = cpy.name;
        return *this;
    }
    WinloseStruct() = default;
};



#endif //WINLOSE_WINLOSESTRUCT_H
