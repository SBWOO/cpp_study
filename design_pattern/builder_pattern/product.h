#pragma once
#include <iostream>
#include <string>

class Computer {
public:
  Computer() {
    // set default
    this->cpu = "i5";
    this->ram = 8;
    this->ssd = 128;
  }
  void setCPU(std::string cpu) {
    this->cpu = cpu;
  }
  void setRAM(int ramgb) {
    this->ram = ramgb;
  }
  void setSSD(int ssdgb) {
    this->ssd = ssdgb;
  }
  void showSpec() {
    std::cout << "cpu: " << cpu << " ram: " << ram << " ssd: " << ssd << std::endl;
  }
private:
  std::string cpu;
  int ram;
  int ssd;
};
