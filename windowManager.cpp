#include <SDL2/SDL.h>
#include <time.h>
#include "windowManager.h"

Ecran::Ecran():ej(etapeJeu::menu){
  if(!init(1080, 750)){
    exit(0);
  }
  //load images
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

Image Ecran::loadImage(const std::string &path){
  return Image();
}

void Ecran::DrawImage(Image *im, float x, float y, float sizeX, float sizeY, char center, int etatPremier, float TimebeforeNext, int flip, int angle){
  
}

long int getTime(){
  struct timespec tms;
  if (clock_gettime(CLOCK_REALTIME,&tms)) {
        return -1;
    }
  return ((tms.tv_sec*1000000) + (tms.tv_nsec/1000));
}
