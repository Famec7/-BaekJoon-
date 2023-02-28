#include <cmath>
#include <iostream>
#include <utility>

int main() {
  int x1, y1;
  int x2, y2;
  int x3, y3;

  std::cin >> x1 >> y1;
  std::cin >> x2 >> y2;
  std::cin >> x3 >> y3;

  std::pair<int, int> a = {x2 - x1, y2 - y1};
  std::pair<int, int> b = {x3 - x2, y3 - y2};
  int clockwise = a.first * b.second - a.second * b.first;

  if (clockwise < 0)
    clockwise = -1;
  else if (clockwise > 0)
    clockwise = 1;
  else
    clockwise = 0;
  std::cout << clockwise << '\n';

  return 0;
}