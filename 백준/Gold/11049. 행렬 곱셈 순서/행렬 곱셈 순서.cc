#include <iostream>

const int INF = 987654321;

int N;
int r[501], c[501];
int cache[501][501];

int solve(int start, int end);

int main() {
  std::cin >> N;

  std::fill(&cache[0][0], &cache[500][501], -1);
  for (int i = 1; i <= N; i++)
    std::cin >> r[i] >> c[i];

  std::cout << solve(1, N) << '\n';

  return 0;
}

int solve(int start, int end) {
  int &ret = cache[start][end];

  if (end - start == 1)
    return ret = r[start] * c[start] * c[end];
  if (start == end)
    return ret = 0; 
  if (ret != -1)
    return ret;

  ret = INF;
  for (int i = start; i < end; i++)
    ret = std::min(ret, solve(start, i) + solve(i + 1, end) +
                            r[start] * c[i] * c[end]);

  return ret;
}