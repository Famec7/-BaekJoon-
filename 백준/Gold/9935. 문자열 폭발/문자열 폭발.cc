#include <iostream>
#include <string>

int main() {
  std::string s, explosion;
  std::string result = "";

  std::cin >> s >> explosion;

  int explo_length = explosion.length();
  for (int i = 0; i < s.length(); i++) {
    result += s[i];
    if (result.length() >= explo_length) {
      int count = 0;
      for (int j = 0; j < explo_length; j++) {
        if (result[result.length() - explo_length + j] == explosion[j])
          count++;
      }
      if (explo_length == count)
        result.erase(result.end() - explo_length, result.end());
    }
  }
  if (result.empty())
    std::cout << "FRULA" << '\n';
  else
    std::cout << result << '\n';

  return 0;
}