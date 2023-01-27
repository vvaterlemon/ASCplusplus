// main.cpp

#include <iostream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ASC++/header/Paper.hpp"
using namespace std;

struct Dir {
	int fb, lr; // fb (forward/backwards), lr (left/right) 
	/* example
	the table below shows the codes to the directions relative to "cen" (center). Up & left are positive
	+, 0, - are shorthands for 1, 0, -1 repectively
	+,+|+,0|+,-
	-----------
	0,+|cen|0,-
	-----------
	-,+|-,0|-,-
	
	if the direction is cen, aka [0,0],
	*/
	Dir(int fb, int lr) {
		this->fb = fb;
		this->lr = lr;
	}
};

struct Atom {
	Pixel pixel;
	Dir direction;
};
	
int main() {
	int width = 68;
	int height = 34;
	Paper paper(width,height,255,colors.orange,' ',true);
	paper.DrawPoint(1,1,1,1,' ');
	paper.DrawRectangle(8,4,6,3,colors.black,colors.black,' ');
	paper.DrawRectangle(10,10,8,4,colors.red,colors.blue,'@');
	// game loop
	//while (true) {
	Engine.updatePaper(paper);	
	//}
	getchar();
	return 0;
}
