#include <iostream>

int GCD(int a, int b);
int GCM(int a, int b);

int main() {
  int a, b;
  std::cin >> a >> b;

  std::cout << GCD(a, b) << '\n';
  std::cout << GCM(a, b) << '\n';

  return 0;
}

int GCD(int a, int b) {
  int min = std::min(a, b);
  int result = 0;

  for (int i = 1; i <= min; i++) {
    if (a % i == 0 && b % i == 0)
      result = i;
  }

  return result;
}

int GCM(int a, int b) {
  int gcd = GCD(a, b);

  return gcd * (a / gcd) * (b / gcd);
}