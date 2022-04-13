#include <iostream>
#include <Eigen/Dense>

int main(int argc, char * argv[])
{
  Eigen::Matrix<double, 4, 4> mat;
  mat << 1, 2, 3, 4,
         5, 6, 7, 8,
         9, 10, 11, 12,
         13, 14, 15, 16;

  std::cout << "The original Matrix" << std::endl;
  std::cout << mat << std::endl << std::endl;

  for(int i = 0; i < 2; i++) {
    std::cout << "Block of size (" << 2 << ", " << 2 <<
      "), starting at (" << i << ", "  << i + 1 << ")" << std::endl;
    std::cout << mat.block<2, 2>( i, i + 1) << std::endl << std::endl;
  }
}
