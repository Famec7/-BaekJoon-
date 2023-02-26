#include <cmath>
#include <iostream>
#include <vector>

int N;
double result;
std::vector<std::pair<long long, long long>> polygon;

long long outer_product(long long x1, long long y1, long long x2, long long y2);

int main() {
  std::cin >> N;

  long long x, y;
  for (int i = 0; i < N; i++) {
    std::cin >> x >> y;
    polygon.push_back({x, y});
  }
  for (int i = 1; i < N - 1; i++) {
    long long x1 = polygon[i].first - polygon[0].first;
    long long y1 = polygon[i].second - polygon[0].second;
    long long x2 = polygon[i + 1].first - polygon[0].first;
    long long y2 = polygon[i + 1].second - polygon[0].second;
    result += (double)(outer_product(x1, y1, x2, y2) / 2.0);
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << fabs(result) << '\n';

  return 0;
}

long long outer_product(long long x1, long long y1, long long x2,
                        long long y2) {
  return x1 * y2 - x2 * y1;
}