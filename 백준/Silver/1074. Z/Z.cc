#include <cmath>
#include <iostream>

int r;
int c;

int z_search(int n, int row, int col) {
  if (n == 0)
    return 0;

  int half_size = pow(2, n - 1);

  if (row < half_size && col < half_size)
    return z_search(n - 1, row, col);
  else if (row < half_size && col >= half_size)
    return half_size * half_size + z_search(n - 1, row, col - half_size);
  else if (row >= half_size && col < half_size)
    return 2 * half_size * half_size + z_search(n - 1, row - half_size, col);
  else
    return 3 * half_size * half_size +
           z_search(n - 1, row - half_size, col - half_size);
}

int main() {
  int N = 0;

  std::cin >> N >> r >> c;

  int result = z_search(N, r, c);
  std::cout << result << '\n';

  return 0;
}