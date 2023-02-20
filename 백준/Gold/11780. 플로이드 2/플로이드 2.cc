#include <iostream>
#include <vector>

const int INF = 1e9;
int n, m;
int dist[101][101], route[101][101];
std::vector<int> result;

void floyd_warshall();
void find_route(int start, int end);

int main() {
  std::cin >> n >> m;
  int a, b, c;
  std::fill(&dist[0][0], &dist[100][101], INF);
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    dist[a][b] = std::min(dist[a][b], c);
    route[a][b] = a;
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
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      find_route(i, j);
      std::cout << result.size() << ' ';
      for (int k = result.size() - 1; k >= 0; k--) {
        std::cout << result[k] << ' ';
      }
      std::cout << '\n';
      result.clear();
    }
  }

  return 0;
}

void floyd_warshall() {
  for (int i = 1; i <= n; i++)
    dist[i][i] = 0;

  for (int through = 1; through <= n; through++) {
    for (int from = 1; from <= n; from++) {
      for (int to = 1; to <= n; to++)
        if (dist[from][to] > dist[from][through] + dist[through][to]) {
          dist[from][to] = dist[from][through] + dist[through][to];
          route[from][to] = route[through][to];
        }
    }
  }
}

void find_route(int start, int end) {
  if (dist[start][end] == 0)
    return;

  int through = route[start][end];
  result.push_back(end);
  while (through) {
    result.push_back(through);
    through = route[start][through];
  }
}