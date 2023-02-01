#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<int> A;
std::vector<int> result;

void lis();

int main() {
  std::cin >> N;
  A.resize(N);

  for (auto &a : A)
    std::cin >> a;
  lis();
  std::cout << result.size() << '\n';

  return 0;
}

void lis() {
  result.push_back(A[0]);
  for (int i = 1; i < N; i++) {
    if (result.back() < A[i])
      result.push_back(A[i]);
    else {
      int index =
          std::lower_bound(result.begin(), result.end(), A[i]) - result.begin();
      result[index] = A[i];
    }
  }
}