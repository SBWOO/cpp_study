#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;
void fn(std::atomic<int>& counter) {
  mtx.lock();
  std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
  mtx.unlock();
  for (int i = 0; i < 10000; i++) {
    counter++;
  }
}

int main() {
  std::atomic<int> counter(0);

  std::vector<std::thread> threads;
  for (int i = 0; i < 4; i ++) {
    threads.push_back(std::thread(fn, ref(counter)));
  }

  for (int i = 0; i <4; i++) {
    threads[i].join();
  }

  std::cout << "Counter 최종 값 :" << counter << std::endl;
}
