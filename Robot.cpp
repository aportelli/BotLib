/*
 * Robot.cpp, part of BotLib
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

#include <BotLib/Robot.hpp>
#include <BotLib/includes.hpp>

using namespace std;
using namespace BotLib;

/******************************************************************************
 *                          Robot implementation                              *
 ******************************************************************************/
// constructor /////////////////////////////////////////////////////////////////
Robot::Robot(void)
{
    pwmFd_  = open(PWM_DEVICE_NAME, O_WRONLY);
    uartFd_ = open(UART_DEVICE_NAME, O_RDWR|O_SYNC);
}

// destructor //////////////////////////////////////////////////////////////////
Robot::~Robot(void)
{
    close(pwmFd_);
    close(uartFd_);
}

// access //////////////////////////////////////////////////////////////////////
int Robot::getPwmFd(void) const
{
    return pwmFd_;
}

int Robot::getUartFd(void) const
{
    return uartFd_;
}

// IO //////////////////////////////////////////////////////////////////////////
int Robot::open(const std::string name, const int mode)
{
    int fd;

    fd = ::open(name.c_str(), mode);
    if (fd == -1)
    {
        BOTLIB_ERROR(System, "impossible to open device '" + name + "'");
    }

    return fd;
}
