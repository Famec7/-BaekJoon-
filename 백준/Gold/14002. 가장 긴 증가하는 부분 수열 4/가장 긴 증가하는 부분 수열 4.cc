#include <iostream>
#include <vector>

int dp[1001];

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N + 1);
  int max = 0, index = 0;
  for (int i = 1; i <= N; i++) {
    std::cin >> A[i];
    int len = 0;
    for (int j = 1; j < i; j++) {
      if (A[j] < A[i])
        len = std::max(len, dp[j]);
    }
    dp[i] = len + 1;
    if (max < dp[i]) {
      max = dp[i];
      index = i;
    }
  }

  std::vector<int> result;
  for (int i = index; i >= 1; i--) {
    if (dp[i] == max) {
      result.push_back(A[i]);
      max--;
    }
  }
  std::cout << result.size() << '\n';
  for (int i = result.size() - 1; i >= 0; i--)
    std::cout << result[i] << ' ';
  std::cout << '\n';

  return 0;
}