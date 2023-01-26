#include <iostream>
#include <string>

int main() {
  int result = 0;
  std::string s, tmp;

  std::cin >> s;

  bool minus = false;
  for (int i = 0; i <= s.length(); i++) {
    if (s[i] == '+' || s[i] == '-' || i == s.length()) {
      if (minus)
        result -= std::stoi(tmp);
      else
        result += std::stoi(tmp);

      if (s[i] == '-')
        minus = true;
      tmp = "";
    } else
      tmp += s[i];
  }

  std::cout << result << '\n';

  return 0;
}