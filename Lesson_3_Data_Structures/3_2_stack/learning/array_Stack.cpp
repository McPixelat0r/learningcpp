#include <iostream>

class Stack {
private:
  int *stack;
  int size;
  int highestIndex;

public:
  Stack(int initialSize) {
    if (initialSize == 0) {
      std::cout << "Stack cannot have a size of 0!";
      return;
    }
    size = initialSize;
    stack = new int[size];
    highestIndex = -1;
  }
  ~Stack() { delete[] stack; }

  void resizeStack() {
    int newSize = size + size / 2;
    int *newStack = new int[newSize];
    for (int i = 0; i <= highestIndex; i++) {
      newStack[i] = stack[i];
    }
    delete[] stack;
    stack = newStack;
    size = newSize;
  }

  void addItem(int item) {
    if (highestIndex + 1 == size) {
      resizeStack();
    }
    highestIndex++;
    stack[highestIndex] = item;
  }

  int popItem() {
    if (size == 0 || highestIndex == -1) {
      std::cout << "You cannot remove items from an empty stack!";
      return -1;
    }
    int topItem = stack[highestIndex];
    highestIndex--;
    return topItem;
  }
};
