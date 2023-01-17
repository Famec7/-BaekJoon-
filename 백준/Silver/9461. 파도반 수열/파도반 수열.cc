#include <iostream>

long long cache[101];
long long P(long long N);

int main() {
  long long T, N;

  std::cin >> T;
  while (T--) {
    std::cin >> N;
    std::cout << P(N) << '\n';
  }

  return 0;
}

long long P(long long N) {
  cache[0] = 0;
  cache[1] = 1;
  cache[2] = 1;

  for (long long i = 3; i <= N; i++)
    cache[i] = cache[i - 2] + cache[i - 3];

  return cache[N];
}