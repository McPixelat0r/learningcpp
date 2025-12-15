#include <iostream>
class Node {
public:
  Node *left;
  Node *right;
  int value;
  Node(int newValue) {
    left = nullptr;
    right = nullptr;
    value = newValue;
  }
};

class BinarySearchTree {
private:
  Node *root;

public:
  BinarySearchTree(int initialValue) { root = new Node(initialValue); }

  bool searchValue(int value) {
    Node *currentNode = root;
    while (currentNode) {
      if (currentNode->value == value) {
        return true;
      }
      if (value > currentNode->value) {
        currentNode = currentNode->right;
      } else {
        currentNode = currentNode->left;
      }
    }
    return false;
  }

  void addValue(int value) {
    if (!root) {
      root = new Node(value);
      return;
    }
    Node *currentNode = root;
    while (currentNode) {
      if (currentNode->value == value) {
        std::cout << "This value is already present in the tree!";
        return;
      }
      if (value > currentNode->value) {
        if (!currentNode->right) {
          currentNode->right = new Node(value);
          return;
        }
        currentNode = currentNode->right;
      } else {
        if (!currentNode->left) {
          currentNode->left = new Node(value);
          return;
        }
        currentNode = currentNode->left;
      }
    }
  }

  // This has brought me so much pain...
  void deleteValue(int value) {
    if (!root) {
      std::cout << "You cannot remove items from an empty tree!" << "\n";
      return;
    } else if (!(root->left || root->right) && root->value == value) {
      delete root;
      root = nullptr;
      return;
    }
    Node *currentNode = root;
    Node *parentNode = nullptr;
    Node *targetNode;

    while (currentNode) {
      if (currentNode->value == value) {
        targetNode = currentNode;
        break;
      } else if (currentNode->left && value < currentNode->value) {
        parentNode = currentNode;
        currentNode = currentNode->left;
      } else if (currentNode->right && value > currentNode->value) {
        parentNode = currentNode;
        currentNode = currentNode->right;
      } else {
        std::cout << "The value is not in the tree!" << "\n";
        return;
      }
    }
  }
};
