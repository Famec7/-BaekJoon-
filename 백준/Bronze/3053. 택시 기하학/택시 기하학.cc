#include <cmath>
#include <iostream>

const double PI = std::acos(-1);

int main() {
  double R;

  std::cin >> R;
  std::cout << std::fixed;
  std::cout.precision(6);
  std::cout << R * R * PI << '\n';
  std::cout << R * R * 2.0 << '\n';

  return 0;
}