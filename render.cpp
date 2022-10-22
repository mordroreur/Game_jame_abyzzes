#include "windowManager.h"
#include "tickManager.h"
#include "render.h"


void Affichage(Ecran *ec){
  
}




void startMainBoucle(Ecran *ec){
  
  SDL_Event event;
  
  while(ec->ej != etapeJeu::fin){
    Affichage(ec);
    ticks(ec);


    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_KEYDOWN:
        //keyDown(event.key, screen);
        break;
      case SDL_KEYUP:
	//if(event.key.keysym.sym == SDLK_F11){
        break;
      case SDL_MOUSEWHEEL:
        // if (event.wheel.y > 0) {
	// } else if (event.wheel.y < 0) {
	// }
        break;
      case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) {
	  //LeftClick(screen);
        } else if (event.button.button == SDL_BUTTON_RIGHT) {
	  //RightClick(screen);
	}
        break;
      case SDL_QUIT:
        ec->ej = etapeJeu::fin;
        break;
      case SDL_WINDOWEVENT:
	/*if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){
	  if(repaint == 0){
	    screen->sizeX = event.window.data1;
	    screen->sizeY = event.window.data2;
	    writeParamFile(screen->sizeX, screen->sizeY, screen->isFullScreen);
	    }
	    }*/
	break;
	/*case SDL_JOYBUTTONDOWN:
	if(event.jbutton.button == 0){
	  inputsJoueurs[event.jbutton.which][INPUT_JUMP] = 1;
	}break;
      case SDL_JOYBUTTONUP:
	if(event.jbutton.button == 0){
	  inputsJoueurs[event.jbutton.which][INPUT_JUMP] = 0;
	  }break;*/
      default:
        break;
      }
    }
  }
}
