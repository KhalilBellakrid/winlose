add_library(winlose SHARED Winlose.cpp Winlose.h api/Winlose.hpp)

if(MSVC)
    include(GenerateExportHeader)
    generate_export_header(winlose EXPORT_MACRO_NAME WINLOSE_EXPORT
            EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/winlose_export.h)
    target_include_directories(winlose PUBLIC .)
endif(MSVC)
