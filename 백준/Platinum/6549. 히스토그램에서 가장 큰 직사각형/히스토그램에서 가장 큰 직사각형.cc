#include <iostream>
#include <vector>

long long solve(int left, int right);
std::vector<long long> h;

int main() {
  int n;

  while (1) {
    std::cin >> n;
    if (n == 0)
      break;
    h.clear();
    h.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> h[i];
    long long result = solve(0, n - 1);
    std::cout << result << '\n';
  }

  return 0;
}

long long solve(int left, int right) {
  if (left == right)
    return h[left];
  int mid = (left + right) / 2; 

  long long result = std::max(solve(left, mid), solve(mid + 1, right));

  int low = mid, high = mid + 1;
  long long height = std::min(h[low], h[high]);

  result = std::max(result, height * 2);

  while (left < low || high < right) {
    if (high < right && (low == left || h[low - 1] < h[high + 1])) {
      high++;
      height = std::min(height, h[high]);
    } else {
      low--;
      height = std::min(height, h[low]);
    }

    result = std::max(result, height * (high - low + 1));
  }

  return result;
}