#include <iostream>

int n, max;
int cache[100000];
int sequence[100000];

int main() {
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> sequence[i];
    cache[i] = sequence[i];
  }
  max = cache[0];
  for (int i = 1; i < n; i++) {
    cache[i] = std::max(cache[i], cache[i - 1] + sequence[i]);
    max = std::max(max, cache[i]);
  }
  std::cout << max << '\n';

  return 0;
}