#include <future>
#include <thread>
#include <iostream>
#include <mutex>

using namespace std::chrono_literals;

std::mutex mtx;

void func(std::promise<int> prms)
{
  std::this_thread::sleep_for(2s);
  prms.set_value(4);

  return;
}

int main (int argc, char * argv[])
{
  std::promise<int> prms;
  std::future<int> fut = prms.get_future();
  std::thread t(func, std::move(prms));
  while(fut.wait_for(0.2s) != std::future_status::ready)
  {
    std::lock_guard<std::mutex> lg1(mtx);
    std::cout << "main thread is running!" << std::endl;
  }

  int a = fut.get();
  std::cout << "finished thread 1 with value : " << a << std::endl;
  t.join();
  return 0;
}
