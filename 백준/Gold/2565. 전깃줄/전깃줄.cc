#include <algorithm>
#include <iostream>

int N, cache[101];
std::pair<int, int> wire[101];

int LIS(int start);

int main() {
  std::cin >> N;

  for (int i = 0; i < N; i++)
    std::cin >> wire[i].first >> wire[i].second;

  std::sort(wire, wire + N);
  std::fill(cache, cache + 101, -1);
  int lis = LIS(-1) - 1;
  std::cout << N - lis << '\n';

  return 0;
}

int LIS(int start) {
  int &ret = cache[start + 1];
  if (ret != -1)
    return ret;

  ret = 1;
  for (int next = start; next < N; next++) {
    if (wire[start].second < wire[next].second)
      ret = std::max(ret, LIS(next) + 1);
  }
  return ret;
}