#include "gestionInput.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <thread>
#include "geometrie/vecteur2.hxx"
#include "windowManager.h"
#include "tickManager.h"
#include "render.h"
#include <iostream>
#include <mutex>
#include "Input.hpp"
#include "geometrie/geometrie.hxx"




void startMainBoucle(std::shared_ptr<Ecran> ec){
  float dep[4] = {0, 0, 0, 0};
  bool powerOn = false;

  
	SDL_Event event;

	long int LastTick;
	long int timeForNewTick = 1000000 / 60;
	long int NowTime;

        long int TimeCount = getTime();
        int tickCount = 0;
        int frameCount = 0;

	

	
	NowTime = getTime();
	LastTick = getTime();
	

	std::thread drawThread (boucleAffichage, ec, &frameCount);
	
	while(ec->ej != etapeJeu::fin) {
		NowTime = getTime();

		/* Gestion des verif gameplay */
		int delatTime = NowTime - LastTick;
		if (delatTime > timeForNewTick) {

			

			std::scoped_lock l(mutexDo);


			
			ticks(ec, delatTime);

			for (auto object: ec->gameObjects)
			{
				if (object != ec->player)
				{
					if (object->collideWith(ec->player))
					{
					  //std::cout << "Gotcha" << std::endl;
					}
				}
			}
			
			LastTick += timeForNewTick;
			tickCount++;
		}else{
			/* Endors le cpu pour garder de la ressource */
			long SleepForCPU = 0;
			SleepForCPU = (long)(timeForNewTick - (delatTime)) / 300;
			SDL_Delay(SleepForCPU);
		}

		if (NowTime > TimeCount) {
			TimeCount += 1000000;
			//LastFpsCount = fpsCount;
			//LastTickCount = tickCount;
			//printf("%d images cette seconde et %d ticks\n", fpsCount, tickCount);
			//std::cout << "Frame : " << frameCount << " Ticks : " << tickCount << std::endl;
			frameCount = 0;
			tickCount = 0;
		}

                Input tempory;
                tempory.shoot = geometrie::Vecteur2<float>{0.0, 0.0};
                                
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
                          //std::cout << event.key.keysym.sym << std::endl;
                          switch (event.key.keysym.sym) {
                          case SDLK_SPACE: powerOn = true;break;
                          case SDLK_z: dep[0] = 1.0;break;//haut
                          case SDLK_d: dep[1] = 1.0;break;//droite
                          case SDLK_s: dep[2] = 1.0;break;//bas
                          case SDLK_q: dep[3] = 1.0;break;//gauche
                          default:break;
                          }
				break;
			case SDL_KEYUP:
                          switch (event.key.keysym.sym) {
                          case SDLK_SPACE: powerOn = false;break;
                          case SDLK_z: dep[0] = 0.0;break;//haut
                          case SDLK_d: dep[1] = 0.0;break;//droite
                          case SDLK_s: dep[2] = 0.0;break;//bas
                          case SDLK_q: dep[3] = 0.0;break;//gauche
			  case SDLK_ESCAPE: ec->ej=etapeJeu::fin;
                          default:break;
                          }
		//if(event.key.keysym.sym == SDLK_F11){
				break;
			case SDL_MOUSEWHEEL:
				// if (event.wheel.y > 0) {
		// } else if (event.wheel.y < 0) {
		// }
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
                                  int posMX, posMY;
                                  SDL_GetMouseState(&posMX, &posMY);
                                  tempory.shoot = geometrie::Vecteur2<float>{posMX - (ec->sizex/2.0), posMY - (ec->sizey/2.0)};
                                  tempory.shoot = geometrie::normalized(tempory.shoot);
				} else if (event.button.button == SDL_BUTTON_RIGHT) {
                                  //
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
		tempory.direction = geometrie::Vecteur2<float>{dep[1] - dep[3], dep[2] - dep[0]};
		tempory.power = powerOn;
		ec->player->setInput(tempory);
	}
	drawThread.join();
}



