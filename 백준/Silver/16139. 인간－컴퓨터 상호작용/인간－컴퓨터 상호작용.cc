#include <iostream>
#include <string>
#include <vector>

std::vector<int> pSum[26];

int main() {
  std::string S;
  char alphabet;
  int q, l, r;

  std::cin >> S >> q;

  for (int i = 0; i < S.length(); i++) {
    for (int j = 0; j < 26; j++) {
      int ascii = S[i] - 'a';
      if (i == 0)
        if (ascii == j)
          pSum[j].push_back(1);
        else
          pSum[j].push_back(0);
      else {
        if (ascii == j)
          pSum[j].push_back(pSum[j][i - 1] + 1);
        else
          pSum[j].push_back(pSum[j][i - 1]);
      }
    }
  }

  while (q--) {
    std::cin >> alphabet >> l >> r;
    int index = alphabet - 'a';
    if (l == 0)
      std::cout << pSum[index][r] << '\n';
    else
      std::cout << pSum[index][r] - pSum[index][l - 1] << '\n';
  }

  return 0;
}