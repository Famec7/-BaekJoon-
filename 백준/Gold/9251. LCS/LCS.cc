#include <iostream>
#include <string>

int dp[1001][1001];

int main() {
  std::string s1, s2;

  std::cin >> s1 >> s2;

  int length1 = s1.length(), length2 = s2.length();
  for (int i = 1; i <= length1; i++) {
    for (int j = 1; j <= length2; j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  std::cout << dp[length1][length2] << '\n';

  return 0;
}