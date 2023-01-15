#include <iostream>

int GCD(int a, int b);

int main() {
  int N;
  int r[100];

  std::cin >> N;
  for (int i = 0; i < N; i++)
    std::cin >> r[i];
  for (int i = 1; i < N; i++) {
    int gcd = GCD(r[0], r[i]);
    std::cout << r[0] / gcd << "/" << r[i] / gcd << '\n';
  }

  return 0;
}

int GCD(int a, int b) {
  if (b == 0)
    return a;
  return GCD(b, a % b);
}