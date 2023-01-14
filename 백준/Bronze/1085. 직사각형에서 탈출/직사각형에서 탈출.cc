#include <iostream>

int main() {
  int x, y, w, h;

  std::cin >> x >> y >> w >> h;
  int result_x = std::min(w - x, x);
  int result_y = std::min(h - y, y);
  std::cout << std::min(result_x, result_y) << '\n';

  return 0; 
}