#include <SDL2/SDL.h>
#include <time.h>
#include "windowManager.h"
#include "image/imageFixe.hpp"
#include "image/imageAnimee.hpp"
#include "Enemy.hpp"
#include "Environment.hpp"

Ecran::Ecran():ej(etapeJeu::menu){
  if(!init(1080, 750)){
    exit(0);
  }
  //load images
  populateImages();

  auto chien = std::make_shared<Enemy>(geometrie::Vecteur2<float>{200.0,100.0}, getImage(NomImage::Ennemy1), 150,150);
  gameObjects.push_back(chien);
  constructPlayer(chien);

}

Ecran::~Ecran(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

bool Ecran::init(int x, int y){
  sizex = x;
  sizey = y;
  
  SDL_DisplayMode screen_dimension;

  /* Initialisation de la SDL  + gestion de l'échec possible */
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) != 0)
    exit(0);

  //récupère la taille de l'écran
  SDL_GetCurrentDisplayMode(0, &screen_dimension);
  //      printf("Taille de l'écran\n\tw : %d\n\th : %d\n", screen_dimension.w,
  //      screen_dimension.h);

  
  window = SDL_CreateWindow("This F****** window", SDL_WINDOWPOS_CENTERED,
				     SDL_WINDOWPOS_CENTERED, sizex,
				     sizey, SDL_WINDOW_RESIZABLE);

  
  /*
  SDL_Surface *thumbnail;
  thumbnail = IMG_Load("Res/thumbnail.png");
  SDL_SetWindowIcon(window, thumbnail);
  SDL_FreeSurface(thumbnail);*/

  if (window == NULL)
    exit(0);

  /* Création du renderer (le truc dans la windows) */
  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
  
  if (renderer == NULL)
    exit(0);


  // écrire (lettre chiffre) dans le render, grace à la bibliothèque TTF
  /*if (TTF_Init() == -1)
  {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
    }*/

  
  /* Taille de écran fournit par SDL */
  SDL_GetWindowSize(window, &sizex, &sizey);

  return true;
}

void Ecran::supprimerObjets() {
	for (auto o : objetsASupprimer) {
		auto last = std::remove(gameObjects.begin(), gameObjects.end(), o);
		gameObjects.erase(last, gameObjects.end());
	}
	objetsASupprimer.clear();
}

void Ecran::constructPlayer(std::shared_ptr<Enemy> chien) {
  player = std::make_shared<Player>([this, chien](std::shared_ptr<GameObject> go){
	gameObjects.push_back(go);
	chien->add_cible(std::weak_ptr{go});
  },
  [this](std::shared_ptr<GameObject> go){
		objetsASupprimer.push_back(go);
  },
	chien,
	getImage(NomImage::Algue),
  	geometrie::Vecteur2<float>{100.0,100.0}, getImage(NomImage::Siren), 100,200);
	gameObjects.push_back(player);
	chien->set_player(player);
}

SDL_Rect Ecran::getWindowRect() {
	int w,h;
	SDL_GetWindowSize(window, &w, &h);
	return {0,0,w,h};
}

std::shared_ptr<Image> Ecran::getImage(const NomImage& ni) {
	return images[ni];
}

SDL_Renderer* Ecran::getRenderer() {
	return renderer;
}

void Ecran::populateImages() {
	using namespace std::literals::string_literals;
	images.insert(std::pair{NomImage::Siren, std::make_shared<ImageFixe>(getRenderer(), "images/sirene.png"s)});
	//images.insert(std::pair{NomImage::Ennemy1, std::make_shared<ImageFixe>(getRenderer(), std::string{"images/enemy.png"})});
	images.insert(std::pair{NomImage::Ennemy1, std::make_shared<ImageAnimee>(getRenderer(), 
			std::vector{"images/enemyAva.png"s, "images/enemy.png"s, "images/enemyArr.png"s, "images/enemy.png"s}, 200000)});
	images.insert(std::pair{NomImage::BackGround, std::make_shared<ImageFixe>(getRenderer(), "images/background.png"s)});
	images.insert(std::pair{NomImage::Algue, std::make_shared<ImageFixe>(getRenderer(), "images/algue.png"s)});
		images.insert(std::pair{NomImage::Caillasse, std::make_shared<ImageFixe>(getRenderer(), std::string{"images/caillasse.png"})});

}


long int getTime(){
  struct timespec tms;
  if (clock_gettime(CLOCK_REALTIME,&tms)) {
        return -1;
    }
  return ((tms.tv_sec*1000000) + (tms.tv_nsec/1000));
}
