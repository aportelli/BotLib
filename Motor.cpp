/*
 * Motor.cpp, part of BotLib
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

#include <BotLib/Motor.hpp>
#include <BotLib/includes.hpp>

using namespace std;
using namespace BotLib;

/******************************************************************************
 *                         Motor implementation                               *
 ******************************************************************************/
// constructor /////////////////////////////////////////////////////////////////
Motor::Motor(const Robot &robot, const byte port)
: Device(robot, port)
{}

// IO //////////////////////////////////////////////////////////////////////////
void Motor::start(const byte power)
{
    execute(opOUTPUT_POWER, power);
    execute(opOUTPUT_START);
}

void Motor::stop(void)
{
    execute(opOUTPUT_STOP);
}

void Motor::execute(const byte command)
{
    command_[0] = command;
    write(getRobot().getPwmFd(), command_, 2);
}

void Motor::execute(const byte command, const byte arg)
{
    command_[0] = command;
    command_[2] = arg;
    write(getRobot().getPwmFd(), command_, 3);
}
