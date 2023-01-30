// Imaging.cpp
// Definition of the Pixel and Sprite member functions
#include <iostream>
#include <string>
#include "../header/Imaging.hpp"

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