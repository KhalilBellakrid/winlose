
#ifndef WINLOSE_EXPORT_H
#define WINLOSE_EXPORT_H

#ifdef WINLOSE_STATIC_DEFINE
#  define WINLOSE_EXPORT
#  define WINLOSE_NO_EXPORT
#else
#  ifndef WINLOSE_EXPORT
#    ifdef winlose_EXPORTS
        /* We are building this library */
#      define WINLOSE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define WINLOSE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef WINLOSE_NO_EXPORT
#    define WINLOSE_NO_EXPORT 
#  endif
#endif

#ifndef WINLOSE_DEPRECATED
#  define WINLOSE_DEPRECATED __declspec(deprecated)
#endif

#ifndef WINLOSE_DEPRECATED_EXPORT
#  define WINLOSE_DEPRECATED_EXPORT WINLOSE_EXPORT WINLOSE_DEPRECATED
#endif

#ifndef WINLOSE_DEPRECATED_NO_EXPORT
#  define WINLOSE_DEPRECATED_NO_EXPORT WINLOSE_NO_EXPORT WINLOSE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef WINLOSE_NO_DEPRECATED
#    define WINLOSE_NO_DEPRECATED
#  endif
#endif

#endif /* WINLOSE_EXPORT_H */
