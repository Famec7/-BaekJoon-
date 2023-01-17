#include <iostream>

int N, count = 0;
int col[15];

bool check(int column);
void queen(int column);

int main() {
  std::cin >> N;

  queen(0);
  std::cout << count << '\n';

  return 0;
}

bool check(int column) {
  for (int i = 0; i < column; i++) {
    if (col[i] == col[column] || abs(col[column] - col[i]) == column - i)
      return false;
  }
  return true;
}

void queen(int column) {
  if (column == N)
    count++;
  for (int i = 0; i < N; i++) {
    col[column] = i;
    if (check(column))
      queen(column + 1);
  }
}