/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Diem-Huong Bui <diemhuongbui@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A program that prints shapes and changes their positions along (x,y) coordinates to "animate" movement.
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "constants.h"
#include "shape.h"
#include "point.h"
using std::vector;
using std::cout;
using std::endl;

void draw(const vector<Shape*> &v){
	for (int row = 0; row < Y; row++)
		for (int column = 0; column < X; column++){
			bool contains = false;
			for (Shape* e : v){
				if (e->contains(Point(column, row*1.5)) == true){
					contains = true;
					break;
				}
			}
			if (contains) //contains == true
				cout << '*';
			else cout << ' ';
		}
	cout << endl;
}

int main(){
	//declare constants for the number of frames to draw and the amt of time to sleep after drawing each frame
	const int frames = 40;
	const int frameSleep = 200;
	
	//for each frame...
	for (double i = 0; i < frames; i++){
		//create shapes
		Rectangle r(5, 3, Point((20 - (i/2)), (14 + (i/2)))); //moves right
		Square s(4, Point(35 + i+2, 9 + i+2)); //moves diagonally down to the right
		Ellipse e(9, (80, 20+ (i/2)), (80, 15+ (i/2))); //moves right
		Circle c(7, Point(60, 18 - (i/3))); //moves up
		
		//vector of shapes
		vector<Shape*> shapes = { &r, &s, &e, &c };

		//draw shapes
		draw(shapes);

		//Wait time before next frame is drawn
		std::this_thread::sleep_for(std::chrono::milliseconds(frameSleep));
	}

	system("pause"); 
	return 0;
}
