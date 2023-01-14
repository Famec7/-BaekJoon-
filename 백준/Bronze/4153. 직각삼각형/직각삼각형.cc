#include <iostream>
#include <algorithm>

int main() {
  int a, b, c;

  while (1) {
    std::cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0)
      break;
    if(a > b)
      std::swap(a, b);
    if(b > c)
      std::swap(b, c);
    if(c*c == a*a + b*b)
      std::cout << "right" << '\n';
    else
      std::cout << "wrong" << '\n';
  }

  return 0;
}