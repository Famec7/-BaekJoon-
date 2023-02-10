#include <iostream>
#include <queue>

std::queue<std::pair<int, int>> q;
int M, N, tomato[1000][1000], result;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs();

int main() {
  std::cin >> M >> N;
  int start_y, start_x;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      std::cin >> tomato[y][x];
      if (tomato[y][x] == 1)
        q.push({y, x});
    }
  }

  bfs();
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (tomato[y][x] == 0) {
        result = 0;
        break;
      }
      result = std::max(result, tomato[y][x]);
    }
    if (result == 0)
      break;
  }
  std::cout << result - 1 << '\n';

  return 0;
}

void bfs() {
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M)
        continue;

      if (tomato[ny][nx] == 0) {
        q.push({ny, nx});
        tomato[ny][nx] = tomato[y][x] + 1;
      }
    }
  }
}