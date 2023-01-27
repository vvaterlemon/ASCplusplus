// Engine.hpp
// Declaration of the Engine struct type

#ifndef ENGINE_HPP
#define ENGINE_HPP

struct {
	// properties
	int fps;	
	time_t prevRender;
	time_t tgap; // duration of time between each frame
	// methods
	void init(int fps);
	void updatePaper(Paper paper);
} Engine;

#endif