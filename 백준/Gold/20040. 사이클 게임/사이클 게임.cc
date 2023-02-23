#include <iostream>

int parent[500001];

int find(int num);
bool merge(int a, int b);

int main() {
  int n, m, a, b;

  std::cin >> n >> m;
  for (int i = 1; i <= n; i++)
    parent[i] = i;
  int result = 0;
  for (int i = 1; i <= m; i++) {
    std::cin >> a >> b;
    if (merge(a, b)) {
      result = i;
      break;
    }
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
    return true;
  parent[b] = a;
  return false;
}