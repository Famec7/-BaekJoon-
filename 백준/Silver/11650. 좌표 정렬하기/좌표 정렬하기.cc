#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;

  std::cin >> N;
  std::vector<std::pair<int, int>> coordinate(N);
  for (int i = 0; i < N; i++)
    std::cin >> coordinate[i].first >> coordinate[i].second;

  std::sort(coordinate.begin(), coordinate.end());
  for (int i = 0; i < N; i++)
    std::cout << coordinate[i].first << ' ' << coordinate[i].second << '\n';

  return 0;
}