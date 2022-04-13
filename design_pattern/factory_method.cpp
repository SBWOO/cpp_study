#include <iostream>
#include <cmath>

class Point
{
protected:
  Point(const double x, const double y) : x{x}, y{y}
  {

  }
public:
  double x, y;
  static Point NewCarteian(double x, double y)
  {
    return {x, y};
  }
  static Point NewPolar(double r, double theta)
  {
    return {r*cos(theta) , r*sin(theta)};
  }
};

int main()
{
  auto p = Point::NewPolar(1.0, 2.0);
  std::cout << "X: " << p.x << " Y: " << p.y << std::endl;
  return 0;
}
