#include "dispatcher.h"

#include <iostream>
using namespace std;

// static member initialization.
queue<AbstractRequest*> Dispatcher::requests;
queue<Worker*> Dispatcher::workers;
mutex Dispatcher::requestsMutex;
mutex Dispatcher::workersMutex;
vector<Worker*> Dispatcher::allWorkers;
vector<thread*> Dispatcher::threads;

bool Dispatcher::init(int num_workers) {
  // null 초기화
  thread* t = 0;
  Worker* w = 0;
  for (int i = 0; i < num_workers; ++i) {
    w = new Worker;
    allWorkers.push_back(w);
    t = new thread(&Worker::run, w);
    threads.push_back(t);
  }

  return true;
}

bool Dispatcher::stop() {
  for(int i = 0; i < allWorkers.size(); ++i) {
    allWorkers[i]->stop();
  }
  cout << "Stopped workers.\n";
  for(int j = 0; j < threads.size(); ++j) {
    threads[j]->join();
    cout << "Joined threads. \n";
  }
}

void Dispatcher::addRequest(AbstractRequest* request) {
  std::cout << "locking workersMutex" << std::endl;
  workersMutex.lock();
  std::cout << "workersMutex lock finished" << std::endl;
  if(!workers.empty()) {
    // get workers on the available queue
    Worker* worker = workers.front();
    worker->setRequest(request);
    condition_variable* cv;
    worker->getCondition(cv);
    cv->notify_one();
    workers.pop();
    workersMutex.unlock();

  }
  workersMutex.unlock();
  requestsMutex.lock();
  // add request to queue
  requests.push(request);
  requestsMutex.unlock();
}

bool Dispatcher::addWorker(Worker* worker) {
  bool wait = true;
  requestsMutex.lock();
  if(!requests.empty()) {
    AbstractRequest* request = requests.front();
    worker->setRequest(request);
    requests.pop();
    wait = false;
    requestsMutex.unlock();
  } else {
    requestsMutex.unlock();
    workersMutex.lock();
    workers.push(worker);
    workersMutex.unlock(); //실수 목록 : unlock을 실수로 lock으로 적음;
                           // 결과적으로 deadlock 현상을 해결하기위해 2시간 소모
  }
  return wait;
}
