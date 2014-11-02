/*
 * Motor.hpp, part of BotLib
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

#ifndef BotLib_Motor_hpp_
#define BotLib_Motor_hpp_

#include <BotLib/Global.hpp>
#include <BotLib/Device.hpp>

BEGIN_NAMESPACE

/******************************************************************************
 *                               Motor                                        *
 ******************************************************************************/

class Motor
{
public:
    // constructor
    Motor(const Device &device, const byte port);
    // destructor
    virtual ~Motor(void) = default;
    // access
    byte getPort(void) const;
    void setPort(const byte port);
    // IO
    void start(const byte power);
    void stop(void);
private:
    // IO
    void execute(const byte command);
    void execute(const byte command, const byte arg);
private:
    const Device &device_;
    byte         command_[3];
};

END_NAMESPACE

#endif // BotLib_Motor_hpp_
