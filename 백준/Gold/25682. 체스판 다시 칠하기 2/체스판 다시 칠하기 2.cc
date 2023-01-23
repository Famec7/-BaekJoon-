#include <iostream>

int pSum[2001][2001];

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  char s;
  int N, M, K, result = 2000001;
  std::cin >> N >> M >> K;

  for (int y = 1; y <= N; y++) {
    for (int x = 1; x <= M; x++) {
      std::cin >> s;
      if (((x + y) % 2 == 0 && s != 'B') || ((x + y) % 2 != 0 && s == 'B'))
        pSum[y][x] = 1;
      pSum[y][x] += pSum[y][x - 1] + pSum[y - 1][x] - pSum[y - 1][x - 1];
    }
  }
  int count = 0;
  for (int y = K; y <= N; y++) {
    for (int x = K; x <= M; x++) {
      count = pSum[y][x] - pSum[y - K][x] - pSum[y][x - K] + pSum[y - K][x - K];
      result = std::min(result, std::min(count, K * K - count));
    }
  }
  std::cout << result << '\n';

  return 0;
}