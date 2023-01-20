#include <iostream>

int N, A[1000];
int cache[1001];

int lis(int start);

int main() {
  std::cin >> N;

  std::fill(cache, cache + 1001, -1);
  for (int i = 0; i < N; i++)
    std::cin >> A[i];

  std::cout << lis(-1) - 1<< '\n';

  return 0;
}

int lis(int start) {
  int &ret = cache[start + 1];
  if (ret != -1)
    return ret;

  ret = 1;
  for (int next = start + 1; next < N; next++) {
    if (start == -1 || A[start] < A[next])
      ret = std::max(ret, lis(next) + 1);
  }
  return ret;
}