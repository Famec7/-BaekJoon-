#include <iostream>

long long count_mod(long long n, long long mod);

int main() {
  long long n, m;
  long long count_2 = 0, count_5 = 0;

  std::cin >> n >> m;
  count_2 = count_mod(n, 2) - count_mod(n - m, 2) - count_mod(m, 2);
  count_5 = count_mod(n, 5) - count_mod(n - m, 5) - count_mod(m, 5);

  std::cout << std::min(count_2, count_5) << '\n';

  return 0;
}

long long count_mod(long long n, long long mod) {
  long long count = 0;
  for (long long i = mod; i <= n; i *= mod)
    count += n / i;

  return count;
}