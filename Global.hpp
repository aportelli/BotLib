/*
 * Global.hpp, part of Botlib
 *
 * Copyright (C) 2014 Antonin Portelli
 *
 * LatAnalyze 3 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Botlib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Botlib.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BotLib_Global_hpp_
#define BotLib_Global_hpp_

#include <string>
#include <sstream>
#include <cstdlib>
#include <BotLib/lms2012/lms2012.h>

#define BEGIN_NAMESPACE namespace BotLib {
#define END_NAMESPACE }

#define MSG_PREF "[BotLib] "

BEGIN_NAMESPACE

typedef char          byte;
typedef signed char   sbyte;
typedef unsigned char ubyte;

class OutPort
{
public:
    enum: byte
    {
        nothing = 0,
        A       = 0x01,
        B       = 0x02,
        C       = 0x04,
        D       = 0x08
    };
};

class InPort
{
public:
    enum: byte
    {
        nothing = 0,
        P1      = 0,
        P2      = 1,
        P3      = 2,
        P4      = 3
    };
};

// String conversions //////////////////////////////////////////////////////////
template <typename T>
inline T strTo(const std::string &str)
{
    T buf;
    std::istringstream stream(str);

    stream >> buf;

    return buf;
}

// optimized specializations
template <>
inline float strTo<float>(const std::string &str)
{
    return strtof(str.c_str(), (char **)NULL);
}
template <>
inline double strTo<double>(const std::string &str)
{
    return strtod(str.c_str(), (char **)NULL);
}
template <>
inline int strTo<int>(const std::string &str)
{
    return (int)(strtol(str.c_str(), (char **)NULL, 10));
}
template <>
inline long strTo<long>(const std::string &str)
{
    return strtol(str.c_str(), (char **)NULL, 10);
}
template <>
inline std::string strTo<std::string>(const std::string &str)
{
    return str;
}

template <typename T>
inline std::string strFrom(const T x)
{
    std::ostringstream stream;

    stream << x;

    return stream.str();
}

END_NAMESPACE

#include <BotLib/Exceptions.hpp>

#endif // BotLib_Global_hpp_
