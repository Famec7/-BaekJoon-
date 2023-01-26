#include <iostream>
#include <vector>

int main() {
  long long result = 0, min;
  int N, index = 0;

  std::cin >> N;
  std::vector<long long> road(N - 1), city(N);
  for (auto &r : road)
    std::cin >> r;
  for (auto &c : city)
    std::cin >> c;

  min = city[0];
  for (int i = 1; i < N - 1; i++) {
    if (city[i] < min) {
      min = city[i];
      index = i;
    }
  }
  for (int i = 0; i < index; i++)
    result += road[i] * city[i];
  for (int i = index; i < N - 1; i++)
    result += min * road[i];

  std::cout << result << '\n';

  return 0;
}