// main.cpp

#include <iostream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ASC++/header/Paper.hpp"
#include "ASC++/header/Engine.hpp"
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
	
	if the direction is cen, aka [0,0], is selected, it would branch Atom string into two that is spawned at the left- and right- forward directions  
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

void DrawAtom(Atom* atoms) {

}
	
int main() {
	Engine engine;
	int width = 68;
	int height = 34;
	Paper paper(width,height,255,colors.orange,' ',false);
	paper.DrawPoint(1,1,1,1,' ');
	paper.DrawRectangle(8,4,6,3,colors.black,colors.black,' ');
	paper.DrawRectangle(10,10,8,4,colors.red,colors.blue,'@');
	// game loop
	while (true) {
		engine.updatePaper(paper);	
	}
	getchar();
	return 0;
}