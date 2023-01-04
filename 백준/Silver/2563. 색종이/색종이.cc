#include <iostream>

int main() {
  int arr[101][101] = {
      0,
  };
  int num;
  int result = 0;

  std::cin >> num;

  int x, y;
  while (num--) {
    std::cin >> x >> y;
    result += 100;
    for (int i = y; i < y + 10; i++) {
      for (int j = x; j < x + 10; j++) {
        arr[i][j]++;
      }
    }
  }

  int over = 0;
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      if (arr[i][j] > 1)
        over += arr[i][j] - 1;
    }
  }

  result -= over;
  std::cout << result << '\n';

  return 0;
}