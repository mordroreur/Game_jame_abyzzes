#include "image.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_Texture* Image::load(SDL_Renderer* renderer, const std::string& path) {
	return IMG_LoadTexture(renderer, path.c_str());
}

void Image::drawImage(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect& destination) {
	SDL_RenderCopy(renderer, texture, NULL, &destination);
}

