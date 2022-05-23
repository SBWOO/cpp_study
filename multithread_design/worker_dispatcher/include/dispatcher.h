#pragma once
#include "request.h"
#include "worker.h"

#include <queue>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

// everything is static member
class Dispatcher {
public:
  static bool init(int num_workers);
  static void addRequest(AbstractRequest* request);
  static bool stop();
  static bool addWorker(Worker * worker);

private:
  static queue<AbstractRequest*> requests;
  static queue<Worker*> workers;
  static mutex requestsMutex;
  static mutex workersMutex;
  static vector<Worker*> allWorkers;
  static vector<thread*> threads;
};
