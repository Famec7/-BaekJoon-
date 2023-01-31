#include <algorithm>
#include <iostream>
#include <vector>

int N, C;
std::vector<int> X;

int set(int start, int end);

int main() {
  std::cin >> N >> C;
  X.resize(N);

  for (auto &x : X)
    std::cin >> x;
  std::sort(X.begin(), X.end());

  std::cout << set(0, X[N - 1] - 1) << '\n';

  return 0;
}

int set(int start, int end) {
  if (start > end)
    return end;

  int mid = (start + end) / 2;

  int count = 1;
  int pos = X[0];
  for (int i = 1; i < N; i++) {
    if (X[i] - pos >= mid) {
      pos = X[i];
      count++;
    }
  }
  if (count >= C)
    return set(mid + 1, end);
  else
    return set(start, mid - 1);
}