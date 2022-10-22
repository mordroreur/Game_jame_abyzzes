#ifndef __SDL_MANAGER_GUARDIAN__
#define __SDL_MANAGER_GUARDIAN__

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>

enum class etapeJeu {fin, menu};

class Ecran{
public :
  Ecran();
  ~Ecran();

  etapeJeu ej;
private:
  int sizex, sizey;
  
  SDL_Window *window;
  SDL_Renderer *renderer;
  
  bool init(int x, int y);
};

long int getTime();

#endif
