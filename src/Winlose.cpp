#include "Winlose.h"
#include "WinloseGlobal.h"

#include <iostream>

std::string Winlose::getVersion() {
    std::cout<<" >> Extern struct: "<<WinloseGlobal::WINLOSE.name<<std::endl;
    return "1.0.0";
}