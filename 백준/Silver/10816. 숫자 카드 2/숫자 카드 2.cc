#include <algorithm>
#include <iostream>
#include <vector>

int N, M;
int count;
std::vector<int> A(N);

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(NULL);
  std::cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++)
    std::cin >> A[i];

  std::cin >> M;
  int B;
  std::sort(A.begin(), A.end());
  for (int i = 0; i < M; i++) {
    std::cin >> B;
    std::cout << std::upper_bound(A.begin(), A.end(), B) -
                     std::lower_bound(A.begin(), A.end(), B)
              << ' ';
  }
  std::cout << '\n';

  return 0;
}