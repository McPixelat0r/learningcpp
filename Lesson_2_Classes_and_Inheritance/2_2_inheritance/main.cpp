#include "Student.h"

int main() {
  Person p("Alice");
  p.greet();

  Student s("Bob", 12345);

  s.setName("Robert");

  s.greet();

  return 0;
}
