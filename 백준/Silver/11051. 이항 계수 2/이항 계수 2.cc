#include <iostream>

const int MOD = 10007;
int cache[1001][1001];
int binomial_coefficient(int N, int K);

int main() {
  int N, K;

  std::fill(&cache[0][0], &cache[1000][1001], -1);
  std::cin >> N >> K;
  std::cout << binomial_coefficient(N, K) << '\n';

  return 0;
}

int binomial_coefficient(int N, int K) {
  if (N == K || K == 0)
    return 1;

  int &ret = cache[N][K];
  if (ret != -1)
    return ret;

  return ret = (binomial_coefficient(N - 1, K) +
                binomial_coefficient(N - 1, K - 1)) %
               MOD;
}