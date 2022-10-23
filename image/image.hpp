#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <vector>
#include <string>
#include <SDL2/SDL.h>

class Image{
	public:
	virtual void draw(SDL_Renderer* renderer, const SDL_Rect& destination, bool faceLeft=false, unsigned int deltaTime = 0) = 0;

	protected:
	void drawImage(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect& destination, bool faceLeft);
	SDL_Texture* load(SDL_Renderer* renderer, const std::string& path);
};


#endif //IMAGE_H_INCLUDED