#pragma once

#include "rccregisters.hpp"
#include "gpiocregisters.hpp"
#include "gpioaregisters.hpp"
#include <iostream>
#include <bitset>
#include "port.hpp"
#include "pin.hpp"
#include "led.hpp"
#include "button.hpp"


inline Port<GPIOC> PortC;
inline Port<GPIOA> PortA;

inline Pin Led1Pin(5U, PortC);
inline Pin Led2Pin(8U, PortC);
inline Pin Led3Pin(9U, PortC);
inline Pin Led4Pin(5U, PortA);