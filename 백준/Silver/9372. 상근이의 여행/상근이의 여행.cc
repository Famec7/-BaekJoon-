#include <iostream>

int main() {
  int T, N, M;

  std::cin >> T;
  while (T--) {
    std::cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++)
      std::cin >> a >> b;
    std::cout << N - 1 << '\n';
  }

  return 0;
}