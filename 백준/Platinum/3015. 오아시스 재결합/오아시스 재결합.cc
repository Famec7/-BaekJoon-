#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::stack<std::pair<int, int>> s;
  int N;
  long long result = 0;

  std::cin >> N;
  std::vector<int> height(N);
  for (auto &h : height)
    std::cin >> h;

  for (auto &h : height) {
    int sec_count = 1;
    while (!s.empty() && s.top().first < h) {
      result += s.top().second;
      s.pop();
    }
    if (!s.empty()) {
      if (s.top().first == h) {
        result += s.top().second;
        sec_count = s.top().second + 1;
        if (s.size() > 1)
          result++;
        s.pop();
      } else
        result++;
    }
    s.push(std::make_pair(h, sec_count));
  }
  std::cout << result << '\n';

  return 0;
}