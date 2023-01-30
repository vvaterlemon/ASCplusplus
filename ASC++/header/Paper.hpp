// Paper.hpp
// Declaration of the Paper class type

#ifndef PAPER_HPP
#define PAPER_HPP

#include <string>
#include "Imaging.hpp"

class Paper {
/*
	The "Paper" object is the canvas that is drawn on and prints it to the terminal
*/
private:
	// properties
	Pixel **pixels; // holds the 2d image as Pixel objects
 	bool isChanged = 0; // to determine if any changes have been done pixels; avoids rendering consecutive, indentical frames 
	std::string frameString; // holds the 2d image as a string (colored using ANSI escape patterns)
	std::string snippetString; // holds the line of consecutative, same colored pixels (to be concatenated to "frameString")
 	ColorPair snippetColorPair; // related to above; the color of the pixel in question
 	int startyLocation; // WIP - the y location in the terminal screen of there the program started
 	int coorWidth, coorHeight; // width/height that the coordinate labels would occupy if enabled    
 	char digit; // digit of a coordinate lable at a particular 2d-index in "pixels"
public:
	Pixel** getPixels() {
		return pixels;
	}
	// properties
	int width, height; // width/height of the actual paper space
	ColorPair color; // color of the paper space
	char symbol; // symbol of the paper space
	// methods
	// constructors
	Paper(int w, int h, int fC, int bC, char sy, bool showC = false); // construct with characters
	Paper(int w, int h, int bC, bool showC); // WIP - contruct without characters 
	void Render(bool isColorPaired = true);
	void DrawPoint(int x, int y, int fC, int bC, char sy);
	void DrawSymbol(int x, int y, int fC, char sy);
	void DrawRectangle(int x, int y, int w, int h, int fC, int bC, char sy);
	void DrawText(int x, int y, int fC, int bC, std::string text);
	void DrawLine(); // WIP
	void DrawSprite(int x, int y, Sprite sprite);
};

#endif
