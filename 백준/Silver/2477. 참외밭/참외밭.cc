#include <iostream>
#include <vector>

int main() {
  int K, max = 0;
  std::vector<std::pair<int, int>> sides(6);

  std::cin >> K; 
  for (auto &side : sides)
    std::cin >> side.first >> side.second;

  int area = 0;
  int result;
  for (int i = 0; i < 6; i++) {
    area = sides[i].second * sides[(i + 1) % 6].second;
    if(area > max) {
      max = area;
      result = area - sides[(i + 3) % 6].second * sides[(i + 4) % 6].second;
    }
  }
  std::cout << result * K << '\n';

  return 0;
}