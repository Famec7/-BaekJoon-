#include <iostream>
#include <vector>

int N, M, max = 0;
std::vector<int> cards;
void BlackJack(int sum, int card, int count);

int main() {
  std::cin >> N >> M;
  cards.resize(N);
  for (auto &card : cards)
    std::cin >> card;

  BlackJack(0, 0, 0);
  std::cout << max << '\n';

  return 0;
}

void BlackJack(int sum, int card, int count) {
  if (count == 3 && sum <= M) {
    max = std::max(max, sum);
    return;
  }
  if (sum > M || count > 3 || card >= N)
    return;
  BlackJack(sum + cards[card], card + 1, count + 1);
  BlackJack(sum, card + 1, count);
}