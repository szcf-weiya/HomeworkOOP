#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle: public Shape
{
 public:
  Rectangle(); //no-arg constructor
  Rectangle(double width, double height); //constructor with parameters 
  double getWidth() const;
  void setWidth(double);
  double getHeight() const;
  void setHeight(double);
  double getArea() const;
  double getPerimeter() const;
  static int getNumberOfRectangles();
 private:
  double width;
  double height;
  static int numberOfRectangles;
};


#endif
