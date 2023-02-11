#include <iostream>
#include <queue>
#include <vector>

const int INF = 987654321;
int V, E, K;
int dist[20001];
std::vector<std::pair<int, int>> graph[20001];

void route();

int main() {
  std::fill(dist, dist + 20001, INF);
  std::cin >> V >> E >> K;
  int u, v, w;
  for (int i = 0; i < E; i++) {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  route();
  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      std::cout << "INF\n";
    else
      std::cout << dist[i] << '\n';
  }

  return 0;
}

void route() {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;
  pq.push({0, K});
  dist[K] = 0;

  while (!pq.empty()) {
    int distance = pq.top().first;
    int current = pq.top().second;
    pq.pop();

    for (int i = 0; i < graph[current].size(); i++) {
      int next = graph[current][i].first;
      int nDist = graph[current][i].second;

      if (dist[next] > nDist + distance) {
        dist[next] = nDist + distance;
        pq.push({nDist + distance, next});
      }
    }
  }
}