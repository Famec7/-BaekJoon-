#include <deque>
#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int T, n;
  std::string operations, array;

  std::cin >> T;
  while (T--) {
    std::cin >> operations >> n >> array;
    std::deque<int> dq;
    std::string tmp = "";
    for (int i = 0; i < array.length(); i++) {
      if (isdigit(array[i]))
        tmp += array[i];
      else {
        if (tmp.empty())
          continue;
        dq.push_back(stoi(tmp));
        tmp = "";
      }
    }

    int reverse = 0;
    bool IsEmpty = false;
    for (const auto operation : operations) {
      if (operation == 'R')
        reverse++;
      else {
        if (dq.empty()) {
          std::cout << "error" << '\n';
          IsEmpty = true;
          break;
        }
        if (reverse % 2 == 0)
          dq.pop_front();
        else
          dq.pop_back();
        n--;
      }
    }
    if (IsEmpty)
      continue;
    std::cout << '[';
    if (reverse % 2 == 0) {
      for (int i = 0; i < n - 1; i++) {
        std::cout << dq.front() << ',';
        dq.pop_front();
      }
      if (!dq.empty())
        std::cout << dq.front();
    } else {
      for (int i = 0; i < n - 1; i++) {
        std::cout << dq.back() << ',';
        dq.pop_back();
      }
      if (!dq.empty())
        std::cout << dq.back();
    }
    std::cout << "]\n";
  }

  return 0;
}