#include <iostream>
#include <algorithm>

int main() {
  int num;
  int factor[50];

  std::cin >> num;
  for (int i = 0; i < num; i++) {
    std::cin >> factor[i];
  }
  std::sort(factor, factor + num);
  if (num % 2 == 0)
    std::cout << factor[0] * factor[num - 1] << '\n';
  else
    std::cout << factor[num / 2] * factor[num / 2] << '\n';

  return 0;
}