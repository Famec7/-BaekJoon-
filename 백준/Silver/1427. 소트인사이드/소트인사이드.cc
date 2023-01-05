#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string N;

  std::cin >> N;
  std::sort(N.begin(), N.end(), std::greater<char>());
  std::cout << N;

  return 0;
}