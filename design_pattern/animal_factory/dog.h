#pragma once

#include "animal.h"

class Dog : public AnimalBase
{
public:
  explicit Dog (std::string dog_params)
  {
    std::cout << "Bark!" << std::endl;
    std::cout << "Dog Params : " << dog_params.c_str() << std::endl;
  }
  void feed (std::string food) override
  {
    std::cout << "Eating dog food! : " << food.c_str() << std::endl;
  }
};
