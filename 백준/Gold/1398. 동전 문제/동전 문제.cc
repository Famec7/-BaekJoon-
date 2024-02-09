#include <cmath>
#include <iostream>

long long dp[101];

void Tabulation() {
  const long long INF = (long long)pow(10, 15) + 1;
  const int COIN[3] = {1, 10, 25};

  for (int i = 1; i < 101; i++) {
    dp[i] = INF;
    for (int j = 0; j < 3; j++) {
      int prev_coin = i - COIN[j];
      if (prev_coin >= 0)
        dp[i] = std::min(dp[i], dp[prev_coin] + 1);
    }
  }
}

void Solve() {
  long long chocolate_price{};
  std::cin >> chocolate_price;

  long long result{};
  // 세 자릿수씩 끊어서 계산
  while (chocolate_price) {
    result += dp[chocolate_price % 100];
    chocolate_price /= 100;
  }

  std::cout << result << '\n';
}

int main() {
  Tabulation();

  int T{};
  std::cin >> T;

  while (T--) {
    Solve();
  }

  return 0;
}