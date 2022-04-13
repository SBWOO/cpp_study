cmake_minimum_required(VERSION 3.8)

project(factory VERSION 1.0.0)

add_executable(${PROJECT_NAME} main.cpp
  animal.h
  cat.h
  dog.h
  animal_factory.h)
