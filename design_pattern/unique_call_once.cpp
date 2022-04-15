#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <memory>

class Cat
{
public:
  Cat()
  {
    std::cout << "init cat" << std::endl;
  }
  void speak()
  {
    std::cout << "meow " << std::endl;
  }
};

std::mutex mtx;
std::once_flag flag;

std::unique_ptr<Cat> cp = nullptr;

void fn()
{
  std::call_once(flag, [](){
    cp = std::make_unique<Cat>();
  });
  mtx.lock();
  std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
  cp->speak();
  mtx.unlock();
}

int main(int argc , char * argv[])
{
  std::vector<std::thread> threads;
  for(int i = 0; i < 10 ; i++) {
    threads.emplace_back(fn);
  }

  for(int i = 0; i < 10 ; i++) {
    threads[i].join();
  }

  return 0;
}
