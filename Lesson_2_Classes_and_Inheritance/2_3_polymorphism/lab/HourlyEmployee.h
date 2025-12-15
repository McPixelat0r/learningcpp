
#ifndef HOURLY_EMPLOYEE_H
#define HOURLY_EMPLOYEE_H

#include "Employee.h"
#include <string>

class HourlyEmployee : public Employee {
private:
  double hourlyRate;
  double hoursWorked;

public:
  HourlyEmployee(std::string newName, double newHourlyRate)
      : Employee(newName), hourlyRate(newHourlyRate) {
    hoursWorked = 0;
  }
  HourlyEmployee(std::string newName, double newHourlyRate,
                 double newHoursWorked)
      : Employee(newName) {
    hourlyRate = newHourlyRate;
    hoursWorked = newHoursWorked;
  }

  void addHours(double hours) override { hoursWorked += hours; }

  double getWeeklyPay() override {
    double finalHoursWorked = hoursWorked;
    hoursWorked = 0;
    return hourlyRate * finalHoursWorked;
  }
};

#endif
