#ifndef __SDL_MANAGER_GUARDIAN__
#define __SDL_MANAGER_GUARDIAN__

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>

enum class etapeJeu {menu};

class Image{
 public:
  std::vector<SDL_Texture *> text;
  int nbImageX, nbImageY, offsetX, offsetY, totalImageNb;
};

class Ecran{
public :
  Ecran();
  ~Ecran();
private:
  int sizex, sizey;
  
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::vector<Image> imlist;
  etapeJeu ej;
  
  bool init(int x, int y);
  Image loadImage(const std::string &path);
  void DrawImage(Image *im, float x, float y, float sizeX, float sizeY, char center, int etatPremier, float TimebeforeNext, int flip, int angle);
};

long int getTime();

#endif
