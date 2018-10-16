#ifndef WINLOSE_H
#define WINLOSE_H

#include "api/Winlose.hpp"

#include <string>
#ifndef WINLOSE_EXPORT
    #if defined(_MSC_VER) && _MSC_VER <= 1990
       #include <winlose_export.h>
    #else
       #define WINLOSE_EXPORT
    #endif
#endif

class Winlose : public api::Winlose {
};
#endif //WINLOSE_H