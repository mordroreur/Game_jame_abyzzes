#include "coordConverter.hpp"

std::optional<SDL_Rect> worldToCam(const SDL_Rect& worldCoord, const SDL_Rect& camRectInWorld, const SDL_Rect& camRectInWindow) {
	int w = (worldCoord.w*camRectInWindow.w)/camRectInWorld.w;
	int h = (worldCoord.h*camRectInWindow.h)/camRectInWorld.h;
	return SDL_Rect{(((worldCoord.x-camRectInWorld.x-worldCoord.w/2)*camRectInWindow.w)/camRectInWorld.w),
			(((worldCoord.y-camRectInWorld.y-worldCoord.h/2)*camRectInWindow.h)/camRectInWorld.h),
			w,
			h
			};
}

