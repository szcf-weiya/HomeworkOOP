# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <iomanip>
# include <stdlib.h>
# include "Shape.h"
# include "DerivedCircle.h"
# include "DerivedRectangle.h"
using namespace std;

int main()
{
  string line;
  string type;
  double widthNum, heightNum, radius;
  ifstream fin("input.txt");
  ofstream fout("out.txt");
  fout << fixed << setprecision(2); // keep two the decimal places
  if (fin.is_open())
    {
      while (getline(fin, line))
	{
	  stringstream ss(line);
	  while(!ss.eof())
	    {
	      ss >> type; // for split string 
	      if (type == "Rectangle")
		{
		  string widthStr, heightStr;
		  ss >> widthStr;
		  ss >> heightStr;
		  widthNum = strtod(widthStr.c_str(), NULL); // transfer str to double
		  heightNum = strtod(heightStr.c_str(), NULL);
		  Shape *rect = new Rectangle(widthNum, heightNum);;
		  // casting to Rectangle*
		  fout << "Rectangle " << static_cast<Rectangle*>(rect)->getNumberOfRectangles() << " area: " << (*rect).getArea() << endl
		       << "Rectangle " << static_cast<Rectangle*>(rect)->getNumberOfRectangles() << " perimeter: " << (*rect).getPerimeter() << endl;
		  delete rect; // free
		  break;
		}
	      else
		{
		  string radiusStr;
		  ss >> radiusStr;
		  radius = strtod(radiusStr.c_str(), NULL); // transfer str to double
		  Shape *cir = new Circle(radius);
		  // casting to Circle*
		  fout << "Circle " << static_cast<Circle*>(cir)->getNumberOfCircles()  << " area: " << (*cir).getArea() << endl
		       << "Circle " << static_cast<Circle*>(cir)->getNumberOfCircles()  << " perimeter: " << (*cir).getPerimeter() << endl;
		  delete cir;  // free
		  break;
		}
	    }
	}
    }
  fout << endl; // keep a space line

  // count the number of objects
  Shape *rect = new Rectangle();
  Shape *cir = new Circle();
  fout << "Rectangle number: " << static_cast<Rectangle*>(rect)->getNumberOfRectangles() - 1 << endl
       << "Circle number: " << static_cast<Circle*>(cir)->getNumberOfCircles() - 1 << endl;
  delete rect; // free
  delete cir; // free
  fout.close();
  fin.close();
}
