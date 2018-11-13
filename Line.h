/*
Author: Alejandro Navarro
Assignment Title: Line, Line.h
Assignment Description: Create a Line Object
Due Date: 10-30-2018
Date Created: 10-29-2018
Date Last Modified: 10-29-2018
*/

#ifndef LINE_H_
#define LINE_H_

#include <ostream>
#include <iostream>
using namespace std;


struct Point{
	double x;
	double y;

  /*
  description: constructor for the Point structure.
  return: none
  precondition: none
  postcondition: Point structure initialized.
  */
	Point(double a = 0, double b = 0){
		x = a;
		y = b;
	}

  /*
  description: displays the x- and y-coordinates.
  return: none
  precondition: none
  postcondition: structure remains the same.
  */
	void display(ostream& out){
		out << "(" << x << "," << y << ")";
	}
};

/*
UML Diagram for Line Class
****************************
- p1: Point
- p2: Point
****************************
+ Line()
+ Line(a: Point, b: Point):
+ setFirstPoint(a: Point): void
+ setSecondPoint(b: Point): void
+ getFirstPoint(): Point
+ getSecondPoint(): Point
+ slope(m: double&): bool
+ yIntercept(b: double&): bool
+ isParallel(l : Line): bool
+ isColinear(l: Line): bool
+ isPerpendicular(l: Line): bool
+ intersect(l: Line): Point
+ display(out: outstream&): void
*/


class Line{
	private:
		Point p1, p2;

	public:
    /*
    description: constructor for the Line object.
    return: none
    precondition: none
    postcondition: Line object initliazed with defualt points.
    */
		Line();

		/*
		description: constructor for the Line object.
    return: none
    precondition: none
    postcondition: Line object initliazed with custom points.
		*/
		Line(Point, Point);

    /*
    description: sets the first point to the Point arguement.
    return: none.
    precondition: valid Point structure
    postcondition: Line object's first point is set to a new Point.
    */
		void setFirstPoint(Point);

		/*
    description: sets the second point to the Point arguement.
    return: none.
    precondition: valid Point structure
    postcondition: Line object's second point is set to a new Point.
    */
		void setSecondPoint(Point);

    /*
    description: gets the first point.
    return: Point
    precondition: none
    postcondition: Line object remains unchanged.
    */
		Point getFirstPoint() const;

		/*
		description: gets the second point.
		return: Point
		precondition: none
		postcondition: Line object remains unchanged.
		*/
		Point getSecondPoint() const;

    /*
    description: determines whether there is a slope,
                 then calculates slope if it exist.
    return: boolean
    precondition: a valid double variable.
    postcondition: m will be set to the slope if a slope exist and return true,
                   otherwise false.
    */
		bool slope(double& m) const;

		/*
		description: determines whether there is a y-intercept,
                 then calculates the y-intercept if it exist.
    return: boolean
    precondition: a valid double  variable.
    postcondition: b will be set to the y-intercept if a y-intercept exist and
                   returns true, otherwise false.
		*/
		bool yIntercept(double& b) const;

    /*
    description: determines whether another Line is parallel.
    return: boolean
    precondition: a valid Line object is passed as an arguement.
    postcondition: both Line objects remain unchanged.
    */
		bool isParallel(Line) const;

    /*
    description: determines whether another Line is collinear.
    return: boolean
    precondition: a valid Line object is passed as an arguement
    postcondition: both Line object remain unchange.
    */
		bool isCollinear(Line) const;

		/*
		description: determines whether another Line is perpendicular.
		return: boolean
		precondition: a valid Line object is passed as an argument.
		postcondition: both Line objects remain unchange.
		*/
		bool isPerpendicular(Line) const;

    /*
    description: calculates the point where another Line intersects this Line.
    return: Point
    precondition: a valid Line that intersects this Line.
    postcondition: both Line object remain unchanged.
    */
		Point intersect(Line) const;

    /*
    description: prints the equation of the line (in slope intercept form)
                 to the output stream.
    return: none
    precondtion: pass outstream by reference.
    postcondition: Line object remains unchanged.
    */
		void display(ostream&) const;
};

#endif /* LINE_H_ */
