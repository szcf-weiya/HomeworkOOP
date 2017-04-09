#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
 public:
  virtual double getArea() const = 0;
  virtual double getPerimeter() const = 0;
};

#endif
