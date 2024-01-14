#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int path(int ja1, int ja2) {
  int mo = ja1 + ja2;
  long long ret = 1;
  int j = 1;
  for (int i = ja1 + 1; i <= mo; i++) {
    ret *= i;
    while (j <= ja2 && (ret % j == 0)) {
      ret /= j++;
    }
  }
  ret = ret == 0 ? 1 : ret;
  return ret;
}
int main() {
  cin >> n >> m >> k;
  k = k == 0 ? 0 : k - 1;
  int x1 = k / m, y1 = k % m;
  int x2 = n - 1 - x1, y2 = m - 1 - y1;
  cout << path(x1, y1) * path(x2, y2);

  return 0;
}