#include <iostream>

int f[41];
int count_first = 0, count_second = 0;

int fib(int n);
int fibonacci(int n);

int main() {
  int n;

  std::cin >> n;
  int result_first = fib(n), result_second = fibonacci(n);
  std::cout << count_first << ' ' << count_second << '\n';

  return 0;
}

int fib(int n) {
  if (n == 1 || n == 2) {
    count_first++;
    return 1;
  }
  return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
  f[1] = 1, f[2] = 1;
  for (int i = 3; i <= n; i++) {
    count_second++;
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}