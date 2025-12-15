#include <iostream>
class Node {
public:
  int value;
  Node *next;
  Node(int newData) {
    value = newData;
    next = nullptr;
  }
};
class LinkedList {
private:
  Node *head;
  int size;

public:
  LinkedList(int newValue) {
    head = new Node(newValue);
    size = 1;
  }
  void appendValue(int newValue) {
    Node *currentNode = head;
    while (currentNode->next != nullptr) {
      currentNode = currentNode->next;
    }
    currentNode->next = new Node(newValue);
    size++;
  }
  void popValue() {
    Node *currentNode = head;
    if (head == nullptr) {
      std::cout << "Linked List is already empty!";
      return;
    } else if (head->next == nullptr) {
      delete head;
      head = nullptr;
    } else {
      while (currentNode->next->next != nullptr) {
        currentNode = currentNode->next;
      }
      delete currentNode->next;
      currentNode->next = nullptr;
    }
    size--;
  }
  void insertValue(int newValue, int insertionIndex) {
    if (insertionIndex > size) {
      std::cout << "Index out of range!";
      return;
    }
    if (size == 0) {
      head = new Node(newValue);
      size++;
      return;
    }
    if (insertionIndex == 0) {
      Node *newNode = new Node(newValue);
      newNode->next = head;
      head = newNode;
      size++;
      return;
    }
    Node *currentNode = head;
    Node *previousNode;
    for (int i = 0; i < insertionIndex; i++) {
      previousNode = currentNode;
      currentNode = currentNode->next;
    }
    Node *newNode = new Node(newValue);
    newNode->next = currentNode;
    previousNode->next = newNode;
    size++;
  }
  void removeValue(int deletionIndex) {
    if (deletionIndex > size) {
      std::cout << "Index out of range!";
      return;
    }
    if (deletionIndex == 0) {
      Node *oldHead = head;
      head = head->next;
      delete oldHead;
      oldHead = nullptr;
      size--;
      return;
    }
    Node *currentNode = head;
    Node *previousNode;
    for (int i = 0; i < deletionIndex; i++) {
      previousNode = currentNode;
      currentNode = currentNode->next;
    }
    previousNode->next = currentNode->next;
    delete currentNode;
    size--;
  }
};
