#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool cmp(std::pair<int, std::string> p1, std::pair<int, std::string> p2) {
  return p1.first < p2.first;
}

int main() {
  int N;

  std::cin >> N;
  std::vector<std::pair<int, std::string>> members(N);

  for (int i = 0; i < N; i++)
    std::cin >> members[i].first >> members[i].second;

  std::stable_sort(members.begin(), members.end(), cmp);

  for (int i = 0; i < N; i++)
    std::cout << members[i].first << ' ' << members[i].second << '\n';

  return 0;
}