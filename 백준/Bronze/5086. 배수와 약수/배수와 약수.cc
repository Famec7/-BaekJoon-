#include <iostream>

int main() {
  int A, B;

  while (1) {
    std::cin >> A >> B;
    if (A == 0 && B == 0)
      break;
    if (B % A == 0)
      std::cout << "factor" << '\n';
    else if (A % B == 0)
      std::cout << "multiple" << '\n';
    else
      std::cout << "neither" << '\n';
  }

  return 0;
}