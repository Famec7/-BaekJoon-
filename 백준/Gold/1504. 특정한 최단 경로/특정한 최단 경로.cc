#include <iostream>
#include <queue>
#include <vector>

const int INF = 987654321;
int N, E;
int v1, v2;
int dist[801];
std::vector<std::pair<int, int>> graph[801];

void route(int start);

int main() {
  std::cin >> N >> E;
  int a, b, c;
  for (int i = 0; i < E; i++) {
    std::cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  std::cin >> v1 >> v2;

  route(1);
  int toV1 = dist[v1];
  int toV2 = dist[v2];

  route(v1);
  int V1toV2 = dist[v2];
  int V1toN = dist[N];

  route(v2);
  int V2toN = dist[N];

  int result = INF;
  result = std::min(result, toV2 + V1toV2 + V1toN);
  result = std::min(result, toV1 + V1toV2 + V2toN);
  if (result == INF || V1toV2 == INF)
    result = -1;
  std::cout << result << '\n';

  return 0;
}

void route(int start) {
  std::fill(dist, dist + 801, INF);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;
  pq.push({0, start});
  dist[start] = 0;

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