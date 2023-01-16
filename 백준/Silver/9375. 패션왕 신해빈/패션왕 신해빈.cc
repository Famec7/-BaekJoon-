#include <iostream>
#include <map>
#include <string>

int main() {
  int T, n, count = 0;
  std::string clothes, kind[30];
  std::map<std::string, int> kinds;

  std::cin >> T;
  while (T--) {
    count = 1;
    std::cin >> n;
    kinds.clear();
    for (int i = 0; i < n; i++) {
      std::cin >> clothes >> kind[i];
      kinds[kind[i]]++;
    }
    for (auto &clothe : kinds)
      count *= (clothe.second + 1);

    std::cout << count - 1 << '\n';
  }

  return 0;
}