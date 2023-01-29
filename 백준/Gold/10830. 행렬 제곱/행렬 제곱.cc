#include <iostream>

int N;
long long B;
long long A[5][5], result[5][5];

void multiply(long long a[][5], long long b[][5]);
void power(long long base[][5], long long exponent);

int main() {
  std::cin >> N >> B;

  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      std::cin >> A[row][col];
    }
    result[row][row] = 1;
  }

  power(A, B);
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      std::cout << result[row][col] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}

void multiply(long long a[][5], long long b[][5]) {
  long long tmp[5][5] = {
      0,
  };
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        tmp[i][j] += a[i][k] * b[k][j];
      }
      tmp[i][j] %= 1000;
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      a[i][j] = tmp[i][j];
}

void power(long long base[][5], long long exponent) {
  while (exponent) {
    if (exponent % 2 == 1)
      multiply(result, base);
    multiply(base, base);
    exponent /= 2;
  }
}