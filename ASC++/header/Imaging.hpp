// Imaging.hpp
// declaration of the Color, Pixel, and Sprite struct types

#ifndef IMAGING_HPP
#define IMAGING_HPP 

// color
struct Color {
/*
	The "Color" object contains the a foreground and background 8-bit color for ANSI escape code
*/
	// properties
	int foreColor, backColor;
	// operators
	bool operator==(const Color& other) const;
};
// # preset colors
struct {
	int red = 196;
	int green = 46;
	int blue = 13;
	int magenta = 13;	
	int cyan = 14;
	int black = 232;
	int white = 255;
	int orange = 202;
} colors;

// pixel
struct Pixel {
/*
type that stores the color and symbol of a point on the paper
*/
	// properties
	Color color;
	char symbol; // the character that is in this "pixel"
	// methods
	void setPixel(int fC, int bC, char sy);
	void print();
	// operators
	bool operator==(const Pixel& other) const; 
};

// sprite
struct Sprite {
	// a type related to the storage and manipulation of an ASCII image composed of pixels
	// properties
	Pixel **pixels;
	int width, height;
	// constructors
	// construct simple ascii art with tranparent background color
	Sprite(char **chars, int foreColor);
	Sprite(Pixel** pixels);
};


#endif