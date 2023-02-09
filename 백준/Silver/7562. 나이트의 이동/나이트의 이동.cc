#include <iostream>
#include <queue>

int I, result = 0;
int Y, X;
int dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dx[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int count[300][300];
bool visited[300][300];

void bfs(int y, int x);

int main() {
  int T;
  int start_x, start_y;

  std::cin >> T;
  while (T--) {
    std::fill(&visited[0][0], &visited[299][300], false);
    std::fill(&count[0][0], &count[299][300], 0);
    std::cin >> I;
    std::cin >> start_x >> start_y;
    std::cin >> X >> Y;
    bfs(start_y, start_x);
    std::cout << count[Y][X] << '\n';
  }

  return 0;
}

void bfs(int y, int x) {
  std::queue<std::pair<int, int>> q;

  q.push({y, x});
  visited[y][x] = true;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;

    q.pop();
    if (y == Y && x == X)
      return;

    for (int i = 0; i < 8; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= I || nx >= I)
        continue;

      if (!visited[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = true;
        count[ny][nx] = count[y][x] + 1;
      }
    }
  }
}