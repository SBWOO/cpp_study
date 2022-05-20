#pragma once

#include "request.h"

#include <condition_variable>
#include <mutex>

using namespace std;

class Worker {
public:
  void run();
  void getCondition(condition_variable* &cv);
  void stop() {running = false; }
  void setRequest(AbstractRequest * request) { this-> request = request; ready = true; }
private:
  condition_variable cv;
  mutex mtx;
  unique_lock<mutex> ulock;
  AbstractRequest* request;
  bool running;
  bool ready;
};
