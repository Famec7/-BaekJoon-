#include <iostream>

int pSum[1025][1025];
int array[1025][1025];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int N, M;

  std::cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> array[i][j];
      pSum[i][j] =
          pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + array[i][j];
    }
  }

  int x1, y1, x2, y2;
  while (M--) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << pSum[x2][y2] - pSum[x2][y1 - 1] - pSum[x1 - 1][y2] +
                     pSum[x1 - 1][y1 - 1]
              << '\n';
  }

  return 0;
}