// Singleton design pattern example

#include <iostream>

class SingletonClass
{
  ~SingletonClass() = default;
public:
  static SingletonClass& getInstance(int input)
  {
    static SingletonClass s;
    s.class_id_ = input;
    return s;
  }
  void print()
  {
    std::cout << "singleton class is still alive! Class id: " << class_id_ << std::endl;
    return;
  }
private:
  SingletonClass() {};
  SingletonClass& operator=(const SingletonClass& in) = delete;
  SingletonClass& operator=(SingletonClass&& in) = delete;
  int class_id_;
};

int main(int argc, char * argv[])
{
  SingletonClass& s = SingletonClass::getInstance(1);
  s.print();

  SingletonClass& s1 = SingletonClass::getInstance(2);
  s1.print();
  s.print();
  return 0;
}
