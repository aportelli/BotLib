/*
 * Exceptions.hpp, part of BotLib
 *
 * Copyright (C) 2014 Antonin Portelli
 *
 * BotLib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BotLib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BotLib.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BotLib_Exceptions_hpp_
#define BotLib_Exceptions_hpp_

#include <stdexcept>
#ifndef BotLib_Global_hpp_
#include <BotLib/Global.hpp>
#endif

#define SRC_LOC strFrom(__FUNCTION__) + " at " + strFrom(__FILE__) + ":"\
                + strFrom(__LINE__)
#define BOTLIB_ERROR(exc,msg) throw(Exceptions::exc(msg, SRC_LOC))
#define BOTLIB_WARNING(msg) \
    std::cerr << Env::msgPrefix << "warning: " << msg\
              << " ("  << SRC_LOC << ")" << std::endl

#define DECL_EXC(name, base) \
class name: public base\
{\
    public:\
    name(std::string msg, std::string loc);\
}

BEGIN_NAMESPACE

namespace Exceptions
{
    // runtime errors
    DECL_EXC(Runtime, std::runtime_error);
    DECL_EXC(System, Runtime);
}

END_NAMESPACE

#endif // BotLib_Exceptions_hpp_
