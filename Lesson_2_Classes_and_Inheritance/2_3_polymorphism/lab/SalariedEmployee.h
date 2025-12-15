#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H

#include "Employee.h"
#include <string>

class SalariedEmployee : public Employee {
private:
  double weeklySalary;

public:
  SalariedEmployee(std::string newName, double newSalary) : Employee(newName) {
    weeklySalary = newSalary;
  }

  double getWeeklyPay() { return weeklySalary; }
};

#endif
