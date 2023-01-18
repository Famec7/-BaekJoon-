#include <iostream>

int N, cache[1000][3];
int R[1000], G[1000], B[1000];

int main() {
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> R[i] >> G[i] >> B[i];
    cache[i][0] = std::min(cache[i - 1][1], cache[i - 1][2]) + R[i];
    cache[i][1] = std::min(cache[i - 1][0], cache[i - 1][2]) + G[i];
    cache[i][2] = std::min(cache[i - 1][0], cache[i - 1][1]) + B[i];
  }
  std::cout << std::min(cache[N - 1][0],
                        std::min(cache[N - 1][1], cache[N - 1][2]))
            << '\n';

  return 0;
}