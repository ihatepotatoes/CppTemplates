#include <iostream>

struct Node {
  int value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int i = 0) : value(i) {}
};

auto left = &Node::left;
auto right = &Node::right;

template <typename T, typename... TP>
Node* traverse(T np, TP... paths) {
  return (np ->* ... ->* paths); // np ->* paths1 ->* paths2 ...
}

int main() {
  Node* root = new Node{0};
  root->left = new Node{1};
  root->left->right = new Node{2};

  Node* node = traverse(root, left, right);
  std::cout << node->value << std::endl;
}
