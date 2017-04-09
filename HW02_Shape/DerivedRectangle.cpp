#include "DerivedRectangle.h"

int Rectangle::numberOfRectangles = 0;

// construct a default rectangle object
Rectangle::Rectangle()
{
  width = 0;
  height = 0;
  numberOfRectangles++;
}

// construct a rectangle object with specified width and height
Rectangle::Rectangle(double width, double height)
{
  setWidth(width);
  setHeight(height);
  numberOfRectangles++;
}

// return the width of this rectangle 
double Rectangle::getWidth() const
{
  return width;
}
// set a new width
void Rectangle::setWidth(double width)
{
  this->width = width>=0 ? width : 0;
}
// return the height of this rectangle
double Rectangle::getHeight() const
{
  return height;
}

// set a new height
void Rectangle::setHeight(double height)
{
  this->height = height >= 0 ? height : 0;
}

// return the area of this rectangle
double Rectangle::getArea() const
{
  return width * height;
}

// return the perimeter of this rectangle
double Rectangle::getPerimeter() const
{
  return 2 * (width + height);
}

// return the number of rectangle objects
int Rectangle::getNumberOfRectangles()
{
  return numberOfRectangles;
}
