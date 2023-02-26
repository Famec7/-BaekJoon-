#include <iostream>
#include <vector>

int N, population[10001], dp[10001][2];
bool visited[10001];
std::vector<int> route[10001];

void best(int node);

int main() {
  std::cin >> N;
  for (int i = 1; i <= N; i++)
    std::cin >> population[i];

  int u, v;
  for (int i = 0; i < N - 1; i++) {
    std::cin >> u >> v;
    route[u].push_back(v);
    route[v].push_back(u);
  }
  best(1);
  std::cout << std::max(dp[1][0], dp[1][1]) << '\n';

  return 0;
}

void best(int node) {
  visited[node] = true;
  dp[node][1] = population[node];

  for (auto &next : route[node]) {
    if (visited[next])
      continue;
    best(next);
    dp[node][0] += std::max(dp[next][0], dp[next][1]);
    dp[node][1] += dp[next][0];
  }
}