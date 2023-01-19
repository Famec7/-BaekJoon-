#include <iostream>

const long long MOD = 1000000000;
long long N, cache[101][10];
long long stair_num(long long n, long long digit);

int main() {
  std::fill(&cache[0][0], &cache[100][10], 0);
  std::cin >> N;
  for (int i = 0; i < 10; i++)
    cache[1][i] = 1;

  long long count = 0;
  for (int i = 1; i < 10; i++)
    count += stair_num(N, i);

  std::cout << count % MOD << '\n';

  return 0;
}

long long stair_num(long long n, long long digit) {
  if (n == 1)
    return cache[n][digit];

  long long &ret = cache[n][digit];
  if (ret > 0)
    return ret;

  if (digit == 0)
    ret = stair_num(n - 1, 1);
  else if (digit == 9)
    ret = stair_num(n - 1, 8);
  else
    ret = stair_num(n - 1, digit - 1) + stair_num(n - 1, digit + 1);

  return ret % MOD;
}