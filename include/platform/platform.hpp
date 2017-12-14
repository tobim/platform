#ifndef __PLATFORM_PLATFORM_HPP_
#define __PLATFORM_PLATFORM_HPP_

#include "boost/predef.h"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

namespace platform {

#if (BOOST_COMP_CLANG)
#define COMPILER_ "clang " TOSTRING(__clang_major__) "." TOSTRING(__clang_minor__) "." TOSTRING(__clang_patchlevel__)
#elif (BOOST_COMP_GNUC)
#define COMPILER_ "gcc " TOSTRING(__GNUC__) "." TOSTRING(__GNUC_MINOR__) "." TOSTRING(__GNUC_PATCHLEVEL__)
#else
#define COMPILER_ "unknown"
#endif

constexpr const char* compiler = COMPILER_;

//constexpr const char* get() {
//    return
//        "Compiler: " compiler "\n"
//        "Host:     " "Stub" "\n"
//        "Target:   " "Stub" "\n"
//        "Lang:     " "Stub" "\n"
//        "RT:       " "Stub" "\n"
//        "STL:      " "Stub" "\n"
//        ;
//}

struct link {

static const char* compiler;

}; // class link

}  // namespace platform

#endif // __PLATFORM_PLATFORM_HPP_
