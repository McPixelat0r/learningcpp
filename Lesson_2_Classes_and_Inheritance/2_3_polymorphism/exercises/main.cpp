#include "Rectangle.h"
#include "Square.h"
#include <iostream>

void printAnyArea(Rectangle *rectangle) { std::cout << rectangle->getArea(); }
int main() {
  Rectangle rectangle_1(10, 5);
  std::cout << "Rectangle\'s area: " << rectangle_1.getArea() << std::endl;

  Square square_1(7);
  std::cout << "Square\'s area: " << square_1.getArea() << std::endl;

  Rectangle *rectangle_2 = new Rectangle(10, 5);
  Square *square_2 = new Square(7);

  printAnyArea(rectangle_2);
  printAnyArea(square_2);

  delete rectangle_2;
  delete square_2;
}
