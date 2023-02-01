// Colors.cpp
// Definition of the RGB and ColorPair member functions 

#include <map>
#include <math.h>
#include <string>

#include "../header/Colors.hpp"

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
// operator
bool RGB::operator==(const RGB& other) const {
	return r == other.r && g == other.g && b == other.b;
}

// color pair definition
// operator
bool ColorPair::operator==(const ColorPair& other) const {
	return foreColorPair == other.foreColorPair && backColorPair == other.backColorPair;
}