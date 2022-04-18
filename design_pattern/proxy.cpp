#include <iostream>

class Subject{
public:
  virtual void request() = 0;
};

// 여기서부터 주석하고 연습
class RealSubject : public Subject {
public:
  void request() {std::cout << "RealSubject Request" << std::endl;}
};

class Porxy : public Subject {
public:
  Proxy() : _realsubject(nullptr) {}
  ~Proxy() {if(_realsubject) delete _realsubject; }

  void request() {
    if(!_realsubject)
     _realsubject = new RealSubject;

     _realsubject->request();
  }
private:
  RealSubject* _realsubject;
};
// 여기까지 주석

int main() {
  Subject* Proxyptr = new Proxy();
  Proxyptr->request();

  delete Proxyptr;
  return 0;
}
