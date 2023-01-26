#include <iostream>
#include <queue>

int main() {
  int T, N, M, tmp;
  int count = 0;

  std::cin >> T;
  while (T--) {
    std::queue<std::pair<int, int>> info;
    std::priority_queue<int> order;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
      std::cin >> tmp;
      info.push({i, tmp});
      order.push(tmp);
    }

    count = 0;
    while (!info.empty()) {
      int index = info.front().first;
      int concern = info.front().second;

      info.pop();
      if (order.top() == concern) {
        order.pop();
        count++;
        if (index == M) {
          std::cout << count << '\n';
          break;
        }
      } else
        info.push({index, concern});
    }
  }

  return 0;
}