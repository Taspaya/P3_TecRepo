#pragma once
#include "Celda.h"
#include "Scene.h"
#include "Character.h"
#include "HUD.h"
#include "Mapa.h"
#include <time.h>



//#include <thread>
#include <iostream>

class Play : public Scene
{
public:
	
	Mapa MapGame;
	SDL_Event event;
	Character P1;		//Objeto de tipo character PLAYER 1
	Character P2;		//Objeto de tipo character PLAYER 2
	HUD Hud;			//Objeto de tipo HUD hud
public:
	void HandleEvents() override;	//permite sobreescribir las virtual 
	void Update() override;			//permite sobreescribir las virtual 
	void Draw() override;			//permite sobreescribir las virtual 
	
	Play(int);
	~Play();
};

