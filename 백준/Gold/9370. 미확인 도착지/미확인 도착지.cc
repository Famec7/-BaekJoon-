#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> pair;

const int INF = 987654321;
std::vector<std::pair<int, int>> road[2001];
int dist[2001];

void bfs(int start);
int detour(int s, int g, int h, int x);

int main() {
  std::ios_base::sync_with_stdio(0);
	std::cin.tie();
  int T;
  int s, g, h;
  int a, b, d;
  int n, m, t;

  std::cin >> T;
  while (T--) {
    std::vector<int> result;
    std::cin >> n >> m >> t;
    std::cin >> s >> g >> h;
    for (int i = 0; i < m; i++) {
      std::cin >> a >> b >> d;
      road[a].push_back({b, d});
      road[b].push_back({a, d});
    }
    int x;
    for (int i = 0; i < t; i++) {
      std::cin >> x;

      bfs(s);
      int origin = dist[x];
      int ret = detour(s, g, h, x);
      if (ret == origin)
        result.push_back(x);
    }
    std::sort(result.begin(), result.end());
    for (const auto &ret : result)
      std::cout << ret << ' ';
    std::cout << '\n';

    for (int i = 1; i <= n; i++)
      road[i].clear();
  }

  return 0;
}

void bfs(int start) {
  std::fill(dist, dist + 2001, INF);
  std::priority_queue<pair, std::vector<pair>, std::greater<pair>> pq;

  pq.push({0, start});
  dist[start] = 0;
  while (!pq.empty()) {
    int current = pq.top().second;
    int distance = pq.top().first;
    pq.pop();

    for (int i = 0; i < road[current].size(); i++) {
      int next = road[current][i].first;
      int nDist = road[current][i].second;

      if (dist[next] > nDist + distance) {
        dist[next] = nDist + distance;
        pq.push({nDist + distance, next});
      }
    }
  }
}

int detour(int s, int g, int h, int x) {
  int result;

  bfs(s);
  int sTog = dist[g];
  int sToh = dist[h];

  if (sTog < sToh) {
    bfs(h);
    result = sTog + dist[g] + dist[x];
  } else {
    bfs(g);
    result = sToh + dist[h] + dist[x];
  }

  return result;
}