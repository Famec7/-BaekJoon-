#include <cmath>
#include <iostream>

int main() {
  int T;
  int x1, y1, r1, x2, y2, r2;
  double r;

  std::cin >> T;
  while (T--) {
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (r == 0) {
      if (r1 == r2)
        std::cout << -1 << '\n';
      else
        std::cout << 0 << '\n';
      continue;
    }
    if (r == r1 + r2 || r == abs(r1 - r2))
      std::cout << 1 << '\n';
    else if (r < r1 + r2 && r > abs(r1 - r2))
      std::cout << 2 << '\n';
    else
      std::cout << 0 << '\n';
  }

  return 0;
}