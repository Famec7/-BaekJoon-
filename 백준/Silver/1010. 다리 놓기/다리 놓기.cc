#include <iostream>

int cache[1001][1001];
int binomial_coefficient(int M, int N);

int main() {
  int T;
  int N, M;

  std::cin >> T;
  std::fill(&cache[0][0], &cache[1000][1001], -1);
  while (T--) {
    std::cin >> N >> M;
    std::cout << binomial_coefficient(M, N) << '\n';
  }

  return 0;
}

int binomial_coefficient(int M, int N) {
  if (M == N || N == 0)
    return 1;

  int &ret = cache[M][N];
  if (ret != -1)
    return ret;

  return ret = binomial_coefficient(M - 1, N) +
               binomial_coefficient(M - 1, N - 1);
}