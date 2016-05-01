/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Diem-Huong Bui <diemhuongbui@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A file defining functions of a class Point.
*/

#include <cmath>
#include "point.h"

Point::Point(double x, double y) : x(x), y(y){} //default point (0,0) ; constructor
double Point::getX() const { return x; } //getters for x and y points
double Point::getY() const { return y; }
double Point::distance(const Point &p) const { 
	return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
}
