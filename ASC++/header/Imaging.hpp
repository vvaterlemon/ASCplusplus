// Imaging.hpp
// declaration of the RGB, ColorPairPair, Pixel, and Sprite struct types

#ifndef IMAGING_HPP
#define IMAGING_HPP 

#include <string>

// RGB
struct RGB {
	// properties
	int r,b,g;
	// constructors
	// using hexidecimal code
	RGB(std::string hex);
	//using rgb 
	RGB(int r, int b, int g);
};

// color pair
struct ColorPair {
/*
	a "ColorPair" object contains the a foreground and background 8-bit color for ANSI escape code
*/
	// properties
	int foreColorPair, backColorPair;
	// operators
	bool operator==(const ColorPair& other) const;
};
// # preset colors
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

// pixel
struct Pixel {
/*
	a "Pixel" stores the color and symbol of a point on the paper
*/
	// properties
	ColorPair color;
	char symbol; // the character that is in this "pixel"
	// methods
	void setPixel(int fC, int bC, char sy);
	void print();
	// operators
	bool operator==(const Pixel& other) const; 
};

// sprite
struct Sprite {
/*
	a "Sprite" stores and manipulates an ASCII image composed of pixels
*/
	// properties
	Pixel **pixels;
	int width, height;
	// constructors
	// construct simple ascii art with tranparent background color
	Sprite(char **chars, int foreColorPair);
	Sprite(Pixel** pixels);
};


#endif
