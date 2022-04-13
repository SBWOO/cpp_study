#pragma once

#include "builder.h"
#include <memory>

class ComputerDirector {
public:
  void setComputerBuilder(std::unique_ptr<ComputerBuilder> computerBuilder)
  {
    this->computerBuilder = std::move(computerBuilder);
  }
  std::unique_ptr<Computer> makeComputer()
  {
    computerBuilder->setCPU();
    computerBuilder->setRAM();
    computerBuilder->setSSD();

    return computerBuilder->getComputer();
  }
private:
  std::unique_ptr<ComputerBuilder> computerBuilder;
};
