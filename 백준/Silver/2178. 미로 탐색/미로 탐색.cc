#include <iostream>
#include <queue>
#include <string>

int N, M;
int maze[100][100];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void bfs(int y, int x);

int main() {
  std::string s;

  std::cin >> N >> M;
  for (int i = 0; i < N; i++) {
    std::cin >> s;
    for (int j = 0; j < M; j++)
      maze[i][j] = s[j] - '0';
  }
  bfs(0, 0);
  std::cout << maze[N - 1][M - 1] << '\n';

  return 0;
}

void bfs(int y, int x) {
  std::queue<std::pair<int, int>> q;

  q.push({y, x});
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;

    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (nx < 0 || ny < 0 || nx >= M || ny >= N)
        continue;
      if (maze[ny][nx] == 1) {
        maze[ny][nx] = maze[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }
}