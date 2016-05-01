/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Diem-Huong Bui <diemhuongbui@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A header file defining a class Point.
*/

#ifndef POINT_H
#define POINT_H

class Point{
	private:
		double x;
		double y;
	public:
		Point(double x = 0, double y = 0);
		double getX() const;
		double getY() const;
		double distance(const Point &p) const;
};

#endif
