#include <algorithm>
#include <iostream>

int P[1000];

int main() {
  int N;

  std::cin >> N;
  for (int i = 0; i < N; i++)
    std::cin >> P[i];
  std::sort(P, P + N);

  int sum = P[0];
  for (int i = 0; i < N - 1; i++) {
    P[i + 1] += P[i];
    sum += P[i + 1];
  }
  std::cout << sum << '\n';

  return 0;
}