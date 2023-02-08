#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

bool visited[100001];
int result[100001], count;
std::vector<int> graph[100001];

void bfs(int R);

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
  bfs(R);
  for (int i = 1; i <= N; i++)
    std::cout << result[i] << '\n';

  return 0;
}

void bfs(int R) {
  std::queue<int> q;
  if (visited[R])
    return;
  visited[R] = true;

  q.push(R);
  while (!q.empty()) {
    int u = q.front();
    count++;
    result[u] = count;
    q.pop();
    for (int i = 0; i < graph[u].size(); i++) {
      if (!visited[graph[u][i]]) {
        visited[graph[u][i]] = true;
        q.push(graph[u][i]);
      }
    }
  }
}