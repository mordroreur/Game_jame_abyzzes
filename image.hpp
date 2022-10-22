#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <vector>
#include <string>
#include <SDL2/SDL.h>

class Image{
	public:
	Image(SDL_Renderer* renderer, const std::vector<std::string>& paths, int timeByFrame);
	void draw(SDL_Renderer* renderer, const SDL_Rect& destination, unsigned int deltaTime = 0);

	private:
	SDL_Texture* load(SDL_Renderer* renderer, const std::string& path);

	std::vector<SDL_Texture *> textures;
	size_t rangImgActuelle = 0;
	int timeByFrame;
	int timeSinceChanged = 0;
};


#endif //IMAGE_H_INCLUDED