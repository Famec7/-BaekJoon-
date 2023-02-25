#include <iostream>
#include <vector>

int N, R, Q;
std::vector<int> tree[100001];
int size[100001];

int countSubtree(int node);

int main() {
  std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
  std::fill(size, size + 100001, -1);
  std::cin >> N >> R >> Q;

  int U, V;
  for (int i = 0; i < N - 1; i++) {
    std::cin >> U >> V;
    tree[U].push_back(V);
    tree[V].push_back(U);
  }
  size[R] = countSubtree(R);

  for (int i = 0; i < Q; i++) {
    std::cin >> U;
    std::cout << size[U] << '\n';
  }

  return 0;
}

int countSubtree(int node) {
  int &ret = size[node];
  if (ret != -1)
    return ret;

  ret = 1;
  for (auto &next : tree[node]) {
    if (size[next] != -1)
      continue;
    ret += countSubtree(next);
  }

  return ret;
}