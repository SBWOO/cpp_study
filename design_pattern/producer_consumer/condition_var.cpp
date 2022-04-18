#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

bool readyFlag = false;
std::mutex mtx;
std::condition_variable cv;

void waitFn()
{
  mtx.lock();
  std::cout << "wait" << std::endl;
  mtx.unlock();
  std::unique_lock<std::mutex> lck(mtx);
  while(!readyFlag)
  {
    cv.wait(lck);
  }
  // while을 사용하지 않고 깔끔하게 끝내는 방법
  // cv.wait(lck, []{return readyFlag});

  // unique_lock이 아직 안풀렸으니 여전히 Critical Section임.

  std::cout << "re run" << std::endl;
}

void signalFn()
{
  mtx.lock();
  std::cout << "signal" << std::endl;
  mtx.unlock();
  {
    std::lock_guard<std::mutex> lck(mtx);
    readyFlag = true;
  }

  cv.notify_one();
}

int main()
{
  std::thread waitT(waitFn);
  std::thread signal(signalFn);

  waitT.join();
  signal.join();

  return 0;
}
