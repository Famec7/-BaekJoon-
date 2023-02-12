#include <iostream>
#include <queue>

typedef std::pair<int, int> pair;

int N, K;
bool visited[100001];

void bfs();

int main() {
  std::cin >> N >> K;
  bfs();

  return 0;
}

void bfs() {
  std::priority_queue<pair, std::vector<pair>, std::greater<pair>> pq;

  pq.push({0, N});
  while (!pq.empty()) {
    int X = pq.top().second;
    int time = pq.top().first;
    pq.pop();

    visited[X] = true;
    if (X == K) {
      std::cout << time << '\n';
      return;
    }

    if (X - 1 >= 0 && !visited[X - 1])
      pq.push({time + 1, X - 1});
    if (X + 1 <= 100000 && !visited[X + 1])
      pq.push({time + 1, X + 1});
    if (X * 2 <= 100000 && !visited[X * 2])
      pq.push({time, X * 2});
  }
}