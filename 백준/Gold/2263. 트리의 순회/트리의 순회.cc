#include <iostream>

int n;
int inorder[100000], postorder[100000];

void preorder(int s1, int e1, int s2, int e2);

int main() {
  std::cin >> n;

  for (int i = 0; i < n; i++)
    std::cin >> inorder[i];
  for (int i = 0; i < n; i++)
    std::cin >> postorder[i];

  int root = postorder[n - 1];
  preorder(0, n - 1, 0, n - 1);

  return 0;
}

void preorder(int s1, int e1, int s2, int e2) {
  if (s1 > e1)
    return;
  int root = postorder[e2];

  int root_index;
  for (int i = s1; i <= e1; i++) {
    if (inorder[i] == root) {
      root_index = i;
      break;
    }
  }
  int L = root_index - s1;

  std::cout << root << ' ';
  preorder(s1, root_index - 1, s2, s2 + L - 1);
  preorder(root_index + 1, e1, s2 + L, e2 - 1);
}