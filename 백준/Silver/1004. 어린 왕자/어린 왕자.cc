#include <cmath>
#include <iostream>

int main() {
  int T, N;
  int x1, x2, y1, y2, r1, r2;
  int x[50], y[50], r[50];
  int count = 0;

  std::cin >> T;
  while (T--) {
    count = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
      std::cin >> x[i] >> y[i] >> r[i];
      r1 = (x[i] - x1) * (x[i] - x1) + (y[i] - y1) * (y[i] - y1);
      r2 = (x[i] - x2) * (x[i] - x2) + (y[i] - y2) * (y[i] - y2);
      if (r1 < r[i] * r[i] && r2 < r[i] * r[i])
        continue;
      if (r1 < r[i] * r[i] || r2 < r[i] * r[i])
        count++;
    }
    std::cout << count << '\n';
  }

  return 0;
}