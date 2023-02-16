#include <iostream>
#include <vector>

int dp[1000001];

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int N;
  std::cin >> N;

  std::vector<int> A(N);
  int max = 0, index = 0;
  for (auto &a : A)
    std::cin >> a;

  std::vector<int> lis;
  lis.push_back(A[0]);
  for (int i = 1; i < N; i++) {
    if (lis.back() < A[i]) {
      lis.push_back(A[i]);
      dp[i] = lis.size() - 1;
    } else {
      int index = std::lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
      lis[index] = A[i];
      dp[i] = index;
    }
  }
  int size = lis.size() - 1;
  std::vector<int> result;
  for (int i = N - 1; i >= 0; i--) {
    if (dp[i] == size) {
      result.push_back(A[i]);
      size--;
    }
  }
  std::cout << result.size() << '\n';
  for (int i = result.size() - 1; i >= 0; i--)
    std::cout << result[i] << ' ';
  std::cout << '\n';

  return 0;
}