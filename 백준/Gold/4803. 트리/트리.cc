#include <iostream>
#include <vector>

bool visited[501];
std::vector<int> tree[501];

bool dfs(int current, int pre);

int main() {
  int n, m, index = 0;
  while (1) {
    std::cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    for (int i = 1; i <= n; i++)
      tree[i].clear();
    std::fill(visited, visited + 501, false);
    int u, v;
    for (int i = 0; i < m; i++) {
      std::cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    int T = 0;
    for (int i = 1; i <= n; i++) {
      if (!visited[i] && dfs(i, 0))
        T++;
    }

    std::cout << "Case " << ++index << ": ";
    if (T == 0)
      std::cout << "No trees.\n";
    else if (T == 1)
      std::cout << "There is one tree.\n";
    else
      std::cout << "A forest of " << T << " trees.\n";
  }

  return 0;
}

bool dfs(int current, int pre) {
  visited[current] = true;

  for (auto &next : tree[current]) {
    if (next == pre)
      continue;
    if (visited[next])
      return false;
    if (!dfs(next, current))
      return false;
  }

  return true;
}