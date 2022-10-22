#include "coordConverter.hpp"

std::optional<SDL_Rect> worldToCam(const SDL_Rect& worldCoord, const SDL_Rect& camRectInWorld, const SDL_Rect& camRectInWindow) {
	SDL_Point p1 {worldCoord.x, worldCoord.y};
	SDL_Point p2 {worldCoord.x + worldCoord.w, worldCoord.y + worldCoord.h};
	SDL_Point p3 {camRectInWorld.x, camRectInWorld.y};

	/*if (!SDL_PointInRect(&p1, &camRectInWorld) && !SDL_PointInRect(&p2, &camRectInWorld) && !SDL_PointInRect(&p3, &worldCoord)) {
		return std::nullopt;
	}*/
	int w = (worldCoord.w*camRectInWindow.w)/camRectInWorld.w;
	int h = (worldCoord.h*camRectInWindow.h)/camRectInWorld.h;
	return SDL_Rect{(((worldCoord.x-camRectInWorld.x-worldCoord.w/2)*camRectInWindow.w)/camRectInWorld.w),
			(((worldCoord.y-camRectInWorld.y-worldCoord.h/2)*camRectInWindow.h)/camRectInWorld.h),
			w,
			h
			};
}

