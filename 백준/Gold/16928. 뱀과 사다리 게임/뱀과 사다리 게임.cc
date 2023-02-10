#include <iostream>
#include <queue>
#include <vector>

int N, M, result[101];
int board[101];

void bfs();

int main() {
  for (int i = 1; i <= 100; i++) {
    board[i] = i;
    result[i] = -1;
  }

  std::cin >> N >> M;

  int u, v;
  for (int i = 0; i < N + M; i++) {
    std::cin >> u >> v;
    board[u] = v;
  }

  result[1] = 0;
  bfs();

  std::cout << result[100] << '\n';

  return 0;
}

void bfs() {
  std::queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 1; i <= 6; i++) {
      int next = u + i;
      if (next > 100)
        continue;
      next = board[next];
      if (result[next] == -1) {
        result[next] = result[u] + 1;
        q.push(next);
      }
    }
  }
}