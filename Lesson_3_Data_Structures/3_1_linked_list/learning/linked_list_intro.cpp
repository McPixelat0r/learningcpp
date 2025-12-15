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

int main() {
  Node *head = new Node(10);

  Node *secondNode = new Node(20);

  head->next = secondNode;

  int secondValue = head->next->data;
  std::cout << secondValue;

  head->next->next = new Node(30);
  int thirdValue = head->next->next->data;
  std::cout << thirdValue;
  return 0;
}
