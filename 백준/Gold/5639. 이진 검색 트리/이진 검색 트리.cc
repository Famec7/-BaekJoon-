#include <iostream>

int tree[1000000];
void postorder(int start, int end);

int main() {
  int num, index = 0;
  while (std::cin >> num)
    tree[index++] = num;
  postorder(0, index);

  return 0;
}

void postorder(int start, int end) {
  if (start >= end)
    return;

  int index = start;
  while (index < end) {
    if (tree[start] < tree[index])
      break;
    index++;
  }
  postorder(start + 1, index);
  postorder(index, end);
  std::cout << tree[start] << '\n';
}