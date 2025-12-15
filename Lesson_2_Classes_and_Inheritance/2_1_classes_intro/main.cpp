#include "Student.h"
#include <iostream>

int main() {
  Student student1("Alex", 12345);
  student1.printInfo();

  Student student2;
  student2.setName("Jane");
  std::cout << student2.getName() << std::endl;
  return 0;
}
