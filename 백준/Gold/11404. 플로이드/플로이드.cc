#include <iostream>

const int INF = 1e9;
int n, m;
int dist[101][101];

void floyd_warshall();

int main() {
  std::cin >> n >> m;

  int a, b, c;
  std::fill(&dist[0][0], &dist[100][101], INF);
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    dist[a][b] = std::min(dist[a][b], c);
  }

  floyd_warshall();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] == INF)
        dist[i][j] = 0;
      std::cout << dist[i][j] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}

void floyd_warshall() {
  for (int i = 1; i <= n; i++)
    dist[i][i] = 0;

  for (int i = 1; i <= n; i++) {
    for (int from = 1; from <= n; from++) {
      for (int to = 1; to <= n; to++)
        dist[from][to] = std::min(dist[from][to], dist[from][i] + dist[i][to]);
    }
  }
}