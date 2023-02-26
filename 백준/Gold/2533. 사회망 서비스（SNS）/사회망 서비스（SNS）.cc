#include <iostream>
#include <vector>

int N, dp[1000001][2];
bool visited[1000001];
std::vector<int> network[1000001];

void solve(int node);

int main() {
  std::cin >> N;

  int u, v;
  for (int i = 0; i < N - 1; i++) {
    std::cin >> u >> v;
    network[u].push_back(v);
    network[v].push_back(u);
  }
  solve(1);
  std::cout << std::min(dp[1][0], dp[1][1]) << '\n';

  return 0;
}

void solve(int node) {
  visited[node] = true;
  dp[node][1] = 1;

  for (auto &next : network[node]) {
    if (visited[next])
      continue;
    solve(next);
    dp[node][0] += dp[next][1];
    dp[node][1] += std::min(dp[next][1], dp[next][0]);
  }
}