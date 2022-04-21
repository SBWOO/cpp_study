#include <iostream>

class Subject{
public:
  virtual void request() = 0;
};

// 여기서부터 주석하고 연습
class RealSubject : public Subject {
public:
  void request()
  {
    std::cout << "Real Subject Request!" << std::endl;
    return;
  }
};

class Proxy : public Subject {
public:
  void request()
  {
    if(s_ == nullptr) {
      s_ = new RealSubject;
    }
    s_->request();
    return;
  }
private:
  RealSubject * s_;

};
// 여기까지 주석

int main() {
  Subject* Proxyptr = new Proxy();
  Proxyptr->request();

  delete Proxyptr;
  return 0;
}
