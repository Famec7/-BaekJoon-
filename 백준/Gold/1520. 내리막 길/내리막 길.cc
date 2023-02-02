#include <iostream>

const int INF = 987654321;

int N, M;
int board[500][500], cache[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solve(int y, int x);

int main() {
  std::cin >> M >> N;

  std::fill(&cache[0][0], &cache[500][501], -1);
  for (int y = 0; y < M; y++)
    for (int x = 0; x < N; x++)
      std::cin >> board[y][x];

  std::cout << solve(0, 0) << '\n';

  return 0;
}

int solve(int y, int x) {
  if (y == M - 1 && x == N - 1)
    return 1;

  int &ret = cache[y][x];
  if (ret != -1)
    return ret;

  ret = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny >= 0 && nx >= 0 && ny < M && nx < N)
      if (board[y][x] > board[ny][nx])
        ret += solve(ny, nx);
  }

  return ret;
}