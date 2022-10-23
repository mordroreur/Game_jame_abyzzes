#include "imageFixe.hpp"


ImageFixe::ImageFixe(SDL_Renderer* renderer, const std::string& path) {
	texture = load(renderer, path);
}

void ImageFixe::draw(SDL_Renderer* renderer, const SDL_Rect& destination, bool faceLeft, unsigned int) {
	drawImage(renderer, texture, destination, faceLeft);
}
