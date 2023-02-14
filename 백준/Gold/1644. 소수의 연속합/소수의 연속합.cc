#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> prime;

void isPrime(int n);

int main() {
  int N;

  std::cin >> N;
  isPrime(N);

  int start = 0, end = 0;
  int sum = 0, count = 0;
  while (start <= end) {
    if (sum >= N)
      sum -= prime[start++];
    else if (end == prime.size())
      break;
    else
      sum += prime[end++];
    if (sum == N)
      count++;
  }
  std::cout << count << '\n';

  return 0;
}

void isPrime(int n) {
  std::vector<bool> check(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (check[i]) {
      for (int j = i + i; j <= n; j += i)
        check[j] = false;
    }
  }

  for (int i = 2; i <= n; i++) {
    if (check[i])
      prime.push_back(i);
  }
}