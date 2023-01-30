#include <algorithm>
#include <iostream>
#include <vector>

int K, N;
std::vector<int> LAN;
int binary_search(long long start, long long end);

int main() {
  std::cin >> K >> N;
  LAN.resize(K);

  for (auto &lan : LAN)
    std::cin >> lan;
  std::sort(LAN.begin(), LAN.end());
  std::cout << binary_search(1, LAN[K - 1]) << '\n';

  return 0;
}

int binary_search(long long start, long long end) {
  if (start > end)
    return end;
  long long mid = (start + end) / 2;

  int len = 0;
  for (int i = 0; i < K; i++)
    len += LAN[i] / mid;

  if (len >= N)
    return binary_search(mid + 1, end);
  else
    return binary_search(start, mid - 1);
}