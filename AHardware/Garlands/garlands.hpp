#pragma once
#include "pin.hpp"
#include "port.hpp"
#include <array>
#include "pinconfig.hpp"
#include "tim2registers.hpp"
#include "nvicregisters.hpp"
#include "timer.hpp"
#include <iostream>


extern Timer timer;
class Garlands
{
  
  public:
    Garlands(Button& aButton): button(aButton), leds
                                                {
                                                  Led(Led1Pin),
                                                  Led(Led2Pin),
                                                  Led(Led3Pin),
                                                  Led(Led4Pin)
                                                }
    {
    }
    void Update()
    {
      if (flag==0)
      {
      deltaPeriod = Period+100;
      if (deltaPeriod==1100)
      {
        flag=1;
      }
      }
      
      if (flag==1)
      {
      deltaPeriod = Period-100;
      if (deltaPeriod==100)
      {
        flag=0;
      }
      }
      
      Period = deltaPeriod;
      std::cout << "Период: " << Period << " мс." <<std::endl;
      timer.ChangePeriod(Period);
    }
    void HandleInterrupt()
    {
      leds[i++].Toggle();
      if (i==4)
      {
        i=0;
      }
    }
    void Start ()
    {
      timer.Start(Period);
    }
    
  private:
     std::array<Led, 4> leds;
     int i = 0;
     Button& button;
     uint32_t Period =100U;
     bool flag=0;
     uint32_t deltaPeriod;

};
     
    
      