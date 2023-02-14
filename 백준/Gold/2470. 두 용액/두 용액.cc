#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;

  std::cin >> N;
  std::vector<int> liquid(N);

  for (auto &liq : liquid)
    std::cin >> liq;
  std::sort(liquid.begin(), liquid.end());

  int min = 2e9;
  int result_l, result_r;
  int left = 0, right = N - 1;
  while (left < right) {
    int sum = liquid[left] + liquid[right];

    if (abs(sum) < min) {
      min = abs(sum);
      result_l = liquid[left];
      result_r = liquid[right];
      if (min == 0)
        break;
    }

    if (sum < 0)
      left++;
    else
      right--;
  }
  std::cout << result_l << ' ' << result_r << '\n';

  return 0;
}