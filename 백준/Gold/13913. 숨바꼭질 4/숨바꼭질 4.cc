#include <iostream>
#include <queue>
#include <vector>

int N, K;
int dist[100001], pos[100001];

int main() {
  std::cin >> N >> K;
  std::fill(dist, dist + 100001, -1);

  std::queue<int> q;
  q.push(N);
  dist[N] = 0;
  pos[N] = N;
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    if (current == K)
      break;
    for (int next : {current - 1, current + 1, current * 2}) {
      if (next < 0 || next > 100000 || dist[next] != -1)
        continue;
      dist[next] = dist[current] + 1;
      pos[next] = current;
      q.push(next);
    }
  }
  std::cout << dist[K] << '\n';

  std::vector<int> result;
  while (1) {
    result.push_back(K);
    if (K == N)
      break;
    K = pos[K];
  }
  for (int i = result.size() - 1; i >= 0; i--)
    std::cout << result[i] << ' ';
  std::cout << '\n';

  return 0;
}