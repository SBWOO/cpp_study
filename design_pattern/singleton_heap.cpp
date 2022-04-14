// Singleton design pattern example

#include <iostream>

class SingletonClass
{
  ~SingletonClass() = default;
public:
  static SingletonClass* getInstance(int input){
    // NULL일 경우 전역변수 해제
    if (s == NULL) {
      s = new SingletonClass;
    }
    s -> class_id_ = input;
    return s;
  }
  void print()
  {
    std::cout << "singleton class is still alive! Class id: " << class_id_ << std::endl;
    return;
  }
private:
  SingletonClass() {}
  SingletonClass(const SingletonClass& ref) = delete;
  SingletonClass& operator=(SingletonClass& in) = delete;
  static SingletonClass * s;
  int class_id_;
};
// NULL 포인터로 선언된 전역변수가 존재
SingletonClass* SingletonClass::s = NULL;

int main(int argc, char * argv[])
{
  SingletonClass* s = SingletonClass::getInstance(1);
  s->print();

  SingletonClass* s1 = SingletonClass::getInstance(2);
  s1->print();
  s->print();
  return 0;
}
