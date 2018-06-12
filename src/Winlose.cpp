#include "Winlose.h"
#include "WinloseStruct.h"

#include <iostream>

std::string Winlose::getVersion() {
    std::cout<<" >> Extern struct: "<<WINLOSE.name<<std::endl;
    return "1.0.0";
}