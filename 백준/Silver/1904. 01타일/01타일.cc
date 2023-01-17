#include <iostream>

const int MOD = 15746;
int cache[1000001];
int binary(int N);

int main() {
  int N;
  std::cin >> N;

  std::cout << binary(N) << '\n';

  return 0;
}

int binary(int N) {
  cache[1] = 1;
  cache[2] = 2;

  for (int i = 3; i <= N; i++)
    cache[i] = (cache[i - 2] + cache[i - 1]) % MOD;

  return cache[N];
}