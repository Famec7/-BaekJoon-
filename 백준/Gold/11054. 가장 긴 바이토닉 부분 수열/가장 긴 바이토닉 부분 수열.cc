#include <iostream>

int main() {
  int N, A[1000], max = 0;
  int dp[1001], r_dp[1001];

  std::cin >> N;
  for (int i = 0; i < N; i++)
    std::cin >> A[i];

  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (A[i] > A[j] && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    r_dp[i] = 1;
    for (int j = N - 1; j > i; j--) {
      if (A[i] > A[j] && r_dp[i] < r_dp[j] + 1)
        r_dp[i] = r_dp[j] + 1;
    }
    max = std::max(max, dp[i] + r_dp[i]);
  }
  std::cout << max - 1 << '\n';

  return 0;
}