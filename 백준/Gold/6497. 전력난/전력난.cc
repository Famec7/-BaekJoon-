#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

std::vector<std::tuple<int, int, int>> tree;
int parent[200000];

int find(int num);
bool merge(int a, int b);

int main() {
  int m, n;
  int x, y, z;

  while (1) {
    std::cin >> m >> n;
    if (m == 0 && n == 0)
      break;
    for (int i = 0; i < m; i++)
      parent[i] = i;
    int result = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> x >> y >> z;
      tree.push_back({z, x, y});
      result += z;
    }
    std::sort(tree.begin(), tree.end());
    for (int i = 0; i < n; i++) {
      if (merge(std::get<1>(tree[i]), std::get<2>(tree[i])))
        result -= std::get<0>(tree[i]);
    }
    std::cout << result << '\n';
    tree.clear();
  }

  return 0;
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