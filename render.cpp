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

static std::mutex mutexDo;


void Affichage(std::shared_ptr<Ecran> ec, int deltaTime){
	
	auto* renderer = ec->getRenderer();
	SDL_RenderClear(renderer);
	ec->getImage(NomImage::Siren)->draw(renderer, {10, 10, 500, 500});

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

