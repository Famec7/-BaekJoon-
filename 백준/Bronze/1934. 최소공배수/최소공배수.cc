#include <iostream>

int GCD(int a, int b);

int main() {
  int T;
  int A, B;

  std::cin >> T;
  while (T--) {
    std::cin >> A >> B;
    int gcd = GCD(A, B);
    std::cout << gcd * (A / gcd) * (B / gcd) << '\n';
  }

  return 0;
}

int GCD(int a, int b) {
  if (b == 0)
    return a;

  return GCD(b, a % b);
}