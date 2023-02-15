#include <algorithm>
#include <iostream>
#include <vector>

int N, C;
std::vector<int> x;

int set(int start, int end);

int main() {
  std::cin >> N >> C;
  x.resize(N);

  for (auto &ref : x)
    std::cin >> ref;

  std::sort(x.begin(), x.end());
  std::cout << set(0, x[N - 1]) << '\n';

  return 0;
}

int set(int start, int end) {
  if (start > end)
    return end;

  int mid = (start + end) / 2;
  int count = 1;
  int pos = x[0];
  for (int i = 1; i < N; i++) {
    if (x[i] - pos >= mid) {
      pos = x[i];
      count++;
    }
  }

  if (count >= C)
    return set(mid + 1, end);
  else
    return set(start, mid - 1);
}