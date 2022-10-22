#ifndef IMAGE_ANIMEE_INCLUDED
#define IMAGE_ANIMEE_INCLUDED

#include "image.hpp"

class ImageAnimee : public Image {
	public:
	ImageAnimee(SDL_Renderer* renderer, const std::vector<std::string>& paths, int timeByFrame);
	~ImageAnimee();

	void draw(SDL_Renderer* renderer, const SDL_Rect& destination, unsigned int deltaTime = 0) override;

	private:
	std::vector<SDL_Texture*> textures;
	size_t rangImgActuelle = 0;
	int timeByFrame;
	int timeSinceChanged = 0;
};

#endif //IMAGE_ANIMEE_INCLUDED
