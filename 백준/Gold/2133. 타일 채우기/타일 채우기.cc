#include <iostream>

// f(2) = 3
// f(n) = f(2) * f(n - 2) + f(n - 4) * 2 + f(n - 6) * 2 + ... + 2
int dp[31];

int main() {
  int N = 0;
  std::cin >> N;

  dp[2] = 3;
  for (int i = 4; i <= N; i += 2) {
    dp[i] = dp[2] * dp[i - 2];
    for (int j = i - 4; j >= 2; j -= 2)
      dp[i] += 2 * dp[j];
    dp[i] += 2;
  }

  std::cout << dp[N] << '\n';

  return 0;
}