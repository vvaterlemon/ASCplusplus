// Imaging.cpp
// Definition of the ColorPair, Pixel, and Sprite member functions
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include "../header/Imaging.hpp"

// maps
std::map<char, int> h2d_map = {
	{'0', 0},
	{'1', 1},
	{'2', 2},
	{'3', 3},
	{'4', 4},
	{'5', 5},
	{'6', 6},
	{'7', 7},
	{'8', 8},
	{'9', 9},
	{'a', 10},
	{'b', 11},
	{'c', 12},
	{'d', 13},
	{'e', 14},
	{'f', 15},
};

// functions
int hex2dec(std::string hex) {
	if (hex.length() == 0) {
		return 0;
	} else {
		return h2d_map[hex[0]]*pow(16,hex.length()-1) + hex2dec(hex.erase(0,1));
	}
}

// RGB color definitions
// constructors
// using hexidecimal code string
RGB::RGB(std::string hex) {
	r = hex2dec(hex.substr(0,2));
	b = hex2dec(hex.substr(2,2));
	g = hex2dec(hex.substr(4,2));
}
// using rgb int
RGB::RGB(int r, int b, int g) : r(r), b(b), g(g) {}

// color pair definition
// operator
bool ColorPair::operator==(const ColorPair& other) const {
	return foreColorPair == other.foreColorPair && backColorPair == other.backColorPair;
}

// pixel definitions
// methods
void Pixel::setPixel(int fC, int bC, char sy) {
	color.foreColorPair = fC;
	color.backColorPair = bC;
	symbol = sy;
}
void Pixel::print() {
	// for debugging
	std::cout << "\033[38;5;" + std::to_string(color.foreColorPair) + ";48;5;" + std::to_string(color.backColorPair) + "m" + symbol + "\033[0m";
}
// operator
bool Pixel::operator==(const Pixel& other) const {
	return color == other.color && symbol == other.symbol;
}

// WIP - sprite definition
// constructor
Sprite::Sprite(char **chars, int foreColorPair) {

}
Sprite::Sprite(Pixel** pixels) {
	this->pixels = pixels;	
}