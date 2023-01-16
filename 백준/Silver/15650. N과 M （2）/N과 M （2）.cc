#include <iostream>

int N, M, seq[8];
bool visited[9] = {
    false,
};
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

  for (int i = start; i <= N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      seq[length] = i;
      sequence(length + 1, i + 1);
      visited[i] = false;
    }
  }
}