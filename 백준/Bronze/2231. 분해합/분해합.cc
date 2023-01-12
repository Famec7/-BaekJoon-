#include <iostream>

int DigitGenerator(int digit);

int main() {
  int N;

  std::cin >> N;
  int result = 0, generator;
  for (int i = N - 54; i < N; i++) {
    generator = DigitGenerator(i) + i;
    if (N == generator) {
      result = i;
      break;
    }
  }
  std::cout << result << '\n';

  return 0;
}

int DigitGenerator(int digit) {
  if (digit <= 0)
    return 0;
  return (digit % 10) + DigitGenerator(digit / 10);
}