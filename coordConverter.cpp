#include "coordConverter.hpp"

std::optional<SDL_Rect> worldToCam(const SDL_Rect& worldCoord, const SDL_Rect& camRectInWorld, const SDL_Rect& camRectInWindow) {
	int w = (worldCoord.w*camRectInWindow.w)/camRectInWorld.w;
	int h = (worldCoord.h*camRectInWindow.h)/camRectInWorld.h;
	float x = ((((float)worldCoord.x-(float)camRectInWorld.x-worldCoord.w/2.0)*camRectInWindow.w)/camRectInWorld.w);
	float y = ((((float)worldCoord.y-(float)camRectInWorld.y-worldCoord.h/2.0)*camRectInWindow.h)/camRectInWorld.h);

	return SDL_Rect{(int)x,
			(int)y,
			w,
			h
			};
}

