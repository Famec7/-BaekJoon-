#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

std::vector<std::tuple<int, int, int>> tree;
int parent[10001];

int find(int num);
bool merge(int a, int b);

int main() {
  int V, E;
  int A, B, C;
  std::cin >> V >> E;
  for (int i = 0; i < V; i++)
    parent[i] = i;
  for (int i = 0; i < E; i++) {
    std::cin >> A >> B >> C;
    tree.push_back({C, A, B});
  }
  std::sort(tree.begin(), tree.end());
  int result = 0;
  for (int i = 0; i < E; i++) {
    if (merge(std::get<1>(tree[i]), std::get<2>(tree[i])))
      result += std::get<0>(tree[i]);
  }
  std::cout << result << '\n';

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