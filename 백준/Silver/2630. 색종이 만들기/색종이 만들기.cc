#include <iostream>

int N;
int blue, white;
int board[128][128];

void check(int y, int x, int size);

int main() {
  std::cin >> N;

  for (int y = 0; y < N; y++)
    for (int x = 0; x < N; x++)
      std::cin >> board[y][x];

  check(0, 0, N);
  std::cout << white << '\n' << blue << '\n';

  return 0;
}

void check(int y, int x, int size) {
  int color = board[y][x];
  for (int dy = y; dy < y + size; dy++) {
    for (int dx = x; dx < x + size; dx++) {
      if (color != board[dy][dx]) {
        check(y, x, size / 2);
        check(y, x + size / 2, size / 2);
        check(y + size / 2, x, size / 2);
        check(y + size / 2, x + size / 2, size / 2);
        return;
      }
    }
  }
  if (color == 0)
    white++;
  else
    blue++;
}