#include <iostream>

class Node {
public:
  int data;
  Node *next;

  Node(int newData) {
    data = newData;
    next = nullptr; // 'nullptr' means "this points to nothing"
  }
};

class Queue {
private:
  Node *head;
  Node *lastElement;
  int size;

  void insertIntoEmptyQueue(int item) {
    head = new Node(item);
    lastElement = head;
    size = 1;
  }

public:
  Queue() {
    head = nullptr;
    lastElement = nullptr;
    size = 0;
  }
  Queue(int value) { insertIntoEmptyQueue(value); }
  ~Queue() {
    int popped = 1;
    while (head != nullptr) {
      popItem(popped);
    }
  }

  void addItem(int item) {
    if (!size) {
      insertIntoEmptyQueue(item);
      return;
    }
    lastElement->next = new Node(item);
    lastElement = lastElement->next;
    size++;
  }

  bool popItem(int &poppedItem) {
    if (!size) {
      std::cout << "The queue is already empty!";
      return false;
    }

    else {
      poppedItem = head->data;
      Node *oldHead = head;
      head = head->next;
      delete oldHead;
      oldHead = nullptr;
      if (head == nullptr) {
        lastElement = nullptr;
      }
      size--;
      return true;
    }
  }
};
