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

  ~BinarySearchTree() { // TODO
  }

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
    // Cases:
    // Case 1: Target node has 0 children (it's a leaf node)
    // Case 2: Target node has 1 child on the right
    // Case 3: Target node has 1 child on the left
    // Case 4: Target node has 2 children

    if (!(currentNode->left || currentNode->right)) {
      // Check if the target node was on the left or right of parent node
      if (parentNode->left && parentNode->left == targetNode) {
        delete parentNode->left;
        parentNode->left = nullptr;
      } else if (parentNode->right && parentNode->right == targetNode) {
        delete parentNode->right;
        parentNode->right = nullptr;
      }
      return;
    }
    if (!(targetNode->left) != !(targetNode->right)) {

      if (targetNode->right) {
        // secondSearchParent = currentNode;
        // currentNode = currentNode->right;
        if (parentNode->left == targetNode) {
          parentNode->left = targetNode->right;
        } else if (parentNode->right == targetNode) {
          parentNode->right = targetNode->right;
        }
      } else {
        if (parentNode->left == targetNode) {
          parentNode->left = targetNode->left;
        } else if (parentNode->right == targetNode) {
          parentNode->right = targetNode->left;
        }
      }
      delete targetNode;
      targetNode = nullptr;
      return;
    }
    Node *secondSearchParent = targetNode;
    currentNode = secondSearchParent->right;
    while (currentNode->left) {
      secondSearchParent = currentNode;
      currentNode = currentNode->left;
    }
    if (parentNode->left == targetNode) {
      parentNode->left->value = currentNode->value;
    } else if (parentNode->right == targetNode) {
      parentNode->right->value = currentNode->value;
    }
    // targetNode->value = currentNode->value;
    if (targetNode == secondSearchParent) {
      delete secondSearchParent->right;
      secondSearchParent->right = nullptr;
    } else {
      // targetNode->right = currentNode;
      if (currentNode->right) {
        secondSearchParent->left = currentNode->right;
      }
      delete currentNode;
      currentNode = nullptr;
    }
    return;
  }
};
