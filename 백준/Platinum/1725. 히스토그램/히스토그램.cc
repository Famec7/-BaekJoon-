#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::stack<int> s;
  int N;
  int result = 0;

  std::cin >> N;
  std::vector<int> h(N);
  for (auto &height : h)
    std::cin >> height;

  h.push_back(0);
  for (int i = 0; i < N + 1; i++) {
    while (!s.empty() && h[s.top()] >= h[i]) {
      int height = h[s.top()];
      s.pop();
      int width = i;
      if (!s.empty())
        width = i - s.top() - 1;
      result = std::max(result, height * width);
    }
    s.push(i);
  }
  std::cout << result << '\n';

  return 0;
}