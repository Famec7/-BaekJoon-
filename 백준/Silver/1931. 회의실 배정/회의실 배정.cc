#include <algorithm>
#include <iostream>

int main() {
  int N, count = 0;
  std::pair<int, int> time[100000];

  std::cin >> N;
  for (int i = 0; i < N; i++)
    std::cin >> time[i].second >> time[i].first;

  std::sort(time, time + N);

  int min = 0;
  for (int i = 0; i < N; i++) {
    int start = time[i].second, end = time[i].first;
    if(min <= start) {
      min = end;
      count++;
    }
  }
  std::cout << count << '\n';

  return 0;
}