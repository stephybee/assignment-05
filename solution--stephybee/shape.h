/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Diem-Huong Bui <diemhuongbui@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A header file defining a class Shape, Rectangle, Ellipse, Square, and Circle.
*/

#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"

//parent class
class Shape{
	public:
		virtual bool contains(const Point &p) const = 0; //pure virtual
		virtual ~Shape() = default; //virtual because rectangle and ellipse inherit
};

//child classes: Rectangle and Ellipse ------------------------------------------------------------------------------------------
class Rectangle :public Shape{
	private:
		double length;
		double height;
		Point center;
	public:
		Rectangle(double length = 0, double height = 0, Point center = Point(0,0));
		bool contains(const Point &p) const; 
};

class Ellipse :public Shape{
private:
	Point f;
	Point g;
	double distance;
public:
	Ellipse(double distance = 1, Point f = Point(0, 0), Point g = Point(0, 0));
	bool contains(const Point &p) const;
		
};

//-------------------------------------------------------------------------------------------------------------------------------

//grandchild classes: Square and Cicle ------------------------------------------------------------------------------------------
class Square :public Rectangle{
public:
	Square(double side = 0, Point center = Point(0,0));
};

class Circle :public Ellipse{
public:
	Circle(double diameter = 0, Point center = Point(0, 0));
};
//-------------------------------------------------------------------------------------------------------------------------------
#endif
