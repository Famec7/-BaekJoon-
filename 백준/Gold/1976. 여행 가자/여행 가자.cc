#include <iostream>

int parent[201];

int find(int num);
void merge(int a, int b);

int main() {
  int N, M;

  std::cin >> N >> M;
  for (int i = 1; i <= N; i++)
    parent[i] = i;
  int info;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> info;
      if (info == 1)
        merge(i, j);
    }
  }

  int route;
  std::cin >> route;
  for (int i = 1; i < M; i++) {
    int root = find(route);
    std::cin >> route;
    if (find(route) != root) {
      std::cout << "NO\n";
      return 0;
    }
  }
  std::cout << "YES\n";

  return 0;
}

int find(int num) {
  if (parent[num] == num)
    return num;
  return parent[num] = find(parent[num]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b)
    return;
  parent[b] = a;
}