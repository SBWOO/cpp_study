#pragma once

#include "animal.h"

class Cat : public AnimalBase
{
public:
  explicit Cat(std::string cat_params)
  {
    std::cout << "Mew!" << std::endl;
    std::cout << "Cat Params : " << cat_params.c_str() << std::endl;
  }
  void feed(std::string food) override
  {
    std::cout << "Eating Cat food! : " << food.c_str() << std::endl;
  }
};
