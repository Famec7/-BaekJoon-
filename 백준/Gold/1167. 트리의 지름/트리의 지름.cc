#include <iostream>
#include <vector>

int V, max, maxNode;
std::vector<std::pair<int, int>> tree[100001];
bool visited[100001];

void dfs(int node, int dist);

int main() {

  std::cin >> V;
  int from, to, dist;
  for (int i = 0; i < V; i++) {
    std::cin >> from;
    while (1) {
      std::cin >> to;
      if (to == -1)
        break;
      std::cin >> dist;
      tree[from].push_back({to, dist});
    }
  }
  dfs(1, 0);
  std::fill(visited, visited + 100001, false);
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