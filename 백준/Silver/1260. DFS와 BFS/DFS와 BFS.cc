#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> graph[1001], dfs_result, bfs_result;
bool visited[1001];

void dfs(int start);
void bfs(int start);

int main() {
  int N, M, u, v;
  int V;

  std::cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= N; i++)
    std::sort(graph[i].begin(), graph[i].end());

  dfs(V);
  std::fill(visited, visited + 1001, false);
  bfs(V);
  for (const auto &d : dfs_result)
    std::cout << d << ' ';
  std::cout << '\n';
  for (const auto &b : bfs_result)
    std::cout << b << ' ';
  std::cout << '\n';

  return 0;
}

void dfs(int start) {
  if (visited[start])
    return;
  visited[start] = true;
  dfs_result.push_back(start);

  for (int i = 0; i < graph[start].size(); i++)
    dfs(graph[start][i]);
}

void bfs(int start) {
  std::queue<int> q;
  visited[start] = true;

  q.push(start);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    bfs_result.push_back(u);
    for (int i = 0; i < graph[u].size(); i++) {
      if (!visited[graph[u][i]]) {
        visited[graph[u][i]] = true;
        q.push(graph[u][i]);
      }
    }
  }
}