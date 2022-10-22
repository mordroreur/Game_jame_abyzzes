#include "imageAnimee.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

ImageAnimee::ImageAnimee(SDL_Renderer* renderer, const std::vector<std::string>& paths, int timeByFrame_)
	: timeByFrame{timeByFrame_}
 {
	for (const auto& p : paths)
	{
		textures.push_back(load(renderer, p));
	}
}

ImageAnimee::~ImageAnimee() {
	for (auto t : textures) {
		SDL_DestroyTexture(t);
	}
}


void ImageAnimee::draw(SDL_Renderer* renderer, const SDL_Rect& destination, unsigned int deltaTime) {
	timeSinceChanged += deltaTime;
	while (timeSinceChanged>=timeByFrame) {
		timeSinceChanged-= timeByFrame;
		rangImgActuelle++;
		rangImgActuelle %= textures.size();
	}

	SDL_RenderCopy(renderer, textures[rangImgActuelle], NULL, &destination);
}

