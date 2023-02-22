#include <iostream>
#include <map>
#include <string>

int parent[200001], count[200001];

int find(int num);
int merge(int a, int b);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, F;

  std::cin >> T;
  while (T--) {
    std::cin >> F;
    std::map<std::string, int> m;
    for (int i = 1; i <= F * 2; i++) {
      parent[i] = i;
      count[i] = 1;
    }
    std::string f1, f2;
    int index = 1;
    for (int i = 0; i < F; i++) {
      std::cin >> f1 >> f2;
      if (m.count(f1) == 0)
        m.insert({f1, index++});
      if (m.count(f2) == 0)
        m.insert({f2, index++});
      std::cout << merge(m[f1], m[f2]) << '\n';
    }
  }

  return 0;
}

int find(int num) {
  if (parent[num] == num)
    return num;
  return parent[num] = find(parent[num]);
}

int merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b)
    return count[a];
  parent[b] = a;
  return count[a] += count[b];
}