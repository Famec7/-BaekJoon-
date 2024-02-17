#include <climits>
#include <iostream>
#include <queue>
#include <string>

constexpr int INF{INT_MAX};

int M, N;
int isWall[100][100];
int count_broken_walls[100][100];
constexpr int dx[4]{-1, 1, 0, 0};
constexpr int dy[4]{0, 0, -1, 1};

typedef struct _Info {
  int x;
  int y;
  int count_broken_wall;
} Info;

struct cmp {
  bool operator()(Info &a, Info &b) {
    return a.count_broken_wall > b.count_broken_wall;
  }
};

void Dijkstra() {
  std::priority_queue<Info, std::vector<Info>, cmp> container;
  container.push({0, 0, 0});
  count_broken_walls[0][0] = 0;

  while (not container.empty()) {
    int cur_x = container.top().x;
    int cur_y = container.top().y;
    int cur_broken_count = container.top().count_broken_wall;
    container.pop();

    if (cur_broken_count > count_broken_walls[cur_y][cur_x])
      continue;

    for (int i = 0; i < 4; i++) {
      int nx = cur_x + dx[i];
      int ny = cur_y + dy[i];

      if (nx < 0 or nx >= M or ny < 0 or ny >= N)
        continue;

      int &next_broken_wall = count_broken_walls[ny][nx];
      if (next_broken_wall >
          count_broken_walls[cur_y][cur_x] + isWall[ny][nx]) {
        next_broken_wall = count_broken_walls[cur_y][cur_x] + isWall[ny][nx];
        container.push({nx, ny, next_broken_wall});
      }
    }
  }
}

void Solve() {
  std::cin >> M >> N;

  std::string line;
  for (int y = 0; y < N; y++) {
    std::cin >> line;
    for (int x = 0; x < M; x++)
      isWall[y][x] = line[x] - '0';
  }
  std::fill(count_broken_walls[0], count_broken_walls[N], INF);

  Dijkstra();

  int &result = count_broken_walls[N - 1][M - 1];
  if (result == INF)
    result = 0;

  std::cout << result << '\n';
}

int main() {
  Solve();

  return 0;
}