#include <iostream>

int main() {
  int n, wine[10000];
  int dp[10000];

  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> wine[i];

  dp[0] = wine[0];
  dp[1] = wine[1] + dp[0];
  dp[2] = std::max(std::max(wine[0], wine[1]) + wine[2], dp[1]);
  for (int i = 3; i < n; i++) {
    dp[i] = std::max(dp[i - 2], dp[i - 3] + wine[i - 1]) + wine[i];
    dp[i] = std::max(dp[i - 1], dp[i]);
  }

  std::cout << dp[n - 1] << '\n';

  return 0;
}