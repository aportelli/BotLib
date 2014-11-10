/*
 * test.cpp, part of BotLib
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

#include <iostream>
#include <unistd.h>
#include <BotLib/Motor.hpp>
#include <BotLib/UartSensor.hpp>

using namespace std;
using namespace BotLib;

int main(void)
{
    Robot      robot;
    Motor      motor(robot, OutPort::A);
    UartSensor sensor(robot, InPort::P1);

    cout << "-- testing motor on port A..." << endl;
    for (int p = 10; p <= 100; p += 10)
    {
        cout << "power= " << p << endl;
        motor.start(p);
        sleep(1);
    }
    motor.stop();

    cout << "-- reading sensor on port 1..." << endl;
    for (int i = 0; i < 100; ++i)
    {
        cout << "value= " << sensor.readRaw() << endl;
        sleep(1);
    }

    return EXIT_SUCCESS;
}
