// 1. HEADER GUARD: Prevents this file from being included included twice
#ifndef STUDENT_H
#define STUDENT_H
#include <string>

// 2. CLASS DEFINITION
// (Only the function *declarations*)

class Student {
private:
  std::string name;
  int studentID;

public:
  Student();                               // Default constructor
  Student(std::string newName, int newID); // Constructor

  // Getters
  std::string getName();
  int getID();

  // Setters
  void setName(std::string newName);

  // Other methods
  void printInfo();
  void greet();
};

#endif
