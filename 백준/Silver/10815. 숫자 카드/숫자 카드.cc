#include <iostream>
#include <set>
#include <vector>

int main() {
  int N, M;
  std::cin >> N;

  std::set<int> cards;
  int tmp;
  for (int i = 0; i < N; i++) {
    std::cin >> tmp;
    cards.insert(tmp);
  }
  std::cin >> M;
  std::vector<int> num(M);
  for (int i = 0; i < M; i++)
    std::cin >> num[i];

  for (int i = 0; i < M; i++) {
    std::cout << cards.count(num[i]) << ' ';
  }
  std::cout << '\n';

  return 0;
}