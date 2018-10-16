#ifndef WINLOSE_H
#define WINLOSE_H

#include "api/Winlose.hpp"
#include "api/WinloseNodeJS.hpp"
#include <string>
#include <memory>
#include <cstdint>
#ifndef WINLOSE_EXPORT
    #if defined(_MSC_VER) && _MSC_VER <= 1990
       #include <winlose_export.h>
    #else
       #define WINLOSE_EXPORT
    #endif
#endif

class Winlose : public api::Winlose {
public:
    explicit Winlose(const std::shared_ptr<api::WinloseNodeJS> &operation);
    int32_t callAdd(int32_t lhs1, int32_t lhs2) override ;

private:
    std::shared_ptr<api::WinloseNodeJS> _operation;
};
#endif //WINLOSE_H