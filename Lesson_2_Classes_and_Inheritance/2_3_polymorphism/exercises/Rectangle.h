// Rectangle.h

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
  double width;
  double height;

public:
  Rectangle(double newWidth, double newHeight)
      : width(newWidth), height(newHeight) {};

  double getWidth() { return width; }

  double getHeight() { return height; }

  virtual double getArea() { return width * height; }
};

#endif
