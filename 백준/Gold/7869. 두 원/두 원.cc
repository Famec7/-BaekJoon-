    #include <cmath>
#include <iostream>

double pi = std::acos(-1);

double distance(double &x1, double &y1, double &x2, double &y2);

int main() {
  double x1, y1, r1, x2, y2, r2;

  std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  double dist = distance(x1, y1, x2, y2);

  double result = 0;
  if (dist >= r1 + r2)
    result = 0;
  else if (abs(r1 - r2) >= dist) {
    if (r1 < r2)
      result = r1 * r1 * pi;
    else
      result = r2 * r2 * pi;
  } else {
    double theta1 =
        std::acos((r1 * r1 + dist * dist - r2 * r2) / (2 * r1 * dist)) * 2;
    double theta2 =
        std::acos((r2 * r2 + dist * dist - r1 * r1) / (2 * r2 * dist)) * 2;

    double S1 = r1 * r1 * theta1 / 2 - r1 * r1 * std::sin(theta1) / 2;
    double S2 = r2 * r2 * theta2 / 2 - r2 * r2 * std::sin(theta2) / 2;

    result = S1 + S2;
  }
  std::cout << std::fixed;
  std::cout.precision(3);
  std::cout << result << '\n';

  return 0;
}

double distance(double &x1, double &y1, double &x2, double &y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}