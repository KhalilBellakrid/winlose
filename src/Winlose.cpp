#include "Winlose.h"

#include <iostream>

Winlose::Winlose(const std::shared_ptr<api::WinloseNodeJS> &operation) : _operation(operation) {}

std::string api::Winlose::getVersion() {
    return "1.0.1";
}

int32_t Winlose::callAdd(int32_t lhs1, int32_t lhs2) {
    return _operation->add(lhs1, lhs2);
}

std::shared_ptr<api::Winlose> api::Winlose::newInstance(const std::shared_ptr<api::WinloseNodeJS> & operation) {
    return std::dynamic_pointer_cast<api::Winlose>(std::make_shared<::Winlose>(operation));
}