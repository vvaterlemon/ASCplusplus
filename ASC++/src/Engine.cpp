// Engine.cpp

#include "../header/Engine.hpp"
#include "../header/Paper.hpp"

void Engine::init(int fps) {
	this->fps = fps;
}

void Engine::updatePaper(Paper paper) {
	//if (prevRender + count >  )
	paper.Render();
}