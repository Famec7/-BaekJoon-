#include <iostream>
#include <vector>

int N;
std::vector<std::pair<int, int>> size;
std::vector<int> rank;

void ranking(int index);

int main() {
  std::cin >> N;
  size.resize(N);
  rank.resize(N, 0);

  for (auto &ref : size)
    std::cin >> ref.first >> ref.second;
  ranking(0);
  for (const auto &ref : rank)
    std::cout << ref + 1 << ' ';
  std::cout << '\n';

  return 0;
}

void ranking(int index) {
  if (index > N)
    return;
  for (int next = index + 1; next < N; next++) {
    if (size[index].first > size[next].first &&
        size[index].second > size[next].second)
      rank[next]++;
    else if (size[index].first < size[next].first &&
             size[index].second < size[next].second)
      rank[index]++;
  }
  ranking(index + 1);
}