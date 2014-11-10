/*
 * Exceptions.cpp, part of BotLib
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

#include <BotLib/Exceptions.hpp>
#include <BotLib/includes.hpp>

#ifndef ERR_SUFF
#define ERR_SUFF " (" + loc + ")"
#endif

#define CONST_EXC(name, init) \
name::name(string msg, string loc)\
:init\
{}

using namespace std;
using namespace BotLib;
using namespace Exceptions;

// runtime errors
CONST_EXC(Runtime, runtime_error(MSG_PREF + msg + ERR_SUFF))
CONST_EXC(System, Runtime("system error: " + msg, loc))
