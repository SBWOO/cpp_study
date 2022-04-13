#include <iostream>
#include <thread>
#include <vector>

void fn()
{
  int a = 0;
  std::cout << "fn" << std::endl;
}
void fn1()
{
  int a = 0;
  std::cout << std::this_thread::get_id() << std::endl;
}
int main()
{
  std::cout << "process start" << std::endl;

  std::thread t1(fn);
  std::thread t2(fn);
  std::thread t3([]{
    int a = 0;
    std::cout << "thread lambda" << std::endl;
  });

  t1.join();
  t2.join();
  t3.join();

  std::cout << "join 3 threads" << std::endl;
  std::cout << "open 10 threads" << std::endl;

  std::vector<std::thread> threads;

  for(int i=0; i < 10 ; i++) {
    threads.emplace_back(std::thread(fn1));
  }

  for(auto & thread : threads)
  {
    thread.join();
  }
  std::cout << "process end" << std::endl;

}
