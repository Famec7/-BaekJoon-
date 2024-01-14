#include <iostream>

int cal_route(int col, int row) {
  long long result = 1;

  int end = col + row + 1;
  int j = 1;
  for (int i = col + 1; i < end; i++) {
    result *= i;
    while (j <= row && result % j == 0) {
      result /= j;
      j++;
    }
  }

  return result;
}

int main() {
  int N = 0, M = 0, K = 0;
  std::cin >> N >> M >> K;

  K = K == 0 ? 0 : K - 1;
  int K_col = K % M;
  int K_row = K / M;

  int K_to_M = (M - 1) - K_col;
  int K_to_N = (N - 1) - K_row;

  int result = cal_route(K_col, K_row) * cal_route(K_to_M, K_to_N);
  std::cout << result << '\n';

  return 0;
}
