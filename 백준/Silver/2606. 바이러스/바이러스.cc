#include <iostream>
#include <vector>

std::vector<int> network[101];
bool visited[101];
int result;

void dfs(int start);

int main() {
  int N, M, u, v;
  std::cin >> N >> M;

  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    network[u].push_back(v);
    network[v].push_back(u);
  }
  dfs(1);
  std::cout << result - 1 << '\n';

  return 0;
}

void dfs(int start) {
  if (visited[start])
    return;
  visited[start] = true;
  result++;

  for (int i = 0; i < network[start].size(); i++)
    dfs(network[start][i]);
}