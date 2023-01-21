#include <iostream>

int N, K;
int W[100], V[100];
int cache[100001][101];

int packing(int weight, int item);

int main() {
  std::cin >> N >> K;

  for (int i = 0; i < N; i++)
    std::cin >> W[i] >> V[i];

  std::fill(&cache[0][0], &cache[100000][101], -1);
  std::cout << packing(K, 0) << '\n';

  return 0;
}

int packing(int weight, int item) {
  if (item == N)
    return 0;
  int &ret = cache[weight][item];
  if (ret != -1)
    return ret;

  ret = packing(weight, item + 1);
  if (W[item] <= weight)
    ret = std::max(ret, packing(weight - W[item], item + 1) + V[item]);

  return ret;
}