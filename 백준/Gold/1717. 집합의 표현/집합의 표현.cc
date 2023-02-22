#include <iostream>

int parent[1000001];

int find(int num);
void merge(int a, int b);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i <= n; i++)
    parent[i] = i;

  int operation, a, b;
  for (int i = 0; i < m; i++) {
    std::cin >> operation >> a >> b;
    if (operation == 0)
      merge(a, b);
    else {
      if (find(a) == find(b))
        std::cout << "YES\n";
      else
        std::cout << "NO\n";
    }
  }

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