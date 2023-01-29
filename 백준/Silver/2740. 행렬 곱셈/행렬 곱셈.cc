#include <iostream>

int main() {
  int A[100][100], B[100][100];
  int N, M, K;

  std::cin >> N >> M;
  for (int row = 0; row < N; row++)
    for (int col = 0; col < M; col++)
      std::cin >> A[row][col];
  std::cin >> M >> K;
  for (int row = 0; row < M; row++)
    for (int col = 0; col < K; col++)
      std::cin >> B[row][col];

  int result[100][100] = {
      0,
  };
  for (int i = 0; i < N; i++)
    for (int j = 0; j < K; j++)
      for (int k = 0; k < M; k++)
        result[i][j] += A[i][k] * B[k][j];

  for (int row = 0; row < N; row++) {
    for (int col = 0; col < K; col++) {
      std::cout << result[row][col] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}