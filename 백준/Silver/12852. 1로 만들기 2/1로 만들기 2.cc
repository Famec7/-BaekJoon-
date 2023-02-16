#include <iostream>

int dp[1000001];

int main() {
  int X;

  std::cin >> X;
  for (int i = 1; i <= X; i++)
    dp[i] = i - 1;
  for (int i = 2; i <= X; i++) {
    if (i % 2 == 0)
      dp[i] = std::min(dp[i], dp[i / 2]);
    if (i % 3 == 0)
      dp[i] = std::min(dp[i], dp[i / 3]);
    dp[i] = std::min(dp[i], dp[i - 1]) + 1;
  }
  std::cout << dp[X] << '\n';
  while (X) {
    std::cout << X << ' ';
    if(X == 1)
      break;
    if (dp[X] == dp[X - 1] + 1)
      X -= 1;
    else if (X % 2 == 0 && dp[X] == dp[X / 2] + 1)
      X /= 2;
    else if (X % 3 == 0 && dp[X] == dp[X / 3] + 1)
      X /= 3;
  }
  std::cout << '\n';

  return 0;
}