/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Diem-Huong Bui <diemhuongbui@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A file defining functions of a class Shape, Rectangle, Ellipse, Square, and Circle.
*/

#include <cmath>
#include "shape.h"
using std::abs;

Rectangle::Rectangle(double length, double height, Point center) : length(length), height(height), center(center){}
bool Rectangle::contains(const Point &p) const{
	return abs(p.getX() - center.getX()) <= length && abs(p.getY() - center.getY()) <= height;
}

Square::Square(double side, Point center) : Rectangle(side / 2, side / 2, center){}

Ellipse::Ellipse(double distance, Point f, Point g) : f(f), g(g), distance(distance){}
bool Ellipse::contains(const Point &p) const{
	return p.distance(f) + p.distance(g) <= distance;
}

Circle::Circle(double diameter, Point center) : Ellipse(diameter, center, center){}
