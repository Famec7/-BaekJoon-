#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> order = {0, 1, 2, 3, 4, 5, 6, 7};
int a[8], result;

bool check(int a, int b, int c);
bool solve();

int main() {
  for (int i = 0; i < 8; i++)
    std::cin >> a[i];

  do {
    if (solve())
      result++;
  } while (std::next_permutation(order.begin(), order.end()));

  std::cout << result << '\n';

  return 0;
}

bool check(int a, int b, int c) {
  double oa = (double)a;
  double ob = (double)b * sqrt(2.0) / 2.0;
  double oc = (double)c;

  if (-oc / oa * ob + oc > ob)
    return true;
  return false;
}

bool solve() {
  for (int i = 0; i < 8; i++) {
    if (check(a[order[i]], a[order[(i + 1) % 8]], a[order[(i + 2) % 8]]))
      return false;
  }

  return true;
}