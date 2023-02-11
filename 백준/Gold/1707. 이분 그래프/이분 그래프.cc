#include <iostream>
#include <vector>

int V, E;
std::vector<int> graph[20001];
int colors[20001];
bool result;

void dfs(int start, int color);

int main() {
  int K;
  int u, v;

  std::cin >> K;
  while (K--) {
    result = true;
    std::cin >> V >> E;
    for (int i = 0; i < E; i++) {
      std::cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    for (int i = 1; i <= V; i++) {
      if (colors[i] == 0)
        dfs(i, 1);
    }

    if (result)
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
    std::fill(colors, colors + 20001, 0);
    for (int i = 1; i <= V; i++)
      graph[i].clear();
  }

  return 0;
}

void dfs(int start, int color) {
  if (colors[start] == 0)
    colors[start] = color;

  for (int i = 0; i < graph[start].size(); i++) {
    int next = graph[start][i];
    if (color == colors[next])
      result = false;
    else if (!colors[next])
      dfs(next, 3 - color);
  }
}