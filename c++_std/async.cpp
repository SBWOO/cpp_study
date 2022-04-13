#include <iostream>
#include <future>
#include <thread>

using namespace std::chrono_literals;

void fn(std::promise<int> input)
{
  std::this_thread::sleep_for(2s);
  input.set_value(42);
  std::cout << "future thread shutdown value with : " << 42 << std::endl;
}

int fn1(int input)
{
  std::this_thread::sleep_for(1s);
  std::cout << "async thread shutdown value with : " << input << std::endl;
  return input;
}

int main()
{
  std::promise<int> prms;
  std::future<int> fut = prms.get_future();

  int input = 44;
  std::future<int> fut1 = std::async(std::launch::async, fn1 , input);

  std::thread t(fn, std::move(prms));

  while(fut.wait_for(0.2s) != std::future_status::ready || fut1.wait_for(0.2s) != std::future_status::ready ) {
    std::cout << "main thread running" << std::endl;
  }

  t.join();
  std::cout << "Program finished with; \nFuture rtn val: " << fut.get() << "\nAsync rtn val: " << fut1.get() << std::endl;

  return 0;
}
