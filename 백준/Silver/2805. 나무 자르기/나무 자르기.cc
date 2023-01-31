#include <algorithm>
#include <iostream>
#include <vector>

int N, M;
std::vector<long long> H;

long long cut(long long start, long long end);

int main() {
  std::cin >> N >> M;
  H.resize(N);

  for (auto &h : H)
    std::cin >> h;
  std::sort(H.begin(), H.end());
  std::cout << cut(0, H[N - 1]) << '\n';

  return 0;
}

long long cut(long long start, long long end) {
  if (start > end)
    return end;

  long long mid = (start + end) / 2;

  long long len = 0;
  for (int i = 0; i < N; i++) {
    if (H[i] > mid)
      len += H[i] - mid;
  }
  if (len >= M)
    return cut(mid + 1, end);
  else
    return cut(start, mid - 1);
}