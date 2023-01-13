#include <iostream>
#include <string>

int title(int N);

int main() {
  int N;

  std::cin >> N;
  int result = title(N);
  std::cout << result << '\n';

  return 0;
}

int title(int N) {
  int result = 665;
  std::string s;
  for (int i = 1; i <= N; i++) {
    for (int j = result + 1;; j++) {
      s = std::to_string(j);
      if (s.find("666") != std::string::npos) {
        result = j;
        break;
      }
    }
  }
  return result;
}