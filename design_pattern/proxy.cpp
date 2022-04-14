#include <iostream>

class Subject{
public:
  virtual void request() = 0;
};

class RealSubject : public Subject{
public:
  void request() {std::cout << "RealSubject Request" << std::endl;}
};

class Proxy : public Subject{
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

int main() {
  Subject* Proxyptr = new Proxy();
  Proxyptr->request();

  delete Proxyptr;
  return 0;
}
