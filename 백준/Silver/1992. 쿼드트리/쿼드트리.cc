#include <iostream>
#include <string>

int N;
int board[64][64];

void zip(int y, int x, int size);

int main() {
  std::cin >> N;

  std::string s;
  for (int y = 0; y < N; y++) {
    std::cin >> s;
    for (int x = 0; x < N; x++)
      board[y][x] = s[x] - '0';
  }

  zip(0, 0, N);

  return 0;
}

void zip(int y, int x, int size) {
  int flag = board[y][x];
  for (int dy = y; dy < y + size; dy++) {
    for (int dx = x; dx < x + size; dx++) {
      if (flag != board[dy][dx]) {
        flag = 2;
      }
      if (flag == 2) {
        std::cout << '(';
        zip(y, x, size / 2);
        zip(y, x + size / 2, size / 2);
        zip(y + size / 2, x, size / 2);
        zip(y + size / 2, x + size / 2, size / 2);
        std::cout << ')';
        return;
      }
    }
  }
  std::cout << flag;
}