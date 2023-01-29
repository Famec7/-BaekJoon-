#include <iostream>
#include <vector>

typedef std::vector<std::vector<long long>> matrix;

const int MOD = 1000000007;
long long n;

matrix operator*(matrix &a, matrix &b);
matrix power(matrix &base, long long index);

int main() {
  std::cin >> n;

  matrix A = {{1, 1}, {1, 0}};
  matrix result = power(A, n - 1);

  std::cout << (result[1][0] + result[1][1]) % MOD << '\n';

  return 0;
}

matrix operator*(matrix &a, matrix &b) {
  matrix result(2, std::vector<long long>(2));

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
      result[i][j] %= MOD;
    }
  }

  return result;
}

matrix power(matrix &base, long long index) {
  matrix result = {{1, 0}, {0, 1}};

  while (index) {
    if (index % 2 == 1)
      result = result * base;
    base = base * base;
    index /= 2;
  }

  return result;
}