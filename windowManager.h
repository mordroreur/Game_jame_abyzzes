#ifndef __SDL_MANAGER_GUARDIAN__
#define __SDL_MANAGER_GUARDIAN__

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <map>
#include <memory>
#include "nom_images.hpp"
#include "image.hpp"

enum class etapeJeu {fin, menu};

class Ecran{
public :
  Ecran();
  ~Ecran();

  etapeJeu ej;
  std::shared_ptr<Image> getImage(const NomImage& ni);
  SDL_Renderer* getRenderer();
  SDL_Rect getWindowRect();

  int sizex, sizey;
private:

  
  SDL_Window *window;
  SDL_Renderer *renderer;
  
  bool init(int x, int y);
  void populateImages();
  std::map<NomImage, std::shared_ptr<Image>> images;
};

long int getTime();

#endif
