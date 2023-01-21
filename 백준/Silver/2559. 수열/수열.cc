#include <iostream>

int main() {
  int N, K;
  int temp[100000];
  int sum = 0, max = -10000001;

  std::cin >> N >> K;

  for (int i = 0; i < N; i++)
    std::cin >> temp[i];

  int start = 0;
  for (int i = 0; i < N; i++) {
    sum += temp[i];
    if (i + 1 >= K) {
      max = std::max(max, sum);
      sum -= temp[start++];
    }
  }
  std::cout << max << '\n';

  return 0;
}