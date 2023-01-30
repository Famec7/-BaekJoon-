#include <algorithm>
#include <iostream>
#include <vector>

int N, M;
std::vector<int> A(N);
int binary_search(int target);

int main() {
  std::cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++)
    std::cin >> A[i];

  std::cin >> M;
  std::vector<int> B(M);
  for (int i = 0; i < M; i++)
    std::cin >> B[i];

  std::sort(A.begin(), A.end());
  for (int i = 0; i < M; i++)
    std::cout << binary_search(B[i]) << '\n';

  return 0;
}

int binary_search(int target) {
  int first = 0;
  int last = N - 1;

  while (first <= last) {
    int mid = (first + last) / 2;

    if (A[mid] == target)
      return 1;
    else if (A[mid] < target)
      first = mid + 1;
    else
      last = mid - 1;
  }

  return 0;
}