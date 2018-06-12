//
// Created by El Khalil Bellakrid on 12/06/2018.
//

#ifndef WINLOSE_WINLOSEGLOBAL_H
#define WINLOSE_WINLOSEGLOBAL_H

#ifndef WINLOSE_EXPORT
    #if defined(_MSC_VER) && _MSC_VER <= 1990
        #include <winlose_export.h>
    #else
        #define WINLOSE_EXPORT
    #endif
#endif

#include "WinloseStruct.h"
namespace WinloseGlobal {
    extern WINLOSE_EXPORT const WinloseStruct WINLOSE;
};


#endif //WINLOSE_WINLOSEGLOBAL_H
