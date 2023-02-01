// Paper.hpp
// Declaration of the Paper class type

#ifndef PAPER_HPP
#define PAPER_HPP

#include <string>
#include "Imaging.hpp"

// functions
extern unsigned int getsize(const auto &arr);
extern unsigned int digitsize(const unsigned int n);

class Paper {
/*
	The "Paper" object is the canvas that is drawn on and is printed it to the terminal
*/
private:
	// properties
	Pixel **pixels; // holds the 2d image as Pixel objects
 	bool isChanged = false; // to determine if any changes have been done pixels; avoids rendering consecutive, indentical frames 
	std::string frameString; // holds the 2d image as a string (colored using ANSI escape patterns)
	std::string snippetString; // holds the line of consecutative, same colored pixels (to be concatenated to "frameString")
 	ColorPair snippetColorPair; // related to above; the color of the pixel in question
 	unsigned int startyLocation; // WIP - the y location in the terminal screen of there the program started
 	unsigned int coorWidth, coorHeight; // width/height that the coordinate labels would occupy if enabled    
 	char digit; // digit of a coordinate lable at a particular 2d-index in "pixels"
public:
	Pixel** getPixels() {
		return pixels;
	}
	// properties
	unsigned int width, height; // width/height of the actual paper space
	ColorPair color; // color of the paper space
	char symbol; // symbol of the paper space
	// constructors
	Paper(unsigned int w, unsigned int h, unsigned int fC, unsigned int bC, char sy, bool showC = false); // construct with characters
	Paper(int w, int h, int bC, bool showC); // WIP - contruct without characters 
	// get set
	bool IsChanged();
	// methods
	void Render(); // prints the image stored in "pixels" using ANSI escape codes with std::cout
	// "Drawing" is the process of setting "pixel" objects in "pixels"
	void DrawPoint(int x, int y, unsigned int fC, unsigned int bC, char sy); // "Draws" a pixel at a coordinate
	void DrawSymbol(int x, int y, unsigned int fC, char sy); // WIP - "Draws" a pixel (with transparent background) at a coordinate
	void DrawRectangle(int x, int y, unsigned int w, unsigned int h, unsigned int fC, unsigned int bC, char sy); // "Draws" a rectangle using "DrawPoint()"
	void DrawText(int x, int y, unsigned int fC, unsigned int bC, std::string text); // "Draws" a text using "DrawPoint()"
	void DrawLine(int x1, int y1, int x2, int y2, unsigned int fC, unsigned int bC, char symbol); // WIP - "Draws" a line using "DrawPoint()" 
	void DrawSprite(int x, int y, Sprite sprite); // WIP - "Draws" a sprite image using "DrawPoint()"
};

#endif
