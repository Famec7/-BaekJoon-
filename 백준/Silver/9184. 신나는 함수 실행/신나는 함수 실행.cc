#include <iostream>

int cache[21][21][21];
int w(int a, int b, int c);

int main() {
  int a, b, c;

  std::fill(&cache[0][0][0], &cache[20][20][21], -1);
  while (1) {
    std::cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1)
      break;
    std::cout << "w(" << a << ", " << b << ", " << c << ") = ";
    std::cout << w(a, b, c) << '\n';
  }

  return 0;
}

int w(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  else if (a > 20 || b > 20 || c > 20)
    return w(20, 20, 20);

  int &ret = cache[a][b][c];
  if (ret != -1)
    return ret;

  if (a < b && b < c)
    return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  else
    return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
                 w(a - 1, b - 1, c - 1);
}