#pragma once
#include <string>

using namespace std;

typedef void (*logFunction)(string text);

class AbstractRequest {
public:
  virtual void setValue(int value) = 0;
  virtual void process() = 0;
  virtual void finish() = 0;
};

class Request : public AbstractRequest {
public:
  void setValue(int value) {this->value = value; }
  void setOutput(logFunction fnc) { outFnc = fnc; }
  void process();
  void finish();

private:
  int value;
  logFunction outFnc;
};
