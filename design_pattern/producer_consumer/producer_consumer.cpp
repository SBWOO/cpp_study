#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <queue>

class StrQueue
{
public:
  void addStr(std::string s)
  {
    {
      std::lock_guard<std::mutex> lck(mtx_);
      strs_queue_.push(std::move(s));
    }
    cv_.notify_all();
  }

  std::string getStr()
  {
    std::unique_lock<std::mutex> lck(mtx_);
    while(strs_queue_.empty()) {
      cv_.wait(lck);
    }
    std::string s = std::move(strs_queue_.front());
    strs_queue_.pop();
    lck.unlock();

    return s;
  }
private:
  std::mutex mtx_;
  std::condition_variable cv_;
  std::queue<std::string> strs_queue_;
};
class StrStack
{
public:

  // producer
  void addStr(std::string s)
  {
    {
      std::lock_guard<std::mutex> lck(mMtx);
      mStrs.emplace_back(std::move(s));
    }
    mCv.notify_one();
  }

  // consumer
  std::string getStr()
  {
    std::unique_lock<std::mutex> lck(mMtx);
    while(mStrs.empty())
    {
      mCv.wait(lck);
    }
    std::string s = std::move(mStrs.back());
    mStrs.pop_back();
    lck.unlock();
    return s;
  }

private:
 std::vector<std::string> mStrs;
 std::mutex mMtx;
 std::condition_variable mCv;
};


int main()
{
  StrQueue strStack;

  //producer
  std::thread t1([&](){
    strStack.addStr("nocope");
  });

  std::thread t2([&](){
    strStack.addStr("meow");
  });

  std::thread t3([&](){
    strStack.addStr("dog");
  });

  std::thread t4([&](){
    strStack.addStr("amumal");
  });

  std::thread t5([&](){
    strStack.addStr("zzz");
  });

  // consumer
  std::thread t6([&](){
    std::cout << strStack.getStr() << std::endl;
  });
  std::thread t7([&](){
    std::cout << strStack.getStr() << std::endl;
  });

  std::thread t8([&](){
    while(1){
       std::cout << strStack.getStr() << std::endl;
    }

  });


  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  t7.join();
  t8.join();

  return 0;

}
