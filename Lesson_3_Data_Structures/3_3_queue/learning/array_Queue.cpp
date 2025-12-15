#include <iostream>
class Queue {
private:
  int *queue;
  int size;
  int front_index;
  int back_index;
  int element_count;

public:
  Queue(int firstSize) {
    size = firstSize;
    front_index = 0;
    back_index = 0;
    queue = new int[size];
    element_count = 0;
  }
  ~Queue() { delete[] queue; }

  void resizeQueue() {
    int newSize = size + size / 2;
    int *newQueue = new int[newSize];
    for (int i = 0; i < size; i++) {
      newQueue[i] = queue[(front_index + i) % size];
    }
    delete[] queue;
    size = newSize;
    queue = newQueue;
    front_index = 0;
    back_index = element_count;
  }

  void addItem(int newItem) {
    if (element_count == size) {
      resizeQueue();
    }
    queue[back_index] = newItem;
    back_index = (back_index + 1) % size;
    element_count++;
  }

  int popItem() {
    if (element_count == 0) {
      std::cout << "You cannot remove items from an empty queue!";
      return -1;
    }
    int frontItem = queue[front_index];
    front_index = (front_index + 1) % size;
    element_count--;
    return frontItem;
  }
  // This is an alternate, more appropriate way of dealing with functions that
  // need to return a value but need error handling
  bool dequeue(int &frontItem) {
    if (element_count == 0) {
      std::cout << "You cannot remove items from an empty queue!";
      return false;
    }
    frontItem = queue[front_index];
    front_index = (front_index + 1) % size;
    element_count--;
    return true;
  }
};
