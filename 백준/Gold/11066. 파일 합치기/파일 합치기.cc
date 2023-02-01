#include <iostream>

int K;
int cost[501], cache[501][501], sum[501];

int solve(int start, int end);

int main() {
  int T;

  std::cin >> T;
  while (T--) {
    std::fill(&cache[0][0], &cache[500][501], 0x3f3f3f3f);
    std::cin >> K;
    for (int i = 1; i <= K; i++) {
      std::cin >> cost[i];
      sum[i] = sum[i - 1] + cost[i];
    }

    std::cout << solve(1, K) << '\n';
  }

  return 0;
}

int solve(int start, int end) {
  int &ret = cache[start][end];

  if (ret != 0x3f3f3f3f)
    return ret;

  if (start >= end)
    return ret = 0;
  if (end - start == 1)
    return ret = cost[start] + cost[end];

  for (int i = start; i < end; i++) {
    int left = solve(start, i);
    int right = solve(i + 1, end);
    ret = std::min(ret, left + right);
  }

  return ret += sum[end] - sum[start - 1];
}