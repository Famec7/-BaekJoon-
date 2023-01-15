#include <iostream>

int binomial_coefficient(int N, int K);

int main() {
  int N, K;

  std::cin >> N >> K;
  std::cout << binomial_coefficient(N, K) << '\n';

  return 0;
}

int binomial_coefficient(int N, int K) {
  if (N == K || K == 0)
    return 1;

  return binomial_coefficient(N - 1, K) + binomial_coefficient(N - 1, K - 1);
}