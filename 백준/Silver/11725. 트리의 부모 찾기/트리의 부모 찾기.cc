#include <iostream>
#include <vector>

int N, parent[100001];
std::vector<int> tree[100001];

void dfs(int node);

int main() {

  std::cin >> N;
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    std::cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs(1);
  for (int i = 2; i <= N; i++)
    std::cout << parent[i] << '\n';

  return 0;
}

void dfs(int node) {
  for (int i = 0; i < tree[node].size(); i++) {
    int next = tree[node][i];

    if (!parent[next]) {
      parent[next] = node;
      dfs(next);
    }
  }
}