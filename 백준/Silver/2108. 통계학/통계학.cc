#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  int N, count[8001] = {0};
  int max = 0, index;
  int mode = 0;
  double average = 0;

  std::cin >> N;
  std::vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    std::cin >> vec[i];
    average += vec[i];
    if (vec[i] <= 0)
      index = -vec[i];
    else
      index = vec[i] + 4000;
    count[index]++;
    if (count[index] > max)
      max = count[index];
  }
  average /= N;
  average = round(average);
  if (average == -0)
    average = 0;

  std::sort(vec.begin(), vec.end());
  bool flag = false;
  for (int i = -4000; i < 4001; i++) {
    if (i <= 0)
      index = -i;
    else
      index = i + 4000;
    if (count[index] == max) {
      mode = i;

      if (flag)
        break;

      flag = true;
    }
  }

  std::cout << average << '\n' << vec[N / 2] << '\n';
  std::cout << mode << '\n' << vec[N - 1] - vec[0] << '\n';

  return 0;
}