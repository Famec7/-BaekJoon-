#include <iostream>

int N, M;
int m[100], c[100];
int cache[100][10001];

int disable(int index, int cost);

int main() {
  std::cin >> N >> M;

  std::fill(&cache[0][0], &cache[99][10001], -1);
  for (int i = 0; i < N; i++)
    std::cin >> m[i];
  for (int i = 0; i < N; i++)
    std::cin >> c[i];

  int cost = 0;
  while (1) {
    if (disable(0, cost) >= M)
      break;
    cost++;
  }
  std::cout << cost << '\n';

  return 0;
}

int disable(int index, int cost) {
  if (index > N - 1)
    return 0;
  int &ret = cache[index][cost];

  if (ret != -1)
    return ret;

  ret = disable(index + 1, cost);
  if (c[index] <= cost)
    ret = std::max(ret, m[index] + disable(index + 1, cost - c[index]));

  return ret;
}