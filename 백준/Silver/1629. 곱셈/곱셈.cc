#include <iostream>

long long A, B, C;
long long power(long long b);

int main() {
  std::cin >> A >> B >> C;
  std::cout << power(B) % C << "\n";

  return 0;
}

long long power(long long b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return A % C;

  long long half = power(b / 2) % C;
  if (b % 2 == 0)
    return half * half % C;
  return half * half % C * A % C;
}