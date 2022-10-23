#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <string_view>
#include <SDL2/SDL.h>
#include "geometrie/string.hxx"

void log(const std::string_view& s);
void log(const SDL_Rect& r);
template <typename T>
void log(const geometrie::Vecteur2<T>& v) {
	log(geometrie::toString(v));
}

#endif //LOGGER_H_INCLUDED