//
// Created by 罗潇阳 on 2023/10/11.
//

#ifndef CPPDB_LOGGER_HPP
#define CPPDB_LOGGER_HPP

#include "./String.hpp"
#include "../../include/easylogging++/easylogging++.h"

class Logger {
public:
    static bool GLOBAL(String s);
    static bool TRACE(String s);
    static bool DEBUG(String s);
    static bool FATAL(String s);
    static bool ERROR(String s);
    static bool WARNING(String s);
    static bool INFO(String s);
    static bool VERBOSE(String s);
    static bool UNKNOWN(String s);
};

#endif //CPPDB_LOGGER_HPP
