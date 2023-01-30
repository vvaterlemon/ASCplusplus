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


Paper::Paper(int w, int h, int fC, int bC, char sy, bool showC = false) {
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
					 01234567 ... 14 -> i index of pixel
					0  000000 ... 1  -> coordinate
					1  012345 ... 2  -> cooridnate
					200              -> paper space
					301
					402
					503
					604

					when setting the pixels for vertical coordinates, case that j=2 & i=1 & coorHeight=2:
						digit = (1<=digitsize(2-2)-1)
								    digitsize(0)-1
								    1-1
								 1<0
								 false

					though still bugged, the alignment of the digit does not align in the same line as its place
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

void Paper::Render(bool isColorPaired) { 
	if (isChanged) {
		frameString = "\033[2;0H";
		snippetColorPair = pixels[0][0].color;
		snippetString = pixels[0][0].symbol;
		for (int j = 0; j < height + coorHeight; j++) {
			for (int i = 0; i < width + coorWidth; i++) {
				if (!(i+j == 0)) {
					Pixel currentPixel = pixels[j][i];
					if (snippetColorPair == currentPixel.color) {
						snippetString += currentPixel.symbol;
					} else {
						frameString += isColorPaired ? "\033[38;5;" + std::to_string(snippetColorPair.foreColorPair) + ";48;5;" + std::to_string(snippetColorPair.backColorPair) + "m" + snippetString + "\033[0m" : snippetString;
						snippetColorPair = currentPixel.color;
						snippetString = currentPixel.symbol;
						std::cout << frameString;
					}
				}
			}
			snippetString += '\n';
		}
		frameString += isColorPaired ? "\033[38;5;" + std::to_string(snippetColorPair.foreColorPair) + ";48;5;" + std::to_string(snippetColorPair.backColorPair) + "m" + snippetString + "\033[0m" : snippetString;	
		std::cout << frameString;
		isChanged = false;
	}
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