#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee {
protected:
  std::string name;

public:
  Employee(std::string newName) : name(newName) {};

  // If a class has any virtual functions, it should have a
  // virtual destructor to ensure correct cleanup when
  // deleting a derived object via a base class pointer.
  virtual ~Employee() = default;
  virtual double getWeeklyPay() { return 0.0; }

  // We provide a default implementation for addHours which does nothing.
  // This is valid for classes like SalariedEmployee.
  // To fix the -Wunused-parameter warning, we simply comment out
  // the variable name 'hours' in the *definition*.
  virtual void addHours(double /*hours*/) {}

  std::string getName() { return name; }
};

#endif
