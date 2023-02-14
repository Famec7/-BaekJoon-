#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N, S;

  std::cin >> N >> S;
  std::vector<int> seq(N);
  for (auto &s : seq)
    std::cin >> s;

  int result = N + 1;
  int start = 0, end = 0, sum = 0;
  while (start <= end) {
    if (sum >= S) {
      result = std::min(result, end - start);
      sum -= seq[start++];
    } else if (end == N)
      break;
    else
      sum += seq[end++];
  }
  if (result == N + 1)
    result = 0;
  std::cout << result << '\n';

  return 0;
}