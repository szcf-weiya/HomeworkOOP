#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle: public Shape
{
 public:
  Circle(); //no-arg constructor
  Circle(double); //parameter constructor
  double getRadius() const;
  void setRadius(double);
  double getArea() const;
  double getPerimeter() const;
  static int getNumberOfCircles();
 private:
  double radius;
  static int numberOfCircles;
};

#endif
