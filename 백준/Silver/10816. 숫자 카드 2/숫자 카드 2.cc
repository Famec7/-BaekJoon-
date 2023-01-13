#include <iostream>
#include <map>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(NULL);
  int N, M;
  std::cin >> N;

  std::map<int, int> cards;
  int tmp;
  for (int i = 0; i < N; i++) {
    std::cin >> tmp;
    cards[tmp]++;
  }
  std::cin >> M;
  std::vector<int> num(M);
  for (int i = 0; i < M; i++)
    std::cin >> num[i];

  for (int i = 0; i < M; i++)
    std::cout << cards[num[i]] << ' ';
  std::cout << '\n';

  return 0;
}