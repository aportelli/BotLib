/*
 * UartSensor.hpp, part of BotLib
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

#ifndef BotLib_UartSensor_hpp_
#define BotLib_UartSensor_hpp_

#include <BotLib/Global.hpp>
#include <BotLib/Device.hpp>

BEGIN_NAMESPACE

/******************************************************************************
 *                               UartSensor                                   *
 ******************************************************************************/
class UartSensor: public Device
{
public:
    // constructor
    UartSensor(const Robot &robot, const byte port);
    // destructor
    virtual ~UartSensor(void) = default;
    // access
    void         configure(const sbyte connection, const sbyte type,
                           const sbyte mode);
    unsigned int readRaw(void) const;
private:
    UART *uart_;
    DEVCON dev;
};

END_NAMESPACE

#endif // BotLib_UartSensor_hpp_
