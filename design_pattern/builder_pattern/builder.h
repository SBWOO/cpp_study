#pragma once

#include "product.h"
#include <memory>

class ComputerBuilder {
public:
  virtual void setCPU() = 0;
  virtual void setRAM() = 0;
  virtual void setSSD() = 0;
  virtual std::unique_ptr<Computer> getComputer() = 0;
};
