#include <iostream>

int sudoku[9][9];

void print();
bool check(int x, int y, int num);
void solve(int x, int y);

int main() {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      std::cin >> sudoku[i][j];

  solve(0, 0);

  return 0;
}

void print() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++)
      std::cout << sudoku[i][j] << ' ';
    std::cout << '\n';
  }
}

bool check(int x, int y, int num) {
  int start_x = (x / 3) * 3;
  int start_y = (y / 3) * 3;
  for (int i = start_y; i < start_y + 3; i++) {
    for (int j = start_x; j < start_x + 3; j++) {
      if (sudoku[i][j] == num)
        return false;
    }
  }
  for (int i = 0; i < 9; i++)
    if (num == sudoku[y][i] || num == sudoku[i][x])
      return false;

  return true;
}

void solve(int y, int x) {
  if (y == 9) {
    print();
    exit(0);
  }
  if (x == 9)
    solve(y + 1, 0);
  if (sudoku[y][x] == 0) {
    for (int i = 1; i <= 9; i++) {
      if (check(x, y, i)) {
        sudoku[y][x] = i;
        solve(y, x + 1);
        sudoku[y][x] = 0;
      }
    }
  }
  else
    solve(y, x + 1);
}