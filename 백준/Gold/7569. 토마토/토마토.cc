#include <iostream>
#include <queue>

typedef struct {
  int x, y, z;
} dimension;

std::queue<dimension> q;
int M, N, H, tomato[100][100][100], result;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs();

int main() {
  std::cin >> M >> N >> H;

  for (int z = 0; z < H; z++) {
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        std::cin >> tomato[z][y][x];
        if (tomato[z][y][x] == 1)
          q.push({x, y, z});
      }
    }
  }

  bfs();
  for (int z = 0; z < H; z++) {
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        if (tomato[z][y][x] == 0) {
          std::cout << "-1" << '\n';
          return 0;
        }
        result = std::max(result, tomato[z][y][x]);
      }
    }
  }

  std::cout << result - 1 << '\n';

  return 0;
}

void bfs() {
  while (!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    int z = q.front().z;
    q.pop();

    for (int i = 0; i < 6; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if (nz < 0 || ny < 0 || nx < 0 || ny >= N || nx >= M || nz >= H)
        continue;

      if (tomato[nz][ny][nx] == 0) {
        q.push({nx, ny, nz});
        tomato[nz][ny][nx] = tomato[z][y][x] + 1;
      }
    }
  }
}