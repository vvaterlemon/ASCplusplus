// Imaging.cpp
// Definition of the Color, Pixel, and Sprite member functions
#include <iostream>
#include <string>
#include "../header/Imaging.hpp"

// Color definition
// operator
bool Color::operator==(const Color& other) const {
	return foreColor == other.foreColor && backColor == other.backColor;
}

// Pixel definitions
// methods
void Pixel::setPixel(int fC, int bC, char sy) {
	color.foreColor = fC;
	color.backColor = bC;
	symbol = sy;
}
void Pixel::print() {
	// for debugging
	std::cout << "\033[38;5;" + std::to_string(color.foreColor) + ";48;5;" + std::to_string(color.backColor) + "m" + symbol + "\033[0m";
}
// operator
bool Pixel::operator==(const Pixel& other) const {
	return color == other.color && symbol == other.symbol;
}

// WIP - Sprite definition
// constructor
Sprite::Sprite(char **chars, int foreColor) {

}
Sprite::Sprite(Pixel** pixels) {
	this->pixels = pixels;	
}