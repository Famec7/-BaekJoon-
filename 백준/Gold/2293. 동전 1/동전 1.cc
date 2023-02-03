#include <iostream>

int n, k;
int coins[100], dp[10001];

int main() {
  std::cin >> n >> k;
  for (int i = 0; i < n; i++)
    std::cin >> coins[i];

  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int coin = coins[i];
    for (int j = coin; j <= k; j++) {
      dp[j] += dp[j - coin];
    }
  }
  std::cout << dp[k] << '\n';

  return 0;
}