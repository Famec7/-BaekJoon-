#include <iostream>

int N, M, seq[8];
void sequence(int length, int start);

int main() {
  std::cin >> N >> M;

  sequence(0, 1);

  return 0;
}

void sequence(int length, int start) {
  if (length == M) {
    for (int i = 0; i < length; i++)
      std::cout << seq[i] << ' ';
    std::cout << '\n';

    return;
  }

  for (int i = 1; i <= N; i++) {
    if (start > i)
      continue;
    seq[length] = i;
    sequence(length + 1, i);
  }
}