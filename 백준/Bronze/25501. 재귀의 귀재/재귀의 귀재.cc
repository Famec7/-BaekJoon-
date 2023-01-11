#include <cstring>
#include <iostream>
#include <string>

int count = 0;
int recursion(const char *s, int l, int r);
int isPalindrome(const char *s);

int main() {
  int T;
  std::string s;

  std::cin >> T;
  while (T--) {
    std::cin >> s;
    count = 0;
    int result = isPalindrome(s.c_str());
    std::cout << result << ' ' << count << '\n';
  }

  return 0;
}

int recursion(const char *s, int l, int r) {
  count++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) { return recursion(s, 0, strlen(s) - 1); }