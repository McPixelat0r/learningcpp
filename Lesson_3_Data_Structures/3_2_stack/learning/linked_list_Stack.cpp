#include <iostream>
class Node {
public:
  int value;
  Node *lower;
  Node(int newData) {
    value = newData;
    lower = nullptr;
  }
};
class Stack {
private:
  Node *top;
  int size;

public:
  Stack(int value) {
    top = new Node(value);
    size = 1;
  }
  ~Stack() {
    while (top != nullptr) {
      popItem();
    }
  }

  void addItem(int value) {
    Node *newTop = new Node(value);
    newTop->lower = top;
    top = newTop;
    size++;
  }

  int popItem() {
    if (size == 0) {
      std::cout << "The stack is already empty!";
      return -1;
    }
    int poppedItem = top->value;
    if (top->lower != nullptr) {
      Node *tempPointer = &(*top);
      poppedItem = top->value;
      top = top->lower;
      delete tempPointer;
    } else {
      delete top;
      top = nullptr;
    }
    size--;
    return poppedItem;
  }
};
