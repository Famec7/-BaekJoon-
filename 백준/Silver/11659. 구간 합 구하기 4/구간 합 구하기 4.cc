#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int N, M;

  std::cin >> N >> M;
  std::vector<int> num(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    std::cin >> num[i];
    num[i] += num[i - 1];
  }

  int start, end;
  while (M--) {
    std::cin >> start >> end;
    std::cout << num[end] - num[start - 1] << '\n';
  }

  return 0;
}