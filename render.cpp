#include <thread>
#include "windowManager.h"
#include "tickManager.h"
#include "render.h"
#include "coordConverter.hpp"
#include <iostream>
#include <mutex>

static std::mutex mutexDo;
long int TimeCount;

SDL_Rect camRectFromPlayerRect(const SDL_Rect& playerRect, const float aspectRatio) {
	int w = 1200;
	int h = w*aspectRatio;
	return {playerRect.x-w/2,playerRect.y-h/2,w,h};
}

void Affichage(std::shared_ptr<Ecran> ec, int deltaTime){
	auto* renderer = ec->getRenderer();

	SDL_Rect playerRect {2000, 2000, 100,200};
	SDL_Rect windowRect = ec->getWindowRect();
	SDL_Rect camRect = camRectFromPlayerRect(playerRect, ((float)windowRect.h)/windowRect.w);
	SDL_Rect camRectInWindow {0,0,windowRect.w, windowRect.h};
	

	SDL_RenderClear(renderer);
	const auto rect = worldToCam(playerRect, camRect, camRectInWindow);
	
	if (rect.has_value()) {
		ec->getImage(NomImage::Siren)->draw(renderer, rect.value());
		//ec->getImage(NomImage::Siren)->draw(renderer, SDL_Rect{10,10, 100,100});
		
	}

	SDL_RenderPresent(renderer);
}

int tickCount;
int frameCount;

void boucleAffichage(std::shared_ptr<Ecran> ec){
	long int LastFrame;
	long int timeForNewFrame = 1000000 / 60;
	long int NowTime;

	frameCount = 0;
	NowTime = getTime();
	LastFrame = getTime();

	while(ec->ej != etapeJeu::fin){

		NowTime = getTime();

		/* Gestion des verif gameplay */
		int deltaTime = NowTime - LastFrame;
		if (deltaTime > timeForNewFrame) {

			std::scoped_lock l (mutexDo);
			Affichage(ec, deltaTime);
			
			LastFrame += timeForNewFrame;
			frameCount++;
		}else{
			/* Endors le cpu pour garder de la ressource */
			long SleepForCPU = 0;
			SleepForCPU = (long)(timeForNewFrame - (deltaTime)) / 300;
			SDL_Delay(SleepForCPU);
		}
	}
}


void startMainBoucle(std::shared_ptr<Ecran> ec){
	
	SDL_Event event;

	long int LastTick;
	long int timeForNewTick = 1000000 / 60;
	long int NowTime;

	
	tickCount = 0;
	TimeCount = getTime();
	
	NowTime = getTime();
	LastTick = getTime();
	

	std::thread drawThread (boucleAffichage, ec);
	
	while(ec->ej != etapeJeu::fin) {
		NowTime = getTime();

		/* Gestion des verif gameplay */
		int delatTime = NowTime - LastTick;
		if (delatTime > timeForNewTick) {
			std::scoped_lock l(mutexDo);
			ticks(ec, delatTime);
			
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
	drawThread.join();
}
