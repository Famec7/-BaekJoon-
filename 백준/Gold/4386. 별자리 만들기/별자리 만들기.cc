#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

std::vector<std::tuple< double, int, int>> tree;
double parent[101];
double star_y[101], star_x[101];

int find(int num);
bool merge(int a, int b);

int main() {
  int N;
  std::cin >> N;
  for (int i = 1; i <= N; i++)
    parent[i] = i;
  for (int i = 0; i < N; i++)
    std::cin >> star_x[i] >> star_y[i];
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      double dist =
          sqrt(pow(star_x[i] - star_x[j], 2) + pow(star_y[i] - star_y[j], 2));
      tree.push_back({dist, i + 1, j + 1});
    }
  }
  std::sort(tree.begin(), tree.end());
  double result = 0;
  for (int i = 0; i < tree.size(); i++) {
    if (merge(std::get<1>(tree[i]), std::get<2>(tree[i])))
      result += std::get<0>(tree[i]);
  }
  std::cout << std::fixed;
  std::cout.precision(2);
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