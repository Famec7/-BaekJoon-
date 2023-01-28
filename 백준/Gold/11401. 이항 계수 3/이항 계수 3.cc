#include <iostream>

const long long MOD = 1000000007;
long long numerator = 1, denominator = 1;

long long power(long long exponent);

int main() {
  int N, K;

  std::cin >> N >> K;
  for (int i = N; i >= N - K + 1; i--)
    numerator = numerator * i % MOD;
  for (int i = 2; i <= K; i++)
    denominator = denominator * i % MOD;
  denominator = power(MOD - 2);

  std::cout << numerator * denominator % MOD << '\n';

  return 0;
}

long long power(long long exponent) {
  if (exponent == 0)
    return 1;

  long long half = power(exponent / 2);
  if (exponent % 2 == 0)
    return half * half % MOD;
  else
    return denominator * power(exponent - 1) % MOD;
}