#include <iostream>

int main() {
  int n, max = 0;
  int dp[500][500];

  std::cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i + 1; j++)
      std::cin >> dp[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == j)
        dp[i][j] += dp[i - 1][j - 1];
      else if (j == 0)
        dp[i][0] += dp[i - 1][0];
      else
        dp[i][j] += std::max(dp[i - 1][j - 1], dp[i - 1][j]);
      max = std::max(max, dp[i][j]);
    }
  }

  std::cout << max << '\n';

  return 0;
}