#pragma once
#include "desktop_builder.h"
#include "computer_director.h"


int main(int argc, const char *argv[]) {
  auto computerDirector = std::make_unique<ComputerDirector>();
  auto i5builder = std::make_unique<DesktopBuilder>();

  computerDirector->setComputerBuilder(std::move(i5builder));
  std::unique_ptr<Computer> myComputer = std::move(computerDirector->makeComputer());
  myComputer->showSpec();

  return 0;
}
