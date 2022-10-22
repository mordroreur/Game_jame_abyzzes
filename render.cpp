#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <thread>
#include "geometrie/vecteur2.hxx"
#include "windowManager.h"
#include "tickManager.h"
#include "render.h"
#include "coordConverter.hpp"
#include <iostream>
#include <mutex>
#include "Input.hpp"
#include "geometrie/geometrie.hxx"

static std::mutex mutexDo;


SDL_Rect camRectFromPlayerRect(const SDL_Rect& playerRect, const float aspectRatio) {
	int w = 1200;
	int h = w*aspectRatio;
	return {playerRect.x-w/2,playerRect.y-h/2,w,h};
}

void Affichage(std::shared_ptr<Ecran> ec, int deltaTime){
	auto* renderer = ec->getRenderer();

	SDL_Rect playerRect = ec->player->getRect();
	SDL_Rect windowRect = ec->getWindowRect();
	SDL_Rect camRect = camRectFromPlayerRect(playerRect, ((float)windowRect.h)/windowRect.w);
	

	SDL_RenderClear(renderer);

	for (auto go : ec->gameObjects) {
		const auto rect = worldToCam(go->getRect(), camRect, windowRect);
		
		if (rect.has_value()) {
			go->getImage()->draw(renderer, rect.value());
		}
	}
	

	SDL_RenderPresent(renderer);
}


void boucleAffichage(std::shared_ptr<Ecran> ec, int *frameCount){
	long int LastFrame;
	long int timeForNewFrame = 1000000 / 60;
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

