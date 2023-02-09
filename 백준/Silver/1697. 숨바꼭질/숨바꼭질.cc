#include <iostream>
#include <queue>

int N, K;
bool visited[100001];

void bfs(int start);

int main() {
  std::cin >> N >> K;
  visited[N] = true;
  bfs(N);

  return 0;
}

void bfs(int start) {
  std::queue<std::pair<int, int>> q;

  q.push({start, 0});
  while (!q.empty()) {
    int X = q.front().first;
    int count = q.front().second;

    q.pop();

    if (X == K) {
      std::cout << count << '\n';
      return;
    }
    if (X - 1 >= 0 && !visited[X - 1]) {
      visited[X - 1] = true;
      q.push({X - 1, count + 1});
    }
    if (X + 1 <= 100000 && !visited[X + 1]) {
      visited[X + 1] = true;
      q.push({X + 1, count + 1});
    }
    if (X * 2 <= 100000 && !visited[X * 2]) {
      visited[X * 2] = true;
      q.push({X * 2, count + 1});
    }
  }
}