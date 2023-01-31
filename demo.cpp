// main.cpp

#include <iostream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ASC++/header/Engine.hpp"
using namespace std;
	
int main() {
	Engine engine;
	int width = 68;
	int height = 34;
	/*
	note, the origin (0,0) of the paper is at the upper-left corner.
	The parameters of any "Draw..." method usually follows this order (int x, int y, int foreground color, int background color, char symbol)  
	*/
	Paper paper(width,height,250,255,'#',true);
	paper.DrawPoint(1,1,0,0,' ');
	paper.DrawText(3,1,0,255,"This is a point");
	paper.DrawRectangle(8,4,6,3,colors.black,colors.black,' ');
	paper.DrawRectangle(10,10,8,4,colors.red,colors.blue,'@');
	// game loop
	while (true) {
		engine.updatePaper(paper);	
	}
	getchar();
	return 0;
}