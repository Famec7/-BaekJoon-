#include <algorithm>
#include <iostream>
#include <vector>

int N, k;

int find(int start, int end);

int main() {
  std::cin >> N >> k;

  std::cout << find(1, k) << '\n';

  return 0;
}

int find(int start, int end) {
  if (start > end)
    return start;

  int mid = (start + end) / 2;

  int count = 0;
  for (int i = 0; i < N; i++)
    count += std::min(N, mid / (i + 1));

  if (count < k)
    return find(mid + 1, end);
  else
    return find(start, mid - 1);
}