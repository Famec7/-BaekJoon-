#include <iostream>
#include <vector>

int N, M, result = 987654321;
int board[51][51];
int check(int x, int y);

int main() {
  std::cin >> N >> M;
  char tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> tmp;
      if (tmp == 'B')
        board[i][j] = 1;
      else if (tmp == 'W')
        board[i][j] = 0;
    }
  }

  for (int i = 0; i <= N - 8; i++) {
    for (int j = 0; j <= M - 8; j++) {
      result = std::min(result, check(i, j));
    }
  }
  std::cout << result << '\n';

  return 0;
}

int check(int x, int y) {
  int count_B = 0, count_W = 0;
  for (int i = x; i < x + 8; i++) {
    for (int j = y; j < y + 8; j++) {
      if (board[i][j] == (i + j) % 2)
        count_B++;
      if (board[i][j] == (i + j + 1) % 2)
        count_W++;
    }
  }
  return std::min(count_B, count_W);
}