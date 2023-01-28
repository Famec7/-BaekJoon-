#include <iostream>

int N;
int minus, zero, one;
int board[2187][2187];

void split(int y, int x, int size);

int main() {
  std::cin >> N;

  for (int y = 0; y < N; y++)
    for (int x = 0; x < N; x++)
      std::cin >> board[y][x];

  split(0, 0, N);
  std::cout << minus << '\n' << zero << '\n' << one << '\n';

  return 0;
}

void split(int y, int x, int size) {
  int flag = board[y][x];
  for (int dy = y; dy < y + size; dy++) {
    for (int dx = x; dx < x + size; dx++) {
      if (flag != board[dy][dx]) {
        split(y, x, size / 3);
        split(y, x + size / 3, size / 3);
        split(y, x + size * 2 / 3, size / 3);
        split(y + size / 3, x + size * 2 / 3, size / 3);
        split(y + size / 3, x, size / 3);
        split(y + size * 2 / 3, x, size / 3);
        split(y + size * 2 / 3, x + size / 3, size / 3);
        split(y + size / 3, x + size / 3, size / 3);
        split(y + size * 2 / 3, x + size * 2 / 3, size / 3);
        return;
      }
    }
  }
  if (flag == -1)
    minus++;
  else if (flag == 0)
    zero++;
  else
    one++;
}