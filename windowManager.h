#ifndef __SDL_MANAGER_GUARDIAN__
#define __SDL_MANAGER_GUARDIAN__

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <map>
#include <memory>
#include "nom_images.hpp"
#include "image/image.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

enum class etapeJeu {fin, menu};

class Ecran{
public :
  Ecran();
  ~Ecran();

  etapeJeu ej;

	void supprimerObjets();
  
  std::shared_ptr<Image> getImage(const NomImage& ni);
  SDL_Renderer* getRenderer();
  SDL_Rect getWindowRect();

  std::vector<std::shared_ptr<GameObject>> gameObjects;
  std::vector<std::shared_ptr<GameObject>> objetsASupprimer;
  std::shared_ptr<Player> player;
  int sizex, sizey;
private:

  
  SDL_Window *window;
  SDL_Renderer *renderer;
  
  bool init(int x, int y);
  void populateImages();
  std::map<NomImage, std::shared_ptr<Image>> images;

  void constructPlayer(std::shared_ptr<Enemy> chien);
};

long int getTime();

#endif
