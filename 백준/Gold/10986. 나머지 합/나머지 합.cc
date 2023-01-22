#include <iostream>
#include <vector>

int main() {
  int N, M;
  long long sum = 0, count = 0;

  std::cin >> N >> M;
  std::vector<long long> A(N);
  std::vector<long long> mod(M, 0);
  for (auto &num : A) {
    std::cin >> num;
    sum += num;
    mod[sum % M]++;
  }
  for (int i = 0; i < M; i++)
    count += mod[i] * (mod[i] - 1) / 2;

  std::cout << mod[0] + count << '\n';

  return 0;
}