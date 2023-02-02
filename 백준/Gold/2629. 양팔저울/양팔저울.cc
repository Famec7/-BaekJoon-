#include <iostream>

int count_weight, count_marble;
int W[30], M;
bool cache[31][15001];

void solve(int index, int weight);

int main() {
  std::cin >> count_weight;
  for (int i = 0; i < count_weight; i++)
    std::cin >> W[i];
  solve(0, 0);

  std::cin >> count_marble;
  for (int i = 0; i < count_marble; i++) {
    std::cin >> M;
    if (M > 15000)
      std::cout << 'N' << ' ';
    else if (cache[count_weight][M])
      std::cout << 'Y' << ' ';
    else
      std::cout << 'N' << ' ';
  }
  std::cout << '\n';

  return 0;
}

void solve(int index, int weight) {
  if (index > count_weight)
    return;

  bool &ret = cache[index][weight];
  if (ret)
    return;

  ret = true;
  solve(index + 1, weight + W[index]);
  solve(index + 1, abs(weight - W[index]));
  solve(index + 1, weight);
}