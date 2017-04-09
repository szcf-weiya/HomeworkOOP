#include "DerivedCircle.h"

int Circle::numberOfCircles = 0;

// construct a default circle object
Circle::Circle()
{
  radius = 0;
  numberOfCircles++;
}

// construct a circle object with specified radius
Circle::Circle(double radius)
{
  setRadius(radius);
  numberOfCircles++;
}

// return the radius of this circle
double Circle::getRadius() const
{
  return radius;
}

// set a new radius
void Circle::setRadius(double radius)
{
  this->radius = (radius >= 0) ? radius : 0;
}


// return the area of this circle
double Circle::getArea() const
{
  return radius * radius * 3.14;
}

// return the perimeter of this circle
double Circle::getPerimeter() const
{
  return 2 * 3.14 * radius;
}

// return the number of circle objects
int Circle::getNumberOfCircles()
{
  return numberOfCircles;
}
