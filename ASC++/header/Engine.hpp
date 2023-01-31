// Engine.hpp
// Declaration of the Engine struct type

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Paper.hpp"

/*
	WIP

	The engine is the object that would handle user input, fps, resolution (aka font size)
*/

// suggestion: Engine should a constructor/initiator
struct Engine {
	// properties
	int fps;	
	time_t prevRender;
	time_t tgap; // duration of time between each 
	// methods
	void init(int fps);
	void updatePaper(Paper paper);
};

#endif