#pragma once

#include <iostream>
#include "animal_factory.h"
using namespace std;

int main(int argc, char * argv[])
{
  std::unique_ptr<AnimalBase> unknown_animal;
  unknown_animal = AnimalFactory::createAnimal(ANIMAL_TYPE::DOG);
  unknown_animal->feed("water");

  return 0;
}
