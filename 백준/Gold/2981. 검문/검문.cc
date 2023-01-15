#include <algorithm>
#include <iostream>
#include <vector>

int GCD(int a, int b);

int main() {
  int N;
  int num[100];

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> num[i];
  }

  std::sort(num, num + N);
  int gcd = num[1] - num[0];
  for (int i = 1; i < N - 1; i++) {
    gcd = GCD(gcd, num[i + 1] - num[i]);
  }

  std::vector<int> result;
  for (int i = 2; i * i <= gcd; i++) {
    if (gcd % i == 0) {
      result.push_back(i);
      result.push_back(gcd / i);
    }
  }
  result.push_back(gcd);
  result.erase(std::unique(result.begin(), result.end()), result.end());
  std::sort(result.begin(), result.end());
  for (const auto &factor : result)
    std::cout << factor << ' ';
  std::cout << '\n';

  return 0;
}

int GCD(int a, int b) {
  if (b == 0)
    return a;
  return GCD(b, a % b);
}