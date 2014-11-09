/*
 * Robot.hpp, part of BotLib
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

#ifndef BotLib_Robot_hpp_
#define BotLib_Robot_hpp_

#include <BotLib/Global.hpp>

BEGIN_NAMESPACE

/******************************************************************************
 *                                 Robot                                     *
 ******************************************************************************/

class Robot
{
public:
    // constructor
    Robot(void);
    // destructor
    virtual ~Robot(void);
    // access
    int getPwmFd(void) const;
private:
    int pwmFd_;
};

END_NAMESPACE

#endif // BotLib_Robot_hpp_
