#ifndef IMAGE_FIXE_INCLUDED
#define IMAGE_FIXE_INCLUDED

#include "image.hpp"

class ImageFixe : public Image {
	SDL_Texture* texture;
public:
	ImageFixe(SDL_Renderer* renderer, const std::string& path);
	void draw(SDL_Renderer* renderer, const SDL_Rect& destination, unsigned int deltaTime = 0) override;
};

#endif //IMAGE_FIXE_INCLUDED