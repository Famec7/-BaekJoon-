#include <deque>
#include <iostream>

void turnLeft(std::deque<int> &q);
void turnRight(std::deque<int> &q);

int main() {
  int N, M, num;
  int count = 0;

  std::cin >> N >> M;
  std::deque<int> q;
  for (int i = 0; i < N; i++)
    q.push_back(i + 1);

  int index = 0;
  while (M--) {
    std::cin >> num;
    int size = q.size();
    for (int i = 0; i < size; i++) {
      if (num == q[i]) {
        index = i;
        break;
      }
    }
    if (index <= size / 2)
      for (int i = 0; i < index; i++) {
        turnLeft(q);
        count++;
      }
    else
      for (int i = size; i > index; i--) {
        turnRight(q);
        count++;
      }
    q.pop_front();
  }
  std::cout << count << '\n';

  return 0;
}

void turnLeft(std::deque<int> &q) {
  if (q.empty())
    return;
  int tmp = q.front();
  q.pop_front();
  q.push_back(tmp);
}

void turnRight(std::deque<int> &q) {
  if (q.empty())
    return;
  int tmp = q.back();
  q.pop_back();
  q.push_front(tmp);
}