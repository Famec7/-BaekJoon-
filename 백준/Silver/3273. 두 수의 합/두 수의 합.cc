#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, x;

  std::cin >> n;
  std::vector<int> a(n);
  for (auto &num : a)
    std::cin >> num;
  std::cin >> x;

  std::sort(a.begin(), a.end());
  int left = 0, right = n - 1;
  int sum = 0, count = 0;
  while (left < right) {
    sum = a[left] + a[right];
    if (sum == x) {
      left++;
      right--;
      count++;
    } else if (sum > x)
      right--;
    else
      left++;
  }
  std::cout << count << '\n';

  return 0;
}