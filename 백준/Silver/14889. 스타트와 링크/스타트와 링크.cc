#include <iostream>

int N, min = 987654321;
int S[20][20];
bool checked[20] = {
    false,
};

void teaming(int index, int start);

int main() {
  std::cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      std::cin >> S[i][j];

  teaming(0, 0);
  std::cout << min << '\n';

  return 0;
}

void teaming(int index, int start) {
  if (index == N / 2) {
    int start = 0, link = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (checked[i] && checked[j])
          start += S[i][j];
        else if (!checked[i] && !checked[j])
          link += S[i][j];
      }
    }
    min = std::min(min, abs(start - link));
    return;
  }

  for (int i = start; i < N; i++) {
    checked[i] = true;
    teaming(index + 1, i + 1);
    checked[i] = false;
  }
}