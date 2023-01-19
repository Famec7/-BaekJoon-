#include <iostream>

int N;
int operation(int n);
int cache[1000001];

int main() {
  std::fill(cache, cache + 1000001, 0);
  std::cin >> N;
  std::cout << operation(N) << '\n';

  return 0;
}

int operation(int n) {
  if (n == 1)
    return 0;

  int &ret = cache[n];
  if (ret > 0)
    return ret;

  ret = operation(n - 1) + 1;
  if (n % 2 == 0)
    ret = std::min(ret, operation(n / 2) + 1);
  if (n % 3 == 0)
    ret = std::min(ret, operation(n / 3) + 1);
  
  return ret;
}