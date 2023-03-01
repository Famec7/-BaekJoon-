#include <iostream>
#include <utility>

int ccw(std::pair<long long, long long> &a, std::pair<long long, long long> &b,
        std::pair<long long, long long> &c);

int main() {
  std::pair<long long, long long> xy[4];
  for (int i = 0; i < 4; i++)
    std::cin >> xy[i].first >> xy[i].second;

  if (ccw(xy[0], xy[1], xy[2]) * ccw(xy[0], xy[1], xy[3]) < 0 &&
      ccw(xy[2], xy[3], xy[0]) * ccw(xy[2], xy[3], xy[1]) < 0)
    std::cout << "1\n";
  else
    std::cout << "0\n";

  return 0;
}

int ccw(std::pair<long long, long long> &a, std::pair<long long, long long> &b,
        std::pair<long long, long long> &c) {
  long long result = (b.first - a.first) * (c.second - a.second) -
                     (c.first - a.first) * (b.second - a.second);
  if (result < 0)
    return -1;
  else if (result > 0)
    return 1;
  else
    return 0;
}