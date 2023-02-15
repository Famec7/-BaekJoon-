#include <algorithm>
#include <iostream>
#include <vector>

int N;
long long C;
std::vector<long long> A, B, weight;

void knapsack(int start, int end, std::vector<long long> &pack, long long sum);

int main() {
  std::cin >> N >> C;
  weight.resize(N);
  for (int i = 0; i < N; i++)
    std::cin >> weight[i];

  knapsack(0, N / 2, A, 0);
  knapsack(N / 2 + 1, N - 1, B, 0);
  std::sort(B.begin(), B.end());

  long long result = 0;
  for (int i = 0; i < A.size(); i++)
    result += std::upper_bound(B.begin(), B.end(), C - A[i]) - B.begin();

  std::cout << result << '\n';

  return 0;
}

void knapsack(int start, int end, std::vector<long long> &pack, long long sum) {
  if (start > end) {
    pack.push_back(sum);
    return;
  }

  knapsack(start + 1, end, pack, sum);
  knapsack(start + 1, end, pack, sum + weight[start]);
}