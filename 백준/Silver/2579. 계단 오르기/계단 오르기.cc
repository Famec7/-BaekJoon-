#include <iostream>

int main() {
  int n, stairs[300], dp[300];

  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> stairs[i];

  dp[0] = stairs[0];
  dp[1] = dp[0] + stairs[1];
  dp[2] = std::max(stairs[0], stairs[1]) + stairs[2];

  for (int i = 3; i < n; i++)
    dp[i] = std::max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
  std::cout << dp[n - 1] << '\n';

  return 0;
}