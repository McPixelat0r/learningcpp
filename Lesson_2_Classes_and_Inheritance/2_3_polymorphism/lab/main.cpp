#include <iostream>
#include <string>

#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

int main() {
  Employee *roster[3];
  roster[0] = new SalariedEmployee("Alice", 1000.00);
  roster[1] = new HourlyEmployee("Bob", 25.00);
  roster[2] = new HourlyEmployee("Carol", 30.00);

  roster[1]->addHours(40);
  roster[2]->addHours(25);

  for (int i = 0; i < 3; i++) {
    std::string employeeName = roster[i]->getName();
    double weeklyPay = roster[i]->getWeeklyPay();
    std::cout << employeeName << ": " << weeklyPay << std::endl;
  }

  for (int i = 0; i < 3; i++) {
    delete roster[i];
  }
}
