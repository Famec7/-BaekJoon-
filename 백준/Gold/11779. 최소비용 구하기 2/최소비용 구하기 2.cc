#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> pair;

const int INF = 2e9;
int n, m, dist[1001], route[1001];
std::vector<pair> bus[1001];

void dijkstra(int start, int end);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> n >> m;

  std::fill(dist, dist + 1001, INF);
  int start, end, cost;
  for (int i = 0; i < m; i++) {
    std::cin >> start >> end >> cost;
    bus[start].push_back({end, cost});
  }
  std::cin >> start >> end;
  dijkstra(start, end);
  std::cout << dist[end] << '\n';

  std::vector<int> cities;
  while (1) {
    cities.push_back(end);
    if (cities.back() == start)
      break;
    end = route[end];
  }

  std::cout << cities.size() << '\n';
  for (int i = cities.size() - 1; i >= 0; i--)
    std::cout << cities[i] << ' ';
  std::cout << '\n';

  return 0;
}

void dijkstra(int start, int end) {
  std::priority_queue<pair, std::vector<pair>, std::greater<pair>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int cost = pq.top().first;
    int current = pq.top().second;
    pq.pop();
    if (current == end)
      break;

    for (int i = 0; i < bus[current].size(); i++) {
      int next = bus[current][i].first;
      int nCost = bus[current][i].second;

      if (dist[next] > cost + nCost) {
        dist[next] = cost + nCost;
        route[next] = current;
        pq.push({dist[next], next});
      }
    }
  }
}