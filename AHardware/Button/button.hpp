#pragma once
#include "pin.hpp"
#include "port.hpp"

class Button
{
  public:
    Button(IPinGet& aPin): pin(aPin)
    {
    }
    
    bool IsPressed()
    {
      return !pin.IsSet();
        
    }
  private:
    IPinGet& pin;
};