#include <algorithm>
#include <iostream>
#include <vector>

bool visited[50][50];
int N, M, K;
int farm[50][50];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};

void dfs(int y, int x);

int main() {
  int T;

  std::cin >> T;
  while (T--) {
    std::cin >> M >> N >> K;
    int X, Y;

    std::fill(&farm[0][0], &farm[49][50], 0);
    std::fill(&visited[0][0], &visited[49][50], false);
    for (int i = 0; i < K; i++) {
      std::cin >> X >> Y;
      farm[Y][X] = 1;
    }

    int result = 0;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        if (farm[y][x] == 1 && !visited[y][x]) {
          visited[y][x] = true;
          dfs(y, x);
          result++;
        }
      }
    }
    std::cout << result << '\n';
  }

  return 0;
}

void dfs(int y, int x) {

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= M)
      continue;
    if (farm[ny][nx] == 1 && !visited[ny][nx]) {
      visited[ny][nx] = true;
      dfs(ny, nx);
    }
  }
}