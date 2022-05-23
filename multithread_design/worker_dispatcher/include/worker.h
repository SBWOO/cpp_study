#pragma once

#include "request.h"

#include <condition_variable>
#include <mutex>
#include <iostream>

using namespace std;

class Worker {
public:
  Worker() { running = true; ready = false; ulock = unique_lock<mutex>(mtx); }
  // 생성자 선언하는 것을 실수함;
  // running, ready가 unknown으로 세팅되어 루프가 돌지 않는 현상 발생, 디버그에 1시간 소요함
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
