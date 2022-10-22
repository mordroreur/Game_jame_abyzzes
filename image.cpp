#include "image.hpp"
#include <SDL2/SDL_image.h>

Image::Image(SDL_Renderer* renderer, const std::vector<std::string>& paths, int timeByFrame_)
	: timeByFrame{timeByFrame_}
 {
	for (const auto& p : paths)
	{
		textures.push_back(load(renderer, p));
	}
}

SDL_Texture* Image::load(SDL_Renderer* renderer, const std::string& path) {
	return IMG_LoadTexture(renderer, path.c_str());
}

void Image::draw(SDL_Renderer* renderer, const SDL_Rect& destination, unsigned int deltaTime) {
	timeSinceChanged += deltaTime;
	while (timeSinceChanged>=timeByFrame) {
		timeSinceChanged-= timeByFrame;
		rangImgActuelle++;
		rangImgActuelle %= textures.size();
	}

	SDL_RenderCopy(renderer, textures[rangImgActuelle], NULL, &destination);
}

