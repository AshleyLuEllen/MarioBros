/*
Author: Alejandro Navarro
Assignment Title: Line, Line.cpp
Assignment Description: Create a Line Object
Due Date: 10-30-2018
Date Created: 10-29-2018
Date Last Modified: 10-29-2018
*/

#include "Line.h"

/*
description: constructor for the Line object.
return: none
precondition: none
postcondition: Line object initliazed with defualt points.
*/
Line::Line()
{
  p1 = Point(0,0);
  p2 = Point(1.0, 1.0);
}

/*
description: constructor for the Line object.
return: none
precondition: none
postcondition: Line object initliazed with custom points.
*/
Line::Line(Point a, Point b)
{
  p1 = a;
  p2 = b;
}

/*
description: sets the first point to the Point arguement.
return: none.
precondition: valid Point structure
postcondition: Line object's first point is set to a new Point.
*/
void Line::setFirstPoint(Point a)
{
  p1 = a;
}

/*
description: sets the second point to the Point arguement.
return: none.
precondition: valid Point structure
postcondition: Line object's second point is set to a new Point.
*/
void Line::setSecondPoint(Point b)
{
  p2 = b;
}

/*
description: gets the first point.
return: Point
precondition: none
postcondition: Line object remains unchanged.
*/
Point Line::getFirstPoint() const
{
  return p1;
}

/*
description: gets the second point.
return: Point
precondition: none
postcondition: Line object remains unchanged.
*/
Point Line::getSecondPoint() const
{
  return p2;
}

/*
description: determines whether there is a slope,
             then calculates slope if it exist.
return: boolean
precondition: a valid double variable.
postcondition: m will be set to the slope if a slope exist and return true,
               otherwise false.
*/
bool Line::slope(double& m) const
{
  bool slopeExist = false;

  //denominator
  double den = p2.x - p1.x;

  if(den != 0)
  {
    slopeExist = true;
    m = (p2.y - p1.y)/den;
  }

  return slopeExist;
}

/*
description: determines whether there is a y-intercept,
             then calculates the y-intercept if it exist.
return: boolean
precondition: a valid double  variable.
postcondition: b will be set to the y-intercept if a y-intercept exist and
               returns true, otherwise false.
*/
bool Line::yIntercept(double& b) const
{
  bool bExist = false;

  //slope
  double m;
  slope(m);

  b = p1.y - (p1.x * m);

  if(b != 0)
    bExist = true;

  return bExist;
}

/*
description: determines whether another Line is parallel.
return: boolean
precondition: a valid Line object is passed as an arguement.
postcondition: both Line objects remain unchanged.
*/
bool Line::isParallel(Line l) const
{
  double m1 = 0, m2 = 0;
  slope(m1);
  l.slope(m2);
  //Check if slopes are equal
  return (m1 == m2);
}

/*
description: determines whether another Line is collinear.
return: boolean
precondition: a valid Line object is passed as an arguement
              postcondition: both Line object remain unchange.
*/
bool Line::isCollinear(Line l) const
{
  double m1 = 0, m2 = 0,
         b1 = 0, b2 = 0;

  slope(m1);
  l.slope(m2);

  yIntercept(b1);
  l.yIntercept(b2);

  //Checks if slopes and y-intercept are equal
  return (m1 == m2 && b1 == b2);
}

/*
description: determines whether another Line is perpendicular.
return: boolean
precondition: a valid Line object is passed as an argument.
postcondition: both Line objects remain unchange.
*/
bool Line::isPerpendicular(Line l) const
{
  double m1 = 0, m2 = 0;
  slope(m1);
  l.slope(m2);
  //Check if the negative inverse of this slope equals the other slope
  return ((1.0/m1) * -1.0 == m2);
}

/*
description: calculates the point where another Line intersects this Line.
return: Point
precondition: a valid Line that intersects this Line.
postcondition: both Line object remain unchanged.
*/
Point Line::intersect(Line l) const
{
  double x, y;
  double m1 = 0, m2 = 0,
         b1 = 0, b2 = 0;

  //Calculate slope
  slope(m1);
  l.slope(m2);

  //Calculate y-intercept
  yIntercept(b1);
  l.yIntercept(b2);

  //Caculate intersection
  if(getFirstPoint().x == getSecondPoint().x)
  {
    y = getFirstPoint().x;
    x = getFirstPoint().x;
  }
  else if(l.getFirstPoint().x == l.getSecondPoint().x)
  {
    y = l.getFirstPoint().x;
    x = l.getFirstPoint().x;
  }
  else
  {
    x = (b2 - b1) / (m1 - m2);
    y = m1 * x + b1;
  }

  return Point(x, y);
}

 /*
description: prints the equation of the line (in slope intercept form)
             to the output stream.
return: none
precondtion: pass outstream by reference.
postcondition: Line object remains unchanged.
*/
void Line::display(ostream& out) const
{
  double m,
         b;

  slope(m);
  yIntercept(b);

  //Checks if the line is a valid function
  if(getFirstPoint().x != getSecondPoint().x)
  {
    //Display equation
    out << "y = ";

    if(m == 1)
      cout << "x ";
    else if(m == -1)
      cout << "-x ";
    else if(m != 0 )
      cout << m << "x ";

    if(b >0)
      cout << "+ " << b;
    if(b < 0)
      cout << b;
  }else
    cout << "x = " << getFirstPoint().x;
}
