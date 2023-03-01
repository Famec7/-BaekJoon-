#include <algorithm>
#include <iostream>
#include <utility>

int ccw(std::pair<long long, long long> &a, std::pair<long long, long long> &b,
        std::pair<long long, long long> &c);
void find_intersection(std::pair<long long, long long> &a,
                       std::pair<long long, long long> &b,
                       std::pair<long long, long long> &c,
                       std::pair<long long, long long> &d);

int main() {
  std::pair<long long, long long> xy[4];
  for (int i = 0; i < 4; i++)
    std::cin >> xy[i].first >> xy[i].second;

  int ans1 = ccw(xy[0], xy[1], xy[2]) * ccw(xy[0], xy[1], xy[3]);
  int ans2 = ccw(xy[2], xy[3], xy[0]) * ccw(xy[2], xy[3], xy[1]);

  if (ans1 == 0 && ans2 == 0) {
    if (xy[0] > xy[1])
      std::swap(xy[0], xy[1]);
    if (xy[2] > xy[3])
      std::swap(xy[2], xy[3]);
    if (xy[0] <= xy[3] && xy[1] >= xy[2]) {
      std::cout << "1\n";
      find_intersection(xy[0], xy[1], xy[2], xy[3]);
    } else
      std::cout << "0\n";
  } else if (ans1 <= 0 && ans2 <= 0) {
    std::cout << "1\n";
    find_intersection(xy[0], xy[1], xy[2], xy[3]);
  } else
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

void find_intersection(std::pair<long long, long long> &a,
                       std::pair<long long, long long> &b,
                       std::pair<long long, long long> &c,
                       std::pair<long long, long long> &d) {
  double p = (a.first - b.first) * (c.second - d.second) -
             (a.second - b.second) * (c.first - d.first);
  double px = (a.first * b.second - a.second * b.first) * (c.first - d.first) -
              (a.first - b.first) * (c.first * d.second - c.second * d.first);
  double py =
      (a.first * b.second - a.second * b.first) * (c.second - d.second) -
      (a.second - b.second) * (c.first * d.second - c.second * d.first);

  if (p == 0) {
    if (a == d && c <= a)
      std::cout << a.first << ' ' << a.second << '\n';
    else if (b == c && a <= c)
      std::cout << b.first << ' ' << b.second << '\n';
  } else {
    double x = px / p;
    double y = py / p;
    std::cout << std::fixed;
    std::cout.precision(9);
    std::cout << x << ' ' << y << '\n';
  }
}