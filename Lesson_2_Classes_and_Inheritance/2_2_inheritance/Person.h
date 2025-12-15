#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
  std::string name;

public:
  Person() : name("Unknown") {} // Default constructor

  // Method: Initialization
  // This is a one step process:
  // As the Student object is being born, its name member is initialized
  // (constructed) immediately by calling the std::string constructor that takes
  // newName
  // Why is this better?
  // 1. Performance: For simple types like int, it makes no difference. But for
  // complex objects like std::string, initialization is more efficient. We
  // avoid the "default construct, then assign" two-step. We just do one
  // "construct-with-value" step.
  // 2. Necessity: Some types must be initialized this way. If your class has a
  // member variable that is const or a reference, you cannot assign to it. You
  // must initialize it in the initializer list.

  Person(std::string newName) : name(newName) {} // This is INITIALIZATION

  // Method: Assignment
  // This is a two step process:
  // 1. Before the '{' runs, the 'name' (which is a std::string object) is
  // **created** using its own default constructor (it becomes '""')
  // 2. Inside the '{', the **assignment operator** is called to copy the value
  // of 'newName' into 'name'
  void setName(std::string newName); // This is ASSIGNMENT

  std::string getName();

  void greet() { std::cout << "Hello, my name is " << name << "\n"; };
};
#endif
