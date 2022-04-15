#include <iostream>
#include <thread>
#include <mutex>

using namespace std::chrono_literals;

std::once_flag flag;
std::mutex mtx;
void print()
{
  std::cout << "This function only prints Message once" << std::endl;
}

void fn()
{
  std::call_once(flag, print);
  mtx.lock();
  std::cout << "Thread id :" << std::this_thread::get_id() << std::endl;
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
