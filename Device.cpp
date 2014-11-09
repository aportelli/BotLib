/*
 * Device.cpp, part of BotLib
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

#include <BotLib/Device.hpp>
#include <BotLib/includes.hpp>

using namespace std;
using namespace BotLib;

/******************************************************************************
 *                          Device implementation                             *
 ******************************************************************************/
// constructor /////////////////////////////////////////////////////////////////
Device::Device(const Robot &robot, const byte port)
: robot_(robot)
, port_(port)
{}

// access //////////////////////////////////////////////////////////////////////
byte Device::getPort(void) const
{
    return port_;
}

void Device::setPort(const byte port)
{
    port_ = port;
}

const Robot & Device::getRobot(void)
{
    return robot_;
}
