#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> xy[3000];
std::vector<int> tree[3000];
int parent[3000], group_number, group_size;
bool visited[3000];

int ccw(std::pair<int, int> &a, std::pair<int, int> &b, std::pair<int, int> &c);
bool find_intersection(std::pair<int, int> &a, std::pair<int, int> &b,
                       std::pair<int, int> &c, std::pair<int, int> &d);
int find(int node);
bool merge(int a, int b);

int main() {
  int N;
  std::cin >> N;
  for (int i = 0; i < N; i++)
    parent[i] = i;

  int x1, y1, x2, y2;
  for (int i = 0; i < N; i++) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    xy[i].push_back({x1, y1});
    xy[i].push_back({x2, y2});
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      bool checked = find_intersection(xy[i][0], xy[i][1], xy[j][0], xy[j][1]);
      if (checked == true)
        merge(i, j);
    }
  }

  std::vector<int> size(N, 0);
  for (int i = 0; i < N; i++)
    size[find(i)]++;

  for (int i = 0; i < N; i++) {
    if (size[i])
      group_number++;
    group_size = std::max(group_size, size[i]);
  }

  std::cout << group_number << '\n';
  std::cout << group_size << '\n';

  return 0;
}

int ccw(std::pair<int, int> &a, std::pair<int, int> &b,
        std::pair<int, int> &c) {
  int result = (b.first - a.first) * (c.second - a.second) -
               (c.first - a.first) * (b.second - a.second);
  if (result < 0)
    return -1;
  else if (result > 0)
    return 1;
  else
    return 0;
}

bool find_intersection(std::pair<int, int> &a, std::pair<int, int> &b,
                       std::pair<int, int> &c, std::pair<int, int> &d) {
  int ans1 = ccw(a, b, c) * ccw(a, b, d);
  int ans2 = ccw(c, d, a) * ccw(c, d, b);

  if (ans1 == 0 && ans2 == 0) {
    if (a > b)
      std::swap(a, b);
    if (c > d)
      std::swap(c, d);
    if (a <= d && b >= c)
      return true;
  } else if (ans1 <= 0 && ans2 <= 0)
    return true;

  return false;
}

int find(int node) {
  if (node == parent[node])
    return node;

  return parent[node] = find(parent[node]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b)
    return false;
  parent[b] = a;
  tree[a].push_back(b);
  tree[b].push_back(a);
  return true;
}