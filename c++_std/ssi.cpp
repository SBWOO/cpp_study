// scoped static init
// fn에서 static멤버로 선언되어있으면 오직 한번만 초기화됨 : thread safe
// mutex, call once로 보호할 필요가 없음.

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class Cat
{
public:

  Cat()
  {
    std::cout << "meow" << std::endl;
  }
  void addCat()
  {
    cat_num++;
    mtx.lock();
    std::cout << "number of cat: "<< cat_num << std::endl;
    mtx.unlock();
  }

std::mutex mtx;

private:
  int cat_num = 0;
};

void fn()
{
  static Cat cat;
  cat.addCat();
  cat.mtx.lock();
  std::cout << "thread executed with id: " << std::this_thread::get_id() << std::endl;
  cat.mtx.unlock();
  // lazy init
}

int main()
{
  std::cout << "process starts!" << std::endl;
  std::vector<std::thread> threads;
  for(int i = 0; i < 10 ; i++) {
    threads.emplace_back(fn);
  }

  for(int i = 0; i < 10; i++) {
    threads[i].join();
  }
}
