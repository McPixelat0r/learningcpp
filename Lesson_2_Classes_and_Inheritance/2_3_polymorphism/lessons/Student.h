// 1. HEADER GUARD: Prevents this file from being included included twice
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <iostream>

// 2. CLASS DEFINITION
// (Only the function *declarations*)

class Student : public Person {
private:
  int studentID;

public:
  Student(std::string newName, int newID) : Person(newName) {
    studentID = newID;
  }; // Constructor

  void printInfo() {
    std::cout << "Name: " << name << ", ID: " << studentID << "\n";
  }
  // We can override functions
  void greet() {
    std::cout << "Hi, my name is " << name << "\n";
    std::cout << "My student ID is " << studentID << "\n";
  };
};

#endif
