#pragma once

#include "builder.h"

class DesktopBuilder : public ComputerBuilder {
public:
 DesktopBuilder () {
   computer = std::make_unique<Computer>();
 }
 virtual void setCPU(){
   computer->setCPU("i7");
   computer->setRAM(16);
 }
 virtual void setRAM() {
   computer->setRAM(16);
 }
 virtual void setSSD() {
   computer->setSSD(256);
 }
 virtual std::unique_ptr<Computer> getComputer() {
   return std::move(computer);
 }
private:
  std::unique_ptr<Computer> computer;
};
