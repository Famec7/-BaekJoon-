#include <deque>
#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::deque<int> dq;
  std::string s;
  int N, num;

  std::cin >> N;
  while (N--) {
    std::cin >> s;
    if (s == "push_front") {
      std::cin >> num;
      dq.push_front(num);
    } else if (s == "push_back") {
      std::cin >> num;
      dq.push_back(num);
    } else if (s == "size")
      std::cout << dq.size() << '\n';
    else if (s == "empty")
      std::cout << dq.empty() << '\n';
    else if (s == "pop_front") {
      if (!dq.empty()) {
        std::cout << dq.front() << '\n';
        dq.pop_front();
      } else
        std::cout << "-1" << '\n';
    } else if (s == "pop_back") {
      if (!dq.empty()) {
        std::cout << dq.back() << '\n';
        dq.pop_back();
      } else
        std::cout << "-1" << '\n';
    } else if (s == "front") {
      if (!dq.empty())
        std::cout << dq.front() << '\n';
      else
        std::cout << "-1" << '\n';
    } else if (s == "back") {
      if (!dq.empty())
        std::cout << dq.back() << '\n';
      else
        std::cout << "-1" << '\n';
    }
  }

  return 0;
}