#include "Person.h"
#include "Student.h"

int main() {
  Person *p1 = new Person("Alice");
  Person *p2 = new Student("Bob", 12345); // This is allowed!

  p1->greet();
  p2->greet();

  // Don't forget to delete
  delete p1;
  delete p2;

  return 0;
}
