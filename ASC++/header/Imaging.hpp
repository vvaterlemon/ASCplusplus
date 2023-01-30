// Imaging.hpp
// declaration of the Pixel and Sprite struct types

#ifndef IMAGING_HPP
#define IMAGING_HPP 

#include "Colors.hpp"

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
