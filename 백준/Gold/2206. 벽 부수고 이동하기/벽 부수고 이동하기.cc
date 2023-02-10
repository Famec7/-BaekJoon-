#include <iostream>
#include <queue>
#include <string>

typedef struct {
  int x, y;
  int block;
} matrix;

int N, M;
int map[1000][1000];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int result[1000][1000][2];

int bfs();

int main() {
  std::string s;

  std::cin >> N >> M;
  for (int i = 0; i < N; i++) {
    std::cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == '0')
        map[i][j] = 0;
      else
        map[i][j] = 1;
    }
  }
  std::cout << bfs() << '\n';

  return 0;
}

int bfs() {
  std::queue<matrix> q;

  result[0][0][1] = 1;
  q.push({0, 0, 1});
  while (!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    int block = q.front().block;
    q.pop();

    if (x == M - 1 && y == N - 1)
      return result[y][x][block];
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (nx < 0 || ny < 0 || nx >= M || ny >= N)
        continue;
      if (map[ny][nx] == 1 && block) {
        q.push({nx, ny, 0});
        result[ny][nx][0] = result[y][x][block] + 1;
      } else if (map[ny][nx] == 0 && result[ny][nx][block] == 0) {
        q.push({nx, ny, block});
        result[ny][nx][block] = result[y][x][block] + 1;
      }
    }
  }

  return -1;
}