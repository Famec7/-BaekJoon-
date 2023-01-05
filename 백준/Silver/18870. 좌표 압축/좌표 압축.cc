#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;

  std::cin >> N;
  std::vector<int> coordinate(N);
  for (int i = 0; i < N; i++)
    std::cin >> coordinate[i];

  std::vector<int> result = coordinate;
  std::sort(coordinate.begin(), coordinate.end());
  coordinate.erase(std::unique(coordinate.begin(), coordinate.end()),
                   coordinate.end());

  for (int i = 0; i < N; i++) {
    auto it = std::lower_bound(coordinate.begin(), coordinate.end(), result[i]);
    std::cout << it - coordinate.begin() << ' ';
  }
  std::cout << '\n';

  return 0;
}