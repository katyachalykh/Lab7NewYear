#include "rccregisters.hpp"
#include "gpiocregisters.hpp"
#include "gpioaregisters.hpp"
#include <iostream>
#include <bitset>
#include "button.hpp"
#include "pinconfig.hpp"
#include "garlands.hpp"
#include "tim2registers.hpp"
#include "nvicregisters.hpp"
#include "tree.hpp"


unsigned int ButPeriod = 100U;
unsigned int LedsPeriod = 500U;
unsigned int counter = 0;

extern "C"
{
  int __low_level_init(void)
  {
    RCC::CR::HSEON::On::Set();
    while(!RCC::CR::HSERDY::Ready::IsSet())
    {
    }
    
    RCC::CFGR::SW::Hse::Set();
    while(!RCC::CFGR::SWS::Hse::IsSet())
    {
    }
    
    RCC::CR::HSION::Off::Set();
    
    RCC::AHB1ENR::GPIOCEN::Enable::Set();
    RCC::AHB1ENR::GPIOAEN::Enable::Set();
    GPIOC::MODER::MODER5::Output::Set();
    GPIOC::MODER::MODER13::Input::Set();
    GPIOA::MODER::MODER5::Output::Set();
    GPIOC::MODER::MODER9::Output::Set();
    GPIOC::MODER::MODER8::Output::Set();
    return 1;
  }
}
Pin buttonPin(13U, PortC);

Button button(buttonPin);

Garlands garlands(button);

Timer timer;

Tree tree;

int main()
{
  tree.Update();
  for(;;)
  {
    if (button.IsPressed())
    {
      garlands.Update();
    }
  }
  return 0;
}
