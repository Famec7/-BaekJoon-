#include <iostream>

int N, M, seq[8];
void sequence(int length);

int main() {
  std::cin >> N >> M;

  sequence(0);

  return 0;
}

void sequence(int length) {
  if (length == M) {
    for (int i = 0; i < length; i++)
      std::cout << seq[i] << ' ';
    std::cout << '\n';

    return;
  }

  for (int i = 1; i <= N; i++) {
    seq[length] = i;
    sequence(length + 1);
  }
}