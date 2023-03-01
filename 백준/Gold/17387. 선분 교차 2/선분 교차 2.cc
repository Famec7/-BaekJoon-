#include <algorithm>
#include <iostream>
#include <utility>

int ccw(std::pair<long long, long long> &a, std::pair<long long, long long> &b,
        std::pair<long long, long long> &c);

int main() {
  std::pair<long long, long long> xy[4];
  for (int i = 0; i < 4; i++)
    std::cin >> xy[i].first >> xy[i].second;

  int ans1 = ccw(xy[0], xy[1], xy[2]) * ccw(xy[0], xy[1], xy[3]);
  int ans2 = ccw(xy[2], xy[3], xy[0]) * ccw(xy[2], xy[3], xy[1]);

  int result = 0;
  if (ans1 == 0 && ans2 == 0) {
    if (xy[0] > xy[1])
      std::swap(xy[0], xy[1]);
    if (xy[2] > xy[3])
      std::swap(xy[2], xy[3]);
    if (xy[0] <= xy[3] && xy[1] >= xy[2])
      result = 1;
  } else if (ans1 <= 0 && ans2 <= 0)
    result = 1;
  
  std::cout << result << '\n';

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