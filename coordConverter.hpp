#ifndef COORD_CONVERTER_HPP_INCLUDED
#define COORD_CONVERTER_HPP_INCLUDED

#include <SDL2/SDL.h>
#include <optional>

std::optional<SDL_Rect> worldToCam(const SDL_Rect& worldCoord, const SDL_Rect& camRect, const SDL_Rect& camRectInWindow);

#endif //COORD_CONVERTER_HPP_INCLUDED
