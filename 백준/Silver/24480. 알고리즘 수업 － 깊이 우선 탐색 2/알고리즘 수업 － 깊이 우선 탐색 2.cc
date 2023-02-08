#include <algorithm>
#include <iostream>
#include <vector>

bool visited[100001];
int result[100001], count;
std::vector<int> graph[100001];

void dfs(int R);

int main() {
  int N, M, R;
  int u, v;

  std::cin >> N >> M >> R;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= N; i++)
    std::sort(graph[i].begin(), graph[i].end(), std::greater<int>());
  dfs(R);
  for (int i = 1; i <= N; i++)
    std::cout << result[i] << '\n';

  return 0;
}

void dfs(int R) {
  if (visited[R])
    return;
  visited[R] = true;

  count++;
  result[R] += count;

  for (int i = 0; i < graph[R].size(); i++)
    dfs(graph[R][i]);
}