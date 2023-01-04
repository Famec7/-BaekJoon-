#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;

  std::cin >> N;
  std::vector<int> vec(N);
  for (int i = 0; i < N; i++)
    std::cin >> vec[i];

  std::sort(vec.begin(), vec.end());

  for (int i = 0; i < N; i++)
    std::cout << vec[i] << '\n';

  return 0;
}