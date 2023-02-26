#include <iostream>
#include <vector>
#include <cmath>

int N;
std::vector<std::pair<double, double>> polygon;

double outer_product(double x1, double y1, double x2, double y2);

int main() {
  std::cin >> N;

  double x, y;
  for (int i = 0; i < N; i++) {
    std::cin >> x >> y;
    polygon.push_back({x, y});
  }
  double result = 0;
  for (int i = 1; i < N - 1; i++) {
    double x1 = polygon[i].first - polygon[0].first;
    double y1 = polygon[i].second - polygon[0].second;
    double x2 = polygon[i + 1].first - polygon[0].first;
    double y2 = polygon[i + 1].second - polygon[0].second;
    result += outer_product(x1, y1, x2, y2) / 2.0;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << fabs(result) << '\n';

  return 0;
}

double outer_product(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}