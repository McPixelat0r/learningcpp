#include "Student.h"
#include <iostream>

Student::Student() {
  name = "Unknown";
  studentID = 0;
}
Student::Student(std::string newName, int newID) {
  name = newName;
  studentID = newID;
}
std::string Student::getName() { return name; }
int Student::getID() { return studentID; }

void Student::setName(std::string newName) {
  if (newName != "") {
    name = newName;
  }
}
void Student::printInfo() {
  std::cout << "Name: " << name << ", ID: " << studentID << "\n";
}

void Student::greet() {
  std::cout << "Hello, my name is " << name << std::endl;
}
