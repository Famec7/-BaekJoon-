#include <iostream>

int kth_string(long long num) {
  if (num == 1)
    return 0;

  long long exponent = 1;
  while (exponent * 2 < num) {
    exponent += exponent;
  }

  // a[k] = 1 - a[k - exponent]
  return 1 - kth_string(num - exponent);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  // 자연수 k 입력
  long long k = 0;
  std::cin >> k;

  int result = kth_string(k);
  std::cout << result << '\n';

  return 0;
}

/*
1 -> 0
2 -> 1 : 1
3 -> 1 : 1
4 -> 0 : 2
5 -> 1 : 1 = 5 - 2 * 2
6 -> 0 : 2 = 6 - 2 * 2
7 -> 0 : 3
8 -> 1 : 4
9 -> 1 : 1
10 -> 0 : 2
*/