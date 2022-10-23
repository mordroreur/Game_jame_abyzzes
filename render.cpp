#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <thread>
#include "geometrie/vecteur2.hxx"
#include "image/image.hpp"
#include "windowManager.h"
#include "tickManager.h"
#include "render.h"
#include "coordConverter.hpp"
#include <iostream>
#include <mutex>
#include "Input.hpp"
#include "geometrie/geometrie.hxx"
#include "logger.h"


SDL_Rect camRectFromPlayerRect(const SDL_Rect& playerRect, const float aspectRatio) {
	int w = 2000;
	int h = w*aspectRatio;
	return {playerRect.x-w/2,playerRect.y-h/2,w,h};
}

void Affichage(std::shared_ptr<Ecran> ec, int deltaTime){
	auto* renderer = ec->getRenderer();

	SDL_Rect playerRect = ec->player->getRect();
	SDL_Rect windowRect = ec->getWindowRect();
	const auto aspectRatio = ((float)windowRect.h)/windowRect.w;
	SDL_Rect camRect = camRectFromPlayerRect(playerRect, aspectRatio);
	

	SDL_RenderClear(renderer);

	
	float scaleX = 2;
	float scaleY = aspectRatio*scaleX;
	
	int screenStartx = (camRect.x < 0)?-ec->sizex*scaleX+(-camRect.x%ec->sizex*scaleX):(-camRect.x%ec->sizex*scaleX);
	int screenStarty = (camRect.y < 0)?-ec->sizey*scaleY+(-camRect.y%ec->sizey*scaleY):(-camRect.y%ec->sizey*scaleY);

	//std::cout << camRect.x << "  " << camRect.y << "      " << camRect.w << "  " << screenStartx << std::endl;

	for(int i = -1; i < 2; i++){
	  for(int j = -1; j < 2; j++){
	    ec->getImage(NomImage::BackGround)->draw(renderer, SDL_Rect{(ec->sizex*scaleX*i)+screenStartx, (ec->sizey*scaleY*j)+screenStarty, ec->sizex*scaleX, ec->sizey*scaleY});
	  }
	}
	
	for (auto go : ec->gameObjects) {
		if (go) {
			const auto rect = worldToCam(go->getRect(), camRect, windowRect);
			
			if (rect.has_value()) {
				go->getImage()->draw(renderer, rect.value(), go->faceLeft(), deltaTime);
			}
		}
	}
	

	SDL_RenderPresent(renderer);
}


void boucleAffichage(std::shared_ptr<Ecran> ec, int *frameCount){
	long int LastFrame;
	long int timeForNewFrame = 1000000 / 120;
	long int NowTime;

	
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
			(*frameCount)++;
		}else{
			/* Endors le cpu pour garder de la ressource */
			long SleepForCPU = 0;
			SleepForCPU = (long)(timeForNewFrame - (deltaTime)) / 300;
			SDL_Delay(SleepForCPU);
		}
	}
}

