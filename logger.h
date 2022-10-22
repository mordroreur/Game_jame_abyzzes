#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <string_view>
#include <SDL2/SDL.h>

void log(const std::string_view& s);
void log(const SDL_Rect& r);

#endif //LOGGER_H_INCLUDED