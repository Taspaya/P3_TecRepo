#pragma once
#include <iostream>
#include "Celda.h"
#include "Scene.h"
#include "Character.h"
#include "HUD.h"
#include "Mapa.h"
#include <time.h>
#include <fstream>
#include <sstream>

#include "../../dep/inc/xml/rapidxml.hpp"
#include "../../dep/inc/xml/rapidxml_utils.hpp"
#include "../../dep/inc/xml/rapidxml_iterators.hpp"
#include "../../dep/inc/xml/rapidxml_print.hpp"


class Play : public Scene
{
public:
	
	//reading xml
	rapidxml::xml_document<> doc;
	std::stringstream buffer;


	Mapa MapGame;
	SDL_Event event;
	Character P1;		//Objeto de tipo character PLAYER 1
	Character P2;		//Objeto de tipo character PLAYER 2
	HUD Hud;			//Objeto de tipo HUD hud
public:

	void readConfig(int);
	void HandleEvents() override;	//permite sobreescribir las virtual 
	void Update() override;			//permite sobreescribir las virtual 
	void Draw() override;			//permite sobreescribir las virtual 
	
	Play(int);
	~Play();
};

