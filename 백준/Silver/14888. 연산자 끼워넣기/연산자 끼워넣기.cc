#include <iostream>

int N, min = 1000000001, max = -1000000001;
int num[11];
int operations[4];

void solution(int result, int index);

int main() {
  std::cin >> N;

  for (int i = 0; i < N; i++)
    std::cin >> num[i];
  for (int i = 0; i < 4; i++)
    std::cin >> operations[i];

  solution(num[0], 1);
  std::cout << max << '\n';
  std::cout << min << '\n';

  return 0;
}

void solution(int result, int index) {
  if (index == N) {
    max = std::max(max, result);
    min = std::min(min, result);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (operations[i] > 0) {
      operations[i]--;
      if (i == 0)
        solution(result + num[index], index + 1);
      else if (i == 1)
        solution(result - num[index], index + 1);
      else if (i == 2)
        solution(result * num[index], index + 1);
      else
        solution(result / num[index], index + 1);
      operations[i]++;
    }
  }

  return;
}