#pragma once
#include "garlands.hpp"

extern Garlands garlands;
class Tree
{
  public:
    void Update ()
    {
      garlands.Start();
    }
};