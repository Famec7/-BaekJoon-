#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool cmp(std::string s1, std::string s2) {
  if (s1.length() < s2.length())
    return 1;
  else if(s1.length() > s2.length())
    return 0;
  else return s1 < s2;
}

int main() {
  int N;

  std::cin >> N;
  std::vector<std::string> words(N);
  for (int i = 0; i < N; i++)
    std::cin >> words[i];

  std::sort(words.begin(), words.end(), cmp);
  words.erase(std::unique(words.begin(), words.end()), words.end());
  for (int i = 0; i < words.size(); i++)
    std::cout << words[i] << '\n';

  return 0;
}