#include <iostream>
#include <queue>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  int N, x;
  std::priority_queue<int> pq;

  std::cin >> N;
  while (N--) {
    std::cin >> x;
    if (x == 0) {
      if (pq.empty())
        std::cout << '0' << '\n';
      else {
        std::cout << pq.top() << '\n';
        pq.pop();
      }
    } else
      pq.push(x);
  }

  return 0;
}