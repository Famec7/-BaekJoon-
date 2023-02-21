#include <iostream>
#include <utility>

int N;
std::pair<char, char> tree[27];

void preorder_traversal(char node);
void inorder_traversal(char node);
void postorder_traversal(char node);

int main() {
  std::cin >> N;
  char parent, left, right;
  for (int i = 0; i < N; i++) {
    std::cin >> parent >> left >> right;
    tree[parent - 'A'] = {left, right};
  }
  preorder_traversal('A');
  std::cout << '\n';
  inorder_traversal('A');
  std::cout << '\n';
  postorder_traversal('A');
  std::cout << '\n';

  return 0;
}

void preorder_traversal(char node) {
  if (node == '.')
    return;
  std::cout << node;
  preorder_traversal(tree[node - 'A'].first);
  preorder_traversal(tree[node - 'A'].second);
}

void inorder_traversal(char node) {
  if (node == '.')
    return;
  inorder_traversal(tree[node - 'A'].first);
  std::cout << node;
  inorder_traversal(tree[node - 'A'].second);
}

void postorder_traversal(char node) {
  if (node == '.')
    return;
  postorder_traversal(tree[node - 'A'].first);
  postorder_traversal(tree[node - 'A'].second);
  std::cout << node;
}