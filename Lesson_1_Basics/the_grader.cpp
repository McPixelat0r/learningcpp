#include <iostream>

// 1. The Grader
void printGrade(int score) {
  if (score >= 90) {
    std::cout << "You got an A!";
  } else if (score >= 80) {
    std::cout << "You got a B.";
  } else if (score >= 70) {
    std::cout << "You got a C.";
  } else if (score >= 60) {
    std::cout << "You got a D.";
  } else {
    std::cout << "You got an F.";
  }
}

int main() {
  std::cout << "Please enter your score: ";
  int grade;
  std::cin >> grade;
  printGrade(grade);
  return 0;
}
