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

#define BEGIN_NAMESPACE namespace BotLib {
#define END_NAMESPACE }

BEGIN_NAMESPACE

typedef char byte;

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

END_NAMESPACE

#endif // BotLib_Global_hpp_
