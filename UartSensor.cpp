/*
 * UartSensor.cpp, part of BotLib
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

#include <BotLib/UartSensor.hpp>
#include <BotLib/includes.hpp>

using namespace std;
using namespace BotLib;

/******************************************************************************
 *                       UartSensor implementation                            *
 ******************************************************************************/
// constructor /////////////////////////////////////////////////////////////////
UartSensor::UartSensor(const Robot &robot, const byte port)
: Device(robot, port)
{
    uart_ = (UART*)mmap(0, sizeof(UART), PROT_READ|PROT_WRITE,
                        MAP_FILE|MAP_SHARED, getRobot().getUartFd(), 0);
    if (uart_ == MAP_FAILED)
    {
        BOTLIB_ERROR(System, "UART device map failed");
    }
}

// access //////////////////////////////////////////////////////////////////////
unsigned int UartSensor::readRaw(void) const
{
    unsigned int p = static_cast<unsigned int>(getPort());

    return static_cast<unsigned int>(uart_->Raw[p][uart_->Actual[p]][0]);
}

void UartSensor::configure(const sbyte connection, const sbyte type,
                           const sbyte mode)
{
    unsigned int p = static_cast<unsigned int>(getPort());
    DEVCON       conf;

    conf.Connection[p] = connection;
    conf.Type[p]       = type;
    conf.Mode[p]       = mode;
    ioctl(getRobot().getUartFd(), UART_SET_CONN, &conf);
}
