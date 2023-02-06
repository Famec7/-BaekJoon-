#include <iostream>
#include <stack>
#include <vector>

int F[1000001];

int main() {
  std::stack<int> s;
  int N;

  std::cin >> N;
  std::vector<int> vec(N), result(N, -1);
  for (auto &num : vec) {
    std::cin >> num;
    F[num]++;
  }

  for (int i = 0; i < N; i++) {
    while (!s.empty() && F[vec[s.top()]] < F[vec[i]]) {
      result[s.top()] = vec[i];
      s.pop();
    }
    s.push(i);
  }
  for (const auto &ret : result)
    std::cout << ret << ' ';
  std::cout << '\n';

  return 0;
}