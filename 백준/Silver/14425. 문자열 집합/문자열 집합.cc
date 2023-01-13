#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  int N, M;
  std::cin >> N >> M;

  std::set<std::string> cards;
  std::vector<std::string> num(M);
  std::string tmp;
  for (int i = 0; i < N; i++) {
    std::cin >> tmp;
    cards.insert(tmp);
  }
  for (int i = 0; i < M; i++)
    std::cin >> num[i];

  int count = 0;
  for (int i = 0; i < M; i++) {
    count += cards.count(num[i]);
  }
  std::cout << count << '\n';

  return 0;
}