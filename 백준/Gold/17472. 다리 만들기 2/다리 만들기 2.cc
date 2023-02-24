#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

std::vector<std::tuple<int, int, int>> tree;
int N, M;
int island_index, island[7][4];
int parent[7], map[10][10];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
bool visited[10][10];

void dfs(int x, int y);
void distance(int start, int start_x, int start_y);
int find(int num);
bool merge(int a, int b);

int main() {
  for (int i = 1; i <= 6; i++)
    parent[i] = i;

  std::cin >> N >> M;
  for (int y = 0; y < N; y++)
    for (int x = 0; x < M; x++)
      std::cin >> map[y][x];

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (map[y][x] != 0) {
        if (!visited[y][x])
          island_index++;
        dfs(x, y);
      }
    }
  }
  for (int y = 0; y < N; y++)
    for (int x = 0; x < M; x++)
      if (map[y][x] != 0)
        distance(map[y][x], x, y);
  std::sort(tree.begin(), tree.end());

  int result = 0;
  for (int i = 0; i < tree.size(); i++) {
    int dist = std::get<0>(tree[i]);
    int island_1 = std::get<1>(tree[i]);
    int island_2 = std::get<2>(tree[i]);
    if (dist < 2)
      continue;
    if (merge(island_1, island_2))
      result += dist;
  }

  int root = find(1);
  for (int i = 1; i <= island_index; i++) {
    if (find(i) != root) {
      std::cout << "-1\n";
      return 0;
    }
  }

  std::cout << result << '\n';

  return 0;
}

void distance(int start, int start_x, int start_y) {
  for (int i = 0; i < 4; i++) {
    int x = start_x;
    int y = start_y;
    int dist = 0;
    while (1) {
      x += dx[i];
      y += dy[i];
      if (x < 0 || x >= M || y < 0 || y >= N || map[y][x] == start)
        break;
      if (map[y][x] != 0) {
        tree.push_back({dist, start, map[y][x]});
        break;
      }
      dist++;
    }
  }
}

void dfs(int x, int y) {
  bool &ret = visited[y][x];
  if (ret)
    return;
  ret = true;
  map[y][x] = island_index;

  island[island_index][0] = std::min(island[island_index][0], x);
  island[island_index][1] = std::max(island[island_index][1], x);
  island[island_index][2] = std::min(island[island_index][2], y);
  island[island_index][3] = std::max(island[island_index][3], y);

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (nx < 0 || nx >= M || ny < 0 || ny >= N)
      continue;
    if (map[ny][nx] != 0 && !visited[ny][nx])
      dfs(nx, ny);
  }
}

int find(int num) {
  if (parent[num] == num)
    return num;
  return parent[num] = find(parent[num]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b)
    return false;
  parent[b] = a;
  return true;
}