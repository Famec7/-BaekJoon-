#include <iostream>

int main() {
  int N;
  int count = 0;

  std::cin >> N;
  for (int i = 5; i <= N; i *= 5)
    count += N / i;
  std::cout << count << '\n';

  return 0;
}