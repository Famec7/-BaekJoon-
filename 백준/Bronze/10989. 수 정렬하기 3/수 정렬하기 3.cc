#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int N, num;
  int count[10001] = {
      0,
  };

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> num;
    count[num]++;
  }

  for (int i = 0; i < 10001; i++) {
    for (int j = 0; j < count[i]; j++) {
      std::cout << i << '\n';
    }
  }

  return 0;
}