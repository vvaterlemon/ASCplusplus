// Paper.cpp
// Definition of the Paper member functions 

#include <iostream>
#include <string>
#include <math.h>
#include "../header/Paper.hpp"

int getsize(const auto &arr) {
	// return the number of elements in an array
	return sizeof(arr)/sizeof(arr[0]) - 1;
}

int digitsize(const int n) {
	// returns the number of digits in an int of base 10
	if (n == 0) return 1;
	return floor(log10(abs(n))) + 1;
}

// constructors
// Suggestion - applicable to all Paper related methods, bC should be prioritised before fC
Paper::Paper(int w, int h, int fC, int bC, char sy, bool showC) {
	width = w;
	height = h;
	color.foreColorPair = fC;
	color.backColorPair = bC;
	symbol = sy;
	startyLocation = "\e[6n"[6]; // WIP
	coorWidth = (showC) ? digitsize(w) : 0;
	coorHeight = (showC) ? digitsize(h) : 0;
	// Set pixels size, colors, and symbol
	pixels = new Pixel*[h + coorHeight];
	for (int j = 0; j < h + coorHeight; j++) {
		pixels[j] = new Pixel[w + coorWidth];
		// ColorPair in and symbolize pixels
		for (int i = 0; i < w + coorWidth; i++) {
			if (showC) {
				// WIP - set coordinates coordinate space pixels
				if (i < coorWidth && j >= coorHeight) {
					// set the vertical coordinate
					digit = (i<=digitsize(j-coorHeight)-1) ? std::to_string(j-coorHeight)[i] : ' ';
					/*
					case example where showC=1, width=15, height=5
					 01234567 ... 14 -> i index of "pixel"
					0  000000 ... 1  -> x coordinate
					1  012345 ... 2  -> x cooridnate
					200              -> paper space
					301
					402
					503
					604
					||└> y-coordinate
					|└-> y-coordinate
					└--> j index of "pixels"  
					
					when setting the pixels for vertical coordinates, case that j=2 & i=1 & coorHeight=2:
						digit = (1<=digitsize(2-2)-1)
								    digitsize(0)-1
								    1-1
								 1<0
								 false

					though still bugged, the alignment of the digit does not align in the same line as its place
					
					Expected behaviour: 00000000011 ...
										12345678901

					Resulted behaviour: 12345678911 ...
										00000000001
					*/
					// Alternate between black and white foreground ant background
					if (j % 2) {
						pixels[j][i].setPixel(colors.black,colors.white,digit); 
					} else {
						pixels[j][i].setPixel(colors.white,colors.black,digit);
					}
				} else if (j < coorHeight) {
					if (i < coorWidth) {
						// the corner with no labels
						pixels[j][i].setPixel(255,255,' ');
					} else {
						// set the horizontal labels
						digit = (j >= digitsize(i-coorWidth)) ? ' ' : std::to_string(i-coorWidth)[j];
						// Alternate between black and white foreground ant background
						if (i % 2) {
							pixels[j][i].setPixel(colors.black,colors.white,digit);
						} else {
							pixels[j][i].setPixel(colors.white,colors.black,digit);
						}
					}	
				} else {
					// Set paper space pixels
					pixels[j][i].setPixel(fC, bC, sy);
				}
			} else {
				// Set paper space pixels 
				pixels[j][i].setPixel(fC, bC, sy);
			}
		}
	}
}

// get-setters
bool Paper::IsChanged() { return isChanged; }

// methods
void Paper::Render() {
	/*
		prints the image stored in "pixels" using ANSI escape codes with std::cout
		
		This function is prime target for any optimization

		Bugs: 
			- still Renders despite current and previous frames being identical
			- Rendering at high fps makes the cursor flicker and dart about the screen (despite there being only 1 cout command in Render), likely to an issue in how the terminal reads ANSI commands
	*/
	// only create and print "frameString" if the current frame is different from the last
	if (isChanged) {
		// tell terminal to set cursor (aka print location) at location (0,2)
		// WIP - should instead be set to location where the program is called 
		frameString = "\033[2;0H";
		// initialize for the "ColorPair" at the origin
		snippetColorPair = pixels[0][0].color;
		snippetString = pixels[0][0].symbol;
		// iterate over each j coordinate
		for (int j = 0; j < height + coorHeight; j++) {
			// iterate over each i coordinate
			for (int i = 0; i < width + coorWidth; i++) {
				// skip origin
				if (!(i+j == 0)) {
					Pixel &currentPixel = pixels[j][i];
					if (snippetColorPair == currentPixel.color) {
						snippetString += currentPixel.symbol;
					} else {
						// Now that the a new color is reached...
						// concat. "snippetString" to "frameString" 
						frameString += "\033[38;5;" + std::to_string(snippetColorPair.foreColorPair) + ";48;5;" + std::to_string(snippetColorPair.backColorPair) + "m" + snippetString + "\033[0m";
						// initialize for new Color
						snippetColorPair = currentPixel.color;
						snippetString = currentPixel.symbol;
					}
				}
			}
			snippetString += '\n';
		}
		// concat. remaining "snippetString"
		frameString += "\033[38;5;" + std::to_string(snippetColorPair.foreColorPair) + ";48;5;" + std::to_string(snippetColorPair.backColorPair) + "m" + snippetString + "\033[0m";	
		// flush final image to string 
		std::cout << frameString;
	}
	// assumes that the next frame is identical to the current one. Only, when any "Draw..." function would update "isChanged" to true
	isChanged = false; // Bugged, for some mystical reason, this new assignment only applies within the scope of this method
}

void Paper::DrawPoint(int x, int y, int fC, int bC, char sy) {
	if (x < width && x >= 0 && y < height && y >= 0) {
		Pixel &pixel = pixels[y + coorHeight][x + coorWidth];
		if (!(pixel.color.foreColorPair == fC &&
			  pixel.color.backColorPair == bC &&
			  pixel.symbol == sy)) {
			isChanged = true;
		}
		pixel.setPixel(fC, bC, sy);
	}
}

void Paper::DrawSymbol(int x, int y, int fC, char sy) {
		// DrawPoint and DrawSymbol could be merged with overloading parameters
		if (x < width + coorWidth && y < height + coorHeight) {
		Pixel &pixel = pixels[y + coorHeight][x + coorWidth];
		if (!(pixel.color.foreColorPair == fC &&
			  pixel.symbol == sy)) {
			isChanged = true;
		}
		pixel.color.foreColorPair = fC;
		pixel.symbol = sy;
	}
} 

void Paper::DrawRectangle(int x, int y, int w, int h, int fC, int bC, char sy) {
	for (int j = y; j < h+y; j++) {
		for (int i = x; i < w+x; i++) {
			DrawPoint(i, j, fC, bC, sy);
		}
	}
}

void Paper::DrawText(int x, int y, int fC, int bC, std::string text) {
	for (unsigned int i = 0; i < text.size(); i++) {
		DrawPoint(x + i, y, fC, bC, text[i]);
	}
} 

void Paper::DrawSprite(int x, int y, Sprite sprite) {
	// WIP
	for (int j = y; j < y; j++) {
		for (int i = x; i < x; x++) {
			
		}
	}
}