// Colors.hpp
// declaration of the RGB and ColorPair struct types

#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

// WIP - RGB
// Killed an entire branch that was dedicaded to implementing since it spagettied, be warned
struct RGB {
	// properties
	unsigned int r,b,g;
	// constructors
	// using hexidecimal code
	RGB(std::string hex);
	//using rgb 
	RGB(int r, int b, int g);
	// operators
	bool operator==(const RGB& other) const;
};

// color pair
struct ColorPair {
/*
	a "ColorPair" object contains the a foreground and background as 8-bit colors
*/
	// properties
	unsigned int foreColorPair, backColorPair;
	// operators
	bool operator==(const ColorPair& other) const;
};
// preset colors 
// using unamed structs as preset containers is not recommended
struct {
	int red = 196;
	int orange = 202;
	int green = 46;
	int blue = 13;
	int magenta = 13;	
	int cyan = 14;
	int black = 232;
	int white = 255;
} colors;

#endif