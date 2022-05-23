#include "dispatcher.h"
#include "request.h"

#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

// global
sig_atomic_t signal_caught = 0; // signal flag
mutex logMutex;  // synchornisation for log output(iostream)

void sigint_handler(int sig) {
  signal_caught = 1;
}

void logFnc(string text) {
  logMutex.lock();
  cout << text << endl;
  logMutex.unlock();
}

int main() {
  signal(SIGINT, &sigint_handler);
  Dispatcher::init(10);
  cout << "Dispatcher initialised." << endl;

  int cycles = 0;
  Request *rq = 0;

  while (!signal_caught && cycles < 50) {
    // creating request

    cout << "main : request cycle no." << cycles << " is running" << endl;
    rq = new Request();
    rq->setValue(cycles);
    rq->setOutput(&logFnc);

    // adding request to running thread
    Dispatcher::addRequest(rq);
    cycles++;
  }

  this_thread::sleep_for(chrono::seconds(5));

  Dispatcher::stop();

  return 0;
}
