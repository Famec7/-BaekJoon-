#include <iostream>

int main() {
  int N, K, A[10];
  std::cin >> N >> K;

  for (int i = 0; i < N; i++)
    std::cin >> A[i];

  int count = 0;
  for (int i = N - 1; i >= 0; i--) {
    count += K / A[i];
    K %= A[i];
  }
  std::cout << count << '\n';

  return 0;
}