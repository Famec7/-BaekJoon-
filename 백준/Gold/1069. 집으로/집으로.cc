#include <cmath>
#include <iostream>

int main() {
  int X, Y, D, T;

  std::cin >> X >> Y >> D >> T;

  double distance = sqrt(X * X + Y * Y);

  double result = distance;

  int jump = distance / D;
  distance -= jump * D;

  if (jump == 0)
    result = std::min(result, std::min(T + D - distance, 2.0 * T));
  else
    result = std::min(result, std::min(jump * T + distance, (jump + 1.0) * T));
  
  std::cout << std::fixed;
  std::cout.precision(9);
  std::cout << result << '\n';

  return 0;
}