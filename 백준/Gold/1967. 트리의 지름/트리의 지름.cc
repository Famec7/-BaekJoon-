#include <iostream>
#include <vector>

int n, max, maxNode;
std::vector<std::pair<int, int>> tree[10001];
bool visited[10001];

void dfs(int node, int dist);

int main() {

  std::cin >> n;
  int from, to, dist;
  for (int i = 0; i < n - 1; i++) {
    std::cin >> from >> to >> dist;
    tree[from].push_back({to, dist});
    tree[to].push_back({from, dist});
  }
  dfs(1, 0);
  std::fill(visited, visited + 10001, false);
  dfs(maxNode, 0);
  std::cout << max << '\n';

  return 0;
}

void dfs(int node, int dist) {
  bool &ret = visited[node];

  if (ret)
    return;
  if (max < dist) {
    max = dist;
    maxNode = node;
  }
  ret = true;
  for (int i = 0; i < tree[node].size(); i++) {
    int next = tree[node][i].first;
    int nDist = tree[node][i].second;
    dfs(next, nDist + dist);
  }
}