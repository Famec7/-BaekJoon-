#include <algorithm>
#include <iostream>
#include <vector>

int n, W[10001];
int dp[10001][2];
bool visited[10001];
std::vector<int> tree[10001], result;

void solve(int node);
void track(int prev, int current, int include);

int main() {
  std::cin >> n;

  for (int i = 1; i <= n; i++)
    std::cin >> W[i];

  int u, v;
  for (int i = 0; i < n - 1; i++) {
    std::cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  solve(1);

  int size = 0;
  if (dp[1][0] < dp[1][1]) {
    size = dp[1][1];
    track(-1, 1, 1);
  } else {
    size = dp[1][0];
    track(-1, 1, 0);
  }
  std::sort(result.begin(), result.end());

  std::cout << size << '\n';
  for (const auto &ret : result)
    std::cout << ret << ' ';
  std::cout << '\n';

  return 0;
}

void solve(int node) {
  visited[node] = true;
  dp[node][1] = W[node];
  for (auto &child : tree[node]) {
    if (visited[child])
      continue;

    solve(child);
    dp[node][0] += std::max(dp[child][1], dp[child][0]);
    dp[node][1] += dp[child][0];
  }
}

void track(int prev, int current, int include) {
  if (include) {
    result.push_back(current);
    for (auto &next : tree[current]) {
      if (next == prev)
        continue;
      track(current, next, 0);
    }
  } else {
    for (auto &next : tree[current]) {
      if (next == prev)
        continue;
      if (dp[next][0] < dp[next][1])
        track(current, next, 1);
      else
        track(current, next, 0);
    }
  }
}