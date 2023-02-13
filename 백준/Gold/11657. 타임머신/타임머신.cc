#include <iostream>
#include <vector>

const int INF = 1e9;
int N, M;
long long dist[501];
std::vector<std::pair<int, int>> bus[501];

bool bellman_ford();

int main() {
  std::cin >> N >> M;

  int A, B, C;
  for (int i = 0; i < M; i++) {
    std::cin >> A >> B >> C;
    bus[A].push_back({B, C});
  }
  bool isCycle = bellman_ford();
  if (isCycle)
    std::cout << "-1\n";
  else {
    for (int i = 2; i <= N; i++) {
      if (dist[i] != INF)
        std::cout << dist[i] << '\n';
      else
        std::cout << "-1\n";
    }
  }

  return 0;
}

bool bellman_ford() {
  std::fill(dist, dist + 501, INF);
  dist[1] = 0;

  bool cycle = false;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 0; k < bus[j].size(); k++) {
        int next = bus[j][k].first;
        int distance = bus[j][k].second;

        if (dist[j] != INF && dist[next] > dist[j] + distance) {
          dist[next] = dist[j] + distance;
          if (i == N)
            cycle = true;
        }
      }
    }
  }

  return cycle;
}