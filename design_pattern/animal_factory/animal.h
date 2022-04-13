#pragma once

#include <iostream>
#include <string>

class AnimalBase {
public:
  AnimalBase(){
    std::cout << "animal base created! " << std::endl;
  }
  virtual void feed(std::string food) = 0;
};
