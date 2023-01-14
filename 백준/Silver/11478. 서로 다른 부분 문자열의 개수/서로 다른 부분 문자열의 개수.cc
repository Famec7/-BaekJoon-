#include <iostream>
#include <set>
#include <string>

int main() {
  std::ios_base ::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::string s, tmp;
  std::set<std::string> result;

  std::cin >> s;
  for (int i = 0; i < s.size(); i++) {
    tmp.clear();
    for (int j = i; j < s.size(); j++) {
      tmp += s[j];
      result.insert(tmp);
    }
  }
  std::cout << result.size() << '\n';

  return 0;
}