#include <algorithm>
#include <iostream>
#include <string>

int dp[1001][1001];

int main() {
  std::string a, b;

  std::cin >> a >> b;
  for (int i = 1; i <= b.length(); i++) {
    for (int j = 1; j <= a.length(); j++) {
      if (a[j - 1] == b[i - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  std::string result = "";
  int col = a.length();
  int row = b.length();
  while (dp[row][col]) {
    if (dp[row][col] == dp[row][col - 1])
      col--;
    else if (dp[row][col] == dp[row - 1][col])
      row--;
    else {
      result += a[col - 1];
      col--, row--;
    }
  }
  std::cout << result.length() << '\n';
  if (result.length() > 0) {
    std::reverse(result.begin(), result.end());
    std::cout << result << '\n';
  }

  return 0;
}