#include <iostream>
#include <queue>

struct cmp {
  bool operator()(int data1, int data2) {
    if (abs(data1) == abs(data2))
      return data1 > data2;
    return abs(data1) > abs(data2);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  int N, x;
  std::priority_queue<int, std::vector<int>, cmp> pq;

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