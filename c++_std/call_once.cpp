#include <iostream>
#include <thread>
#include <mutex>

using namespace std::chrono_literals;

std::once_flag Flag;
std::mutex mtx;

void print()
{
  std::cout << "This should be called once." << std::endl;
}

void fn()
{
  std::call_once(Flag, print);
  mtx.lock();
  std::cout << "thread id:" << std::this_thread::get_id() << std::endl;
  mtx.unlock();
}

int main()
{
  std::thread t1(fn);
  std::thread t2(fn);
  std::thread t3(fn);
  std::thread t4(fn);
  std::thread t5(fn);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();

  return 0;

}
