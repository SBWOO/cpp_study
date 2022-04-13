#pragma once

#include <iostream>
#include "cat.h"
#include "dog.h"
#include <memory>
#include <iostream>

enum ANIMAL_TYPE {
  DOG,
  CAT,
};
class AnimalFactory {
public:
  AnimalFactory() = delete;
  ~AnimalFactory() = default;
  static std::unique_ptr<AnimalBase> createAnimal(ANIMAL_TYPE type)
  {
    switch(type){
      case ANIMAL_TYPE::DOG :
        return std::make_unique<Dog>("Dolmatian");
      case ANIMAL_TYPE::CAT :
        return std::make_unique<Cat>("Persian");
      default :
      std::cout << "Input is not name of ANIMAL_TYPE! " << std::endl;
    }
  }
};

